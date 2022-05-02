#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_RESOLUTIONCONVERTER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_RESOLUTIONCONVERTER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ResolutionConverter.hpp
// PURPOSE: Defines the ResolutionConverter class.

#include "IConverter.hpp"
#include "AConversionContext.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    // CLASS:   ResolutionConverter
    // PURPOSE: Perform resolution unit conversions.
    class ResolutionConverter : public IConverter {
       public:
        float convert(float a_quantity, int a_fromUnit, int a_toUnit, AConversionContext &a_ctx);
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_RESOLUTIONCONVERTER_HPP