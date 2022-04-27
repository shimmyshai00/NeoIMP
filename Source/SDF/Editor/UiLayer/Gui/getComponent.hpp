#ifndef SDF_EDITOR_UILAYER_GUI_GETCOMPONENT_HPP
#define SDF_EDITOR_UILAYER_GUI_GETCOMPONENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.hpp
// PURPOSE: Defines the DI component for the GUI.

#include <fruit/fruit.h>

#include "../IUiEntryPoint.hpp"

namespace SDF::Editor::UiLayer::Gui {
    typedef fruit::Component<IUiEntryPoint> Component;

    Component getComponent();
}  // namespace SDF::Editor::UiLayer::Gui

#endif  // SDF_EDITOR_UILAYER_GUI_GETCOMPONENT_HPP