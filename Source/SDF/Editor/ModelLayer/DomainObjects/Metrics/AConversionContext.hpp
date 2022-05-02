#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_ACONVERSIONCONTEXT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_ACONVERSIONCONTEXT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    AConversionContext.hpp
// PURPOSE: Defines the AConversionContext base class.

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    // CLASS:   AConversionContext
    // PURPOSE: Defines an abstract base for conversion contexts.
    class AConversionContext {
       public:
        virtual ~AConversionContext() = default;

        // FUNCTION: getResolutionPpi
        // PURPOSE:  Gets the context pixels-per-inch (PPI) resolution.
        // NOTES:    None.
        virtual float getResolutionPpi() const = 0;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_ACONVERSIONCONTEXT_HPP