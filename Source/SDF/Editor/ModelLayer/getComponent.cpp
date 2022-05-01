// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.cpp
// PURPOSE: Implements the DI component for the model layer.

#include "getComponent.hpp"

#include "Services/CreateImage.hpp"
#include "Services/UnitConversion.hpp"

namespace SDF::Editor::ModelLayer {
    Component getComponent() {
        return fruit::createComponent()
            .bind<UiLayer::AbstractModel::Services::IUnitConversionContextManipulator, Services::UnitConversion>()
            .bind<UiLayer::AbstractModel::Services::IConvertLength, Services::UnitConversion>()
            .bind<UiLayer::AbstractModel::Services::IConvertResolution, Services::UnitConversion>()
            .bind<UiLayer::AbstractModel::Services::ICreateImage, Services::CreateImage>();
    }
}  // namespace SDF::Editor::ModelLayer