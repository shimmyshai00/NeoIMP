#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_HSMMANAGEDVIEW_TPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_HSMMANAGEDVIEW_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmManagedView.tpp
// PURPOSE: Implements the HsmManagedView base template.

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    template <class QObjectT, class T, class ... InitArgs>
    HsmManagedView<QObjectT, T, InitArgs...>::HsmManagedView(InitArgs... as_args, QWidget *a_parent)
        : MvcAdapter::QtView<QObjectT, T>(a_parent)
    {
    }

    template <class QObjectT, class T, class ... InitArgs>
    template <class QSignalObjectT, class R, class... Args>
    QMetaObject::Connection HsmManagedView<QObjectT, T, InitArgs...>::connectToHsm(QSignalObjectT *a_qObject,
                                                                      R (QSignalObjectT::*a_signal)(Args...)) {
        return QObjectT::connect(a_qObject, a_signal, [&](Args... b_args) {
            HsmQtSignalEventArgs<Args...> signalEvent;
            signalEvent.qObject = a_qObject;
            signalEvent.funcDescriptor = SIGNAL(a_signal);
            signalEvent.args = std::make_tuple(b_args...);

            this->stimulate(signalEvent);
        });
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_HSMMANAGEDVIEW_TPP