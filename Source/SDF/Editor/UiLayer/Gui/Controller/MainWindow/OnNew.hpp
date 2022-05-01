#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_MAINWINDOW_ONNEW_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_MAINWINDOW_ONNEW_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    OnNew.hpp
// PURPOSE: Defines the OnNew class.

#include "../../../../../Common/Mvc/IController.hpp"
#include "../../../../../Common/Mvc/IViewProducer.hpp"

namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow {
    // CLASS:   OnNew
    // PURPOSE: Handles the "New" menu command.
    class OnNew : public Common::Mvc::IController<> {
       public:
        OnNew(Common::Mvc::IViewProducer<> *a_newDocumentDialogProducer);

        void onTriggered();

       private:
        Common::Mvc::IViewProducer<> *m_newDocumentDialogProducer;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow

#endif  // SDF_EDITOR_UILAYER_GUI_CONTROLLER_MAINWINDOW_ONNEW_HPP