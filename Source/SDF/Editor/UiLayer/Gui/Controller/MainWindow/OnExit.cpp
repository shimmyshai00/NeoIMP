// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    OnExit.cpp
// PURPOSE: Implements the OnExit class.

#include "OnExit.hpp"

namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow {
    OnExit::OnExit(IUiTerminator *a_uiTerminator) : m_uiTerminator(a_uiTerminator) {}

    void OnExit::onTriggered() {
        if (m_uiTerminator != nullptr) {
            m_uiTerminator->terminateUi();
        }
    }
}  // namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow