#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_HSMMANAGEDVIEW_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_HSMMANAGEDVIEW_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmManagedView.hpp
// PURPOSE: Defines the HsmManagedView base template.

#include <QMetaObject>
#include <QObject>
#include <memory>
#include <tuple>

#include "../../../../../Common/Hsm/Hsm.hpp"
#include "../MvcAdapter/QtView.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    struct HsmQtSignalEvent {
        QObject *qObject;
        const char *funcDescriptor;

        virtual ~HsmQtSignalEvent() = default;
    };

    template <class... Args>
    struct HsmQtSignalEventArgs : public HsmQtSignalEvent {
        std::tuple<Args...> args;
    };

    // CLASS:   HsmManagedView
    // PURPOSE: Defines a base type for views that manage their internal state using a hierarchical state machine (HSM)
    //          pattern.
    // NOTES:   The constructor of the derived view should call beginHsm() appropriately once done.
    template <class QObjectT, class T, class ... InitArgs>
    class HsmManagedView : public MvcAdapter::QtView<QObjectT, T>, public Common::Hsm::Hsm<HsmQtSignalEvent, T> {
       public:
        HsmManagedView(InitArgs... as_args, QWidget *a_parent = nullptr);
        virtual ~HsmManagedView() = default;
       protected:
        // FUNCTION: connectToHsm
        // PURPOSE:  Connects a signal from another object to an HSM event.
        // NOTES:    We cannot use a Qt slot for this instead because of the genericity.
        template <class QSignalObjectT, class R, class... Args>
        QMetaObject::Connection connectToHsm(QSignalObjectT *a_qObject, R (QSignalObjectT::*a_signal)(Args...));
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#include "HsmManagedView.tpp"

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_HSMMANAGEDVIEW_HPP