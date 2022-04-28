#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_MAINWINDOW_ONEXIT_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_MAINWINDOW_ONEXIT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    OnExit.hpp
// PURPOSE: Defines the OnExit class.

#include "../../../../../Common/Mvc/IController.hpp"
#include "../IUiTerminator.hpp"

namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow {
    // CLASS:   OnExit
    // PURPOSE: Handles the "Exit" menu command.
    class OnExit : public Common::Mvc::IController<> {
       public:
        OnExit(IUiTerminator *a_uiTerminator);

        void onTriggered();

       private:
        IUiTerminator *m_uiTerminator;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow

#endif  // SDF_EDITOR_UILAYER_GUI_CONTROLLER_MAINWINDOW_ONEXIT_HPP