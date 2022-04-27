// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.cpp
// PURPOSE: Implements the DI component for the GUI.

#include "getComponent.hpp"

#include "EntryPoint.hpp"
#include "Qt/getComponent.hpp"

namespace SDF::Editor::UiLayer::Gui {
    Component getComponent() {
        return fruit::createComponent().bind<IUiEntryPoint, EntryPoint>().install(Qt::getComponent);
    }
}  // namespace SDF::Editor::UiLayer::Gui