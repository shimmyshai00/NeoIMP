// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    UnitConversion.hpp
// PURPOSE: Implements the UnitConversion class.

#include "UnitConversion.hpp"

namespace SDF::Editor::ModelLayer::Services {
    UnitConversion::UnitConversion() {}

    Common::Handle UnitConversion::createUnitConversionContext(float a_resolutionPpi) { return Common::HANDLE_INVALID; }

    void UnitConversion::deleteUnitConversionContext(Common::Handle a_ctx) {}

    void UnitConversion::setConversionResolution(Common::Handle a_ctx, float a_resolutionPpi) {}

    float UnitConversion::convert(float a_quant,
                                  UiLayer::AbstractModel::Defs::Metrics::LengthUnit a_from,
                                  UiLayer::AbstractModel::Defs::Metrics::LengthUnit a_to,
                                  Common::Handle a_ctx) {
        return 0.0f;
    }

    float UnitConversion::convert(float a_quant,
                                  UiLayer::AbstractModel::Defs::Metrics::ResolutionUnit a_from,
                                  UiLayer::AbstractModel::Defs::Metrics::ResolutionUnit a_to) {
        return 0.0f;
    }
}  // namespace SDF::Editor::ModelLayer::Services