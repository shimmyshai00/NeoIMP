// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ResolutionConverter.cpp
// PURPOSE: Implements the ResolutionConverter class.

#include "ResolutionConverter.hpp"

#include "../../Exceptions.hpp"
#include "conversion_factors.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    float ResolutionConverter::convert(float a_quantity, int a_fromUnit, int a_toUnit, AConversionContext &a_ctx) {
        using namespace UiLayer::AbstractModel::Defs::Metrics;

        if ((a_fromUnit < 0) || (a_fromUnit >= RESOLUTION_UNIT_MAX)) {
            throw UnknownResolutionUnitException(a_fromUnit);
        }

        if ((a_toUnit < 0) || (a_toUnit >= RESOLUTION_UNIT_MAX)) {
            throw UnknownResolutionUnitException(a_toUnit);
        }

        // This conversion is much simpler because there is no context-variable option.
        double conversionFactor = g_resolutionUnitDefs[a_fromUnit] / g_resolutionUnitDefs[a_toUnit];

        return a_quantity * conversionFactor;
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics