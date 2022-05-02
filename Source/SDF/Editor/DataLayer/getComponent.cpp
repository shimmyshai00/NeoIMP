// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.cpp
// PURPOSE: Implements the DI component for the data layer.

#include "getComponent.hpp"

#include "../../Common/Data/getComponent.hpp"
#include "Repositories/ConversionContext.hpp"

namespace SDF::Editor::DataLayer {
    Component getComponent() {
        using namespace ModelLayer::AbstractData;
        
        return fruit::createComponent()
            .bind<IConversionContextRepository, Repositories::ConversionContext>()
            .install(Common::Data::getComponent);
    }
}  // namespace SDF::Editor::DataLayer