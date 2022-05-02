#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETIMAGELIMITS_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETIMAGELIMITS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IGetImageLimits.hpp
// PURPOSE: Defines the IGetImageLimits interface.

#include <cstddef>

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   IGetImageLimits
    // PURPOSE: Defines a service interface for getting the engine limits on image size.
    class IGetImageLimits {
       public:
        virtual ~IGetImageLimits() = default;

        // FUNCTION: getMaximumImageWidth
        // PURPOSE:  Gets the maximum image width, in pixels, supported by the engine.
        // NOTES:    None.
        virtual std::size_t getMaximumImageWidth() const = 0;

        // FUNCTION: getMaximumImageHeight
        // PURPOSE:  Gets the maximum image height, in pixels, supported by the engine.
        // NOTES:    None.
        virtual std::size_t getMaximumImageHeight() const = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETIMAGELIMITS_HPP