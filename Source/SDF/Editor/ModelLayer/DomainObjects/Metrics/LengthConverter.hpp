#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_LENGTHCONVERTER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_LENGTHCONVERTER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    LengthConverter.hpp
// PURPOSE: Defines the LengthConverter class.

#include "AConversionContext.hpp"
#include "IConverter.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    // CLASS:   LengthConverter
    // PURPOSE: Perform length unit conversions.
    class LengthConverter : public IConverter {
       public:
        float convert(float a_quantity, int a_fromUnit, int a_toUnit, AConversionContext &a_ctx);
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_LENGTHCONVERTER_HPP