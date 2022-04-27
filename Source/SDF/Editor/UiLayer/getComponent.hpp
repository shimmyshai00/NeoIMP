#ifndef SDF_EDITOR_UILAYER_GETCOMPONENT_HPP
#define SDF_EDITOR_UILAYER_GETCOMPONENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.hpp
// PURPOSE: Defines the DI component for the UI layer.

#include <fruit/fruit.h>

#include "IUiEntryPoint.hpp"

namespace SDF::Editor::UiLayer {
    typedef fruit::Component<IUiEntryPoint> Component;

    Component getComponent();
}  // namespace SDF::Editor::UiLayer

#endif  // SDF_EDITOR_UILAYER_GETCOMPONENT_HPP