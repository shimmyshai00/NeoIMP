#ifndef SDF_EDITOR_MODELLAYER_SERVICES_CREATEIMAGE_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_CREATEIMAGE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    CreateImage.hpp
// PURPOSE: Defines the CreateImage class.

#include <fruit/fruit.h>

#include "../../../Common/Handle.hpp"
#include "../../UiLayer/AbstractModel/Defs/Image/Spec.hpp"
#include "../../UiLayer/AbstractModel/Services/ICreateImage.hpp"

namespace SDF::Editor::ModelLayer::Services {
    // CLASS:   CreateImage
    // PURPOSE: Defines the MVC service object used to create a new image.
    class CreateImage : public UiLayer::AbstractModel::Services::ICreateImage {
       public:
        INJECT(CreateImage());

        Common::Handle createImage(UiLayer::AbstractModel::Defs::Image::Spec a_spec);
    };
}  // namespace SDF::Editor::ModelLayer::Services

#endif  // SDF_EDITOR_MODELLAYER_SERVICES_CREATEIMAGE_HPP