#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_ICONVERTER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_ICONVERTER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IConverter.hpp
// PURPOSE: Defines the IConverter interface.

#include "AConversionContext.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    // CLASS:   IConverter
    // PURPOSE: Defines the model-level interface for unit converters.
    class IConverter {
       public:
        virtual ~IConverter() = default;

        // FUNCTION: convert
        // PURPOSE:  Perform a unit conversion.
        // NOTES:    None.
        virtual float convert(float a_quantity, int a_fromUnit, int a_toUnit, AConversionContext &a_ctx) = 0;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_ICONVERTER_HPP