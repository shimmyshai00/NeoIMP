// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.cpp
// PURPOSE: Implements the DI component for the UI layer.

#include "getComponent.hpp"

#include "Gui/getComponent.hpp"

namespace SDF::Editor::UiLayer {
    Component getComponent() { return fruit::createComponent().install(Gui::getComponent); }
}  // namespace SDF::Editor::UiLayer