#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_CUSTOMCONVERSIONCONTEXT_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_CUSTOMCONVERSIONCONTEXT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    CustomConversionContext.hpp
// PURPOSE: Defines the CustomConversionContext class.

#include "AConversionContext.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    // CLASS:   CustomConversionContext
    // PURPOSE: Provides a custom unit conversion context independent of an image document.
    class CustomConversionContext : public AConversionContext {
       public:
        // FUNCTION: CustomConversionContext
        // PURPOSE:  Constructs a new conversion context.
        // NOTES:    None.
        CustomConversionContext(float a_resolutionPpi);

        // FUNCTION: getResolutionPpi
        // PURPOSE:  Gets the context pixels-per-inch (PPI) resolution.
        // NOTES:    None.
        float getResolutionPpi() const;
       private:
        float m_resolutionPpi;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_METRICS_CUSTOMCONVERSIONCONTEXT_HPP