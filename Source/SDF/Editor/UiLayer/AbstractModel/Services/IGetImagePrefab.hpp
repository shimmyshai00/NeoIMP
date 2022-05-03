#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETIMAGEPREFAB_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETIMAGEPREFAB_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IGetImagePrefab.hpp
// PURPOSE: Defines the IGetImagePrefab interface.

#include <cstddef>
#include <string>

#include "../Defs/Image/Spec.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   IGetImagePrefab
    // PURPOSE: Defines a service interface to get prefabricated templates for creating images.
    class IGetImagePrefab {
       public:
        virtual ~IGetImagePrefab() = default;

        // FUNCTION: getNumPrefabs
        // PURPOSE:  Gets the number of stored prefabs.
        // NOTES:    None.
        virtual std::size_t getNumPrefabs() = 0;

        // FUNCTION: getPrefabTitle
        // PURPOSE:  Gets the title of a prefab by index (from 0 to getNumPrefabs()-1).
        // NOTES:    None.
        virtual std::string getPrefabTitle(std::size_t a_index) = 0;

        // FUNCTION: getPrefabSpec
        // PURPOSE:  Gets the image spec of a prefab by index.
        // NOTES:    None.
        virtual Defs::Image::Spec getPrefabSpec(std::size_t a_index) = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IGETIMAGEPREFAB_HPP