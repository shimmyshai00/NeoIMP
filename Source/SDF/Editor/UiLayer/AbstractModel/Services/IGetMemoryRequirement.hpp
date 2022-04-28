#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETMEMORYREQUIREMENT_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETMEMORYREQUIREMENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IGetMemoryRequirement.hpp
// PURPOSE: Defines the IGetMemoryRequirement interface.

#include <cstddef>

#include "../Defs/Image/Spec.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   IGetMemoryRequirement
    // PURPOSE: Defines a service interface for getting the memory requirements for creating a new image.
    class IGetMemoryRequirement {
       public:
        virtual ~IGetMemoryRequirement() = default;

        // FUNCTION: getMinimumMemoryForSpec
        // PURPOSE:  Gets the minimum memory required for an image of the given spec.
        // NOTES:    This memory is that required for the background layer of the image.
        virtual std::size_t getMinimumMemoryForSpec(Defs::Image::Spec a_spec) const = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETMEMORYREQUIREMENT_HPP