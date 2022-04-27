#ifndef SDF_EDITOR_UILAYER_GUI_QT_GETCOMPONENT_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_GETCOMPONENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.hpp
// PURPOSE: Defines the DI component for the Qt-based GUI.

#include <fruit/fruit.h>

#include "../../../../Common/Mvc/IViewProducer.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt {
    typedef fruit::Component<Common::Mvc::IViewProducer<>> Component;

    Component getComponent();
}  // namespace SDF::Editor::UiLayer::Gui::Qt

#endif  // SDF_EDITOR_UILAYER_GUI_QT_GETCOMPONENT_HPP