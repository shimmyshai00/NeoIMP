#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICONVERTRESOLUTION_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICONVERTRESOLUTION_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IConvertResolution.hpp
// PURPOSE: Defines the IConvertResolution interface.

#include "../../../../Common/Handle.hpp"
#include "../Defs/Metrics/ResolutionUnit.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   IConvertResolution
    // PURPOSE: Defines a service interface for doing resolution unit conversions.
    class IConvertResolution {
       public:
        virtual ~IConvertResolution() = default;

        // FUNCTION: convert
        // PURPOSE:  Converts a resolution from one unit of measurement to another.
        // NOTES:    These units do not require conversion contexts.
        virtual float convert(float a_quant,
                              Defs::Metrics::ResolutionUnit a_from,
                              Defs::Metrics::ResolutionUnit a_to) = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICONVERTRESOLUTION_HPP