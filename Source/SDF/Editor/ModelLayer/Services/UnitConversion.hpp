#ifndef SDF_EDITOR_MODELLAYER_SERVICES_UNITCONVERSION_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_UNITCONVERSION_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    UnitConversion.cpp
// PURPOSE: Defines the UnitConversion class.

#include <fruit/fruit.h>

#include "../../../Common/Handle.hpp"
#include "../../UiLayer/AbstractModel/Services/IConversionContextManipulator.hpp"
#include "../../UiLayer/AbstractModel/Services/IConvertLength.hpp"
#include "../../UiLayer/AbstractModel/Services/IConvertResolution.hpp"

namespace SDF::Editor::ModelLayer::Services {
    // CLASS:   UnitConversion
    // PURPOSE: Defines an MVC service for doing measurement unit conversions.
    class UnitConversion : public UiLayer::AbstractModel::Services::IUnitConversionContextManipulator,
                           public UiLayer::AbstractModel::Services::IConvertLength,
                           public UiLayer::AbstractModel::Services::IConvertResolution {
       public:
        INJECT(UnitConversion());

        Common::Handle createUnitConversionContext(float a_resolutionPpi);
        void deleteUnitConversionContext(Common::Handle a_ctx);
        void setConversionResolution(Common::Handle a_ctx, float a_resolutionPpi);

        float convert(float a_quant,
                      UiLayer::AbstractModel::Defs::Metrics::LengthUnit a_from,
                      UiLayer::AbstractModel::Defs::Metrics::LengthUnit a_to,
                      Common::Handle a_ctx);

        float convert(float a_quant,
                      UiLayer::AbstractModel::Defs::Metrics::ResolutionUnit a_from,
                      UiLayer::AbstractModel::Defs::Metrics::ResolutionUnit a_to);
    };
}  // namespace SDF::Editor::ModelLayer::Services

#endif  // SDF_EDITOR_MODELLAYER_SERVICES_UNITCONVERSION_HPP