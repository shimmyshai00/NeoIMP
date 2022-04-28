#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICREATEIMAGE_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICREATEIMAGE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ICreateImage.hpp
// PURPOSE: Defines the ICreateImage interface.

#include "../../../../Common/Handle.hpp"
#include "../Defs/Image/Spec.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   ICreateImage
    // PURPOSE: Defines a service interface for creating a new image.
    class ICreateImage {
       public:
        virtual ~ICreateImage() = default;

        // FUNCTION: createImage
        // PURPOSE:  Create a new image.
        // NOTES:    None.
        virtual Common::Handle createImage(Defs::Image::Spec a_spec) = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_ICREATEIMAGE_HPP