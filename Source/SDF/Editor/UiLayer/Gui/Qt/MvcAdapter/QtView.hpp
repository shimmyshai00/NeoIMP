#ifndef SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_QTVIEW_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_QTVIEW_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    QtView.hpp
// PURPOSE: Defines the QtView template.

#include <QMetaObject>
#include <QWidget>
#include <memory>
#include <vector>

#include "../../../../../Common/Connection.hpp"
#include "../../../../../Common/IDisconnector.hpp"
#include "../../../../../Common/Mvc/IController.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter {
    // CLASS:   QtView
    // PURPOSE: Defines an adapter for Qt QWidgets into the widget system-agnostic MVC system. Note that T should CRTP-
    //          inherit this class.
    template <class QWidgetT, class T>
    class QtView : public QWidgetT, private Common::IDisconnector {
       public:
        QtView(QWidget *a_parent = nullptr);

        // FUNCTION: attachController
        // PURPOSE:  Tries to attach an MVC controller onto a Qt signal on the base widget. This class simply tries to
        //           translate and then pass the arguments coming off the signal in-order to the controller. If the
        //           controller does not have enough arguments, it discards some.
        // NOTES:    (TBA) A variant to use a general converter lambda to do the calling for trickier cases.
        template <class FuncPtr, class... ControllerArgs>
        Common::Connection attachController(FuncPtr a_signal,
                                            std::unique_ptr<Common::Mvc::IController<ControllerArgs...>> a_controller);

       private:
        // Homogenizer for the controllers.
        std::vector<std::unique_ptr<Common::IConnectable>> m_ownedControllers;
        std::vector<QMetaObject::Connection> m_qtConns;

        void disconnectConnectable(Common::IConnectable *pa_connectable);
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter

#include "QtView.tpp"

#endif  // SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_QTVIEW_HPP