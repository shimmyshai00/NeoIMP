// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ImagePrefabs.cpp
// PURPOSE: Implements the ImagePrefabs class.

#include "ImagePrefabs.hpp"

namespace SDF::Editor::ModelLayer::Services {
    ImagePrefabs::ImagePrefabs(AbstractData::IImagePrefabRepository *a_imagePrefabRepository)
        : m_imagePrefabRepository(a_imagePrefabRepository) {}

    std::size_t ImagePrefabs::getNumPrefabs() { return m_imagePrefabRepository->getNumPrefabs(); }

    std::string ImagePrefabs::getPrefabTitle(std::size_t a_index) {
        return m_imagePrefabRepository->getPrefabTitle(a_index);
    }

    UiLayer::AbstractModel::Defs::Image::Spec ImagePrefabs::getPrefabSpec(std::size_t a_index) {
        return m_imagePrefabRepository->getPrefabSpec(a_index);
    }
}  // namespace SDF::Editor::ModelLayer::Services