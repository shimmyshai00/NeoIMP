#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_CONVERSION_FACTORS_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_CONVERSION_FACTORS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    conversion_factors.hpp
// PURPOSE: Defines the unit conversion factors.

#include "../../../UiLayer/AbstractModel/Defs/Metrics/LengthUnit.hpp"
#include "../../../UiLayer/AbstractModel/Defs/Metrics/ResolutionUnit.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    // note: this must mirror the order of the enum in UiLayer::AbstractModel::Defs::LengthUnit.
    // note 2: The base units are millimeters (mm).
    static const float g_lengthUnitDefs[UiLayer::AbstractModel::Defs::Metrics::LENGTH_UNIT_MAX] = {
        1.0f / 72.0f, // default: 72 PPI
        25.4f / 72.0f,
        1.0f,
        25.4f / 6.0f,
        10.0f,
        25.4f
    };

    // Base unit: PPI
    static const float g_resolutionUnitDefs[UiLayer::AbstractModel::Defs::Metrics::RESOLUTION_UNIT_MAX] = {
        1.0f,
        2.54f,
        25.4f
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_CONVERSION_FACTORS_HPP