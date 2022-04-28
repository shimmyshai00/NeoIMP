#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICONVERTLENGTH_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICONVERTLENGTH_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IConvertLength.hpp
// PURPOSE: Defines the IConvertLength interface.

#include "../../../../Common/Handle.hpp"
#include "../Defs/Metrics/LengthUnit.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   IConvertLength
    // PURPOSE: Defines a service interface for doing length unit conversions.
    class IConvertLength {
       public:
        virtual ~IConvertLength() = default;

        // FUNCTION: convert
        // PURPOSE:  Converts a length from one unit of measurement to another.
        // NOTES:    Because one length unit is pixels, whose relationship to the others is variable, a conversion
        //           context must be supplied. If this is HANDLE_INVALID, a default conversion of 72 PPI is assumed.
        //           This context is usually an image document (so would have the same handle as it), but custom 
        //           contexts can also be created.
        virtual float convert(float a_quant,
                              Defs::Metrics::LengthUnit a_from,
                              Defs::Metrics::LengthUnit a_to,
                              Common::Handle a_ctx) = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICONVERTLENGTH_HPP