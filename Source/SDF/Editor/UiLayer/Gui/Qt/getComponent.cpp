// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.cpp
// PURPOSE: Implements the DI component for the Qt-based GUI.

#include "getComponent.hpp"

#include "ViewProducers/MainWindowProducer.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt {
    Component getComponent() {
        return fruit::createComponent().bind<Common::Mvc::IViewProducer<>, ViewProducers::MainWindowProducer>();
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt