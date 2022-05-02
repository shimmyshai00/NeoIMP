#ifndef SDF_EDITOR_DATALAYER_GETCOMPONENT_HPP
#define SDF_EDITOR_DATALAYER_GETCOMPONENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.hpp
// PURPOSE: Defines the DI component for the data layer.

#include <fruit/fruit.h>

#include "../ModelLayer/AbstractData/IConversionContextRepository.hpp"

namespace SDF::Editor::DataLayer {
    typedef fruit::Component<ModelLayer::AbstractData::IConversionContextRepository> Component;

    Component getComponent();
}  // namespace SDF::Editor::DataLayer

#endif  // SDF_EDITOR_DATALAYER_GETCOMPONENT_HPP