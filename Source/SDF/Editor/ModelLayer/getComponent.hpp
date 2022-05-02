#ifndef SDF_EDITOR_MODELLAYER_GETCOMPONENT_HPP
#define SDF_EDITOR_MODELLAYER_GETCOMPONENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.hpp
// PURPOSE: Defines the DI component for the model layer.

#include <fruit/fruit.h>

#include "../UiLayer/AbstractModel/Services/IGetImageLimits.hpp"
#include "../UiLayer/AbstractModel/Services/IConversionContextManipulator.hpp"
#include "../UiLayer/AbstractModel/Services/IConvertLength.hpp"
#include "../UiLayer/AbstractModel/Services/IConvertResolution.hpp"
#include "../UiLayer/AbstractModel/Services/ICreateImage.hpp"

namespace SDF::Editor::ModelLayer {
    typedef fruit::Component<UiLayer::AbstractModel::Services::IGetImageLimits,
                             UiLayer::AbstractModel::Services::IUnitConversionContextManipulator,
                             UiLayer::AbstractModel::Services::IConvertLength,
                             UiLayer::AbstractModel::Services::IConvertResolution,
                             UiLayer::AbstractModel::Services::ICreateImage>
        Component;

    Component getComponent();
}  // namespace SDF::Editor::ModelLayer

#endif  // SDF_EDITOR_MODELLAYER_GETCOMPONENT_HPP