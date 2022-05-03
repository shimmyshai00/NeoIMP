#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEPREFABREPOSITORY_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEPREFABREPOSITORY_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IImagePrefabRepository.hpp
// PURPOSE: Defines the IImagePrefabRepository interface.

#include <string>
#include <vector>

#include "../../../Common/Handle.hpp"
#include "../../UiLayer/AbstractModel/Defs/Image/Spec.hpp"

namespace SDF::Editor::ModelLayer::AbstractData {
    // CLASS:   IImagePrefabRepository
    // PURPOSE: Defines a repository interface for image prefabs. Note that these prefabs are kept in a sorted-list 
    //          form.
    class IImagePrefabRepository {
       public:
        virtual ~IImagePrefabRepository() = default;

        // FUNCTION: getNumPrefabs
        // PURPOSE:  Gets the number of stored prefabs.
        // NOTES:    None.
        virtual std::size_t getNumPrefabs() const = 0;

        // FUNCTION: getPrefabTitle
        // PURPOSE:  Gets the title of an image prefab.
        // NOTES:    which must range from 0 to getNumPrefabs()-1.
        virtual std::string getPrefabTitle(std::size_t a_which) const = 0;

        // FUNCTION: getPrefabSpec
        // PURPOSE:  Gets an image prefab spec.
        // NOTES:    which must range from 0 to getNumPrefabs()-1.
        virtual UiLayer::AbstractModel::Defs::Image::Spec getPrefabSpec(std::size_t a_which) const = 0;
    };
}  // namespace SDF::Editor::ModelLayer::AbstractData

#endif  // SDF_EDITOR_MODELLAYER_ABSTRACTDATA_IIMAGEPREFABREPOSITORY_HPP