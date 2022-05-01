// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    OnNew.cpp
// PURPOSE: Implements the OnNew class.

#include "OnNew.hpp"

namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow {
    OnNew::OnNew(Common::Mvc::IViewProducer<> *a_newDocumentDialogProducer)
        : m_newDocumentDialogProducer(a_newDocumentDialogProducer) {}

    void OnNew::onTriggered() { m_newDocumentDialogProducer->requestView(); }
}  // namespace SDF::Editor::UiLayer::Gui::Controller::MainWindow