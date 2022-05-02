// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    LengthConverter.cpp
// PURPOSE: Implements the LengthConverter class.

#include "LengthConverter.hpp"

#include "../../Exceptions.hpp"
#include "conversion_factors.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    float LengthConverter::convert(float a_quantity, int a_fromUnit, int a_toUnit, AConversionContext &a_ctx) {
        using namespace UiLayer::AbstractModel::Defs::Metrics;

        if ((a_fromUnit < 0) || (a_fromUnit >= LENGTH_UNIT_MAX)) {
            throw UnknownLengthUnitException(a_fromUnit);
        }

        if ((a_toUnit < 0) || (a_toUnit >= LENGTH_UNIT_MAX)) {
            throw UnknownLengthUnitException(a_toUnit);
        }

        // Pixels need separate handling due to being resolution-dependent. To avoid needing to deal with 4 separate
        // conversion cases (for whether or not pixels appear as source or destination unit), we should convert to
        // inches as a middle ground, expanding to double precision to maximize accuracy.
        double toInches = 0.0;
        if (a_fromUnit == LENGTH_UNIT_PIXEL) {
            toInches = 1.0f / a_ctx.getResolutionPpi();
        } else {
            toInches = g_lengthUnitDefs[a_fromUnit] / g_lengthUnitDefs[LENGTH_UNIT_INCH];
        }

        double intermedQuantity = a_quantity * toInches;
        double toDest = 0.0;

        if (a_toUnit == LENGTH_UNIT_PIXEL) {
            toDest = a_ctx.getResolutionPpi();
        } else {
            toDest = g_lengthUnitDefs[LENGTH_UNIT_INCH] / g_lengthUnitDefs[a_toUnit];
        }

        return intermedQuantity * toDest;
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics