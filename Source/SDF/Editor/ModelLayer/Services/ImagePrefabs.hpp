#ifndef SDF_EDITOR_MODELLAYER_SERVICES_IMAGEPREFABS_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_IMAGEPREFABS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ImagePrefabs.hpp
// PURPOSE: Defines the ImagePrefabs class.

#include <fruit/fruit.h>

#include <cstddef>
#include <string>

#include "../../../UiLayer/AbstractModel/Defs/Image/Spec.hpp"
#include "../../../UiLayer/AbstractModel/Services/IGetImagePrefab.hpp"
#include "../AbstractData/IImagePrefabRepository.hpp"

namespace SDF::Editor::ModelLayer::Services {
    // CLASS:   ImagePrefabs
    // PURPOSE: Defines an MVC service for managing image prefabs.
    class ImagePrefabs : public UiLayer::AbstractModel::Services::IGetImagePrefab {
       public:
        INJECT(ImagePrefabs(AbstractData::IImagePrefabRepository *a_imagePrefabRepository));

        std::size_t getNumPrefabs();
        std::string getPrefabTitle(std::size_t a_index);
        UiLayer::AbstractModel::Defs::Image::Spec getPrefabSpec(std::size_t a_index);
       private:
        AbstractData::IImagePrefabRepository *m_imagePrefabRepository;
    };
}  // namespace SDF::Editor::ModelLayer::Services

#endif  // SDF_EDITOR_MODELLAYER_SERVICES_IMAGEPREFABS_HPP