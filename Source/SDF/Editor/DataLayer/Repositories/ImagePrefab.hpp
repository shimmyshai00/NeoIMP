#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEPREFAB_HPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEPREFAB_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ImagePrefab.hpp
// PURPOSE: Defines the ImagePrefab class.

#include <fruit/fruit.h>

#include <map>
#include <string>
#include <vector>
#include <memory>

#include "../../../Common/Data/IUidGenerator.hpp"
#include "../../../Common/Handle.hpp"
#include "../../ModelLayer/AbstractData/IImagePrefabRepository.hpp"
#include "../../UiLayer/AbstractModel/Defs/Image/Spec.hpp"

namespace SDF::Editor::DataLayer::Repositories {
    namespace Impl {
        struct Prefab;
    }

    // CLASS:   ImagePrefab
    // PURPOSE: Defines a repository of image prefabs including builtin ones as well as the possibility to add and save
    //          custom ones to the backing database.
    class ImagePrefab : public ModelLayer::AbstractData::IImagePrefabRepository {
       public:
        INJECT(ImagePrefab(Common::Data::IUidGenerator *a_uidGenerator));

        std::size_t getNumPrefabs() const;
        std::string getPrefabTitle(std::size_t a_which) const;
        UiLayer::AbstractModel::Defs::Image::Spec getPrefabSpec(std::size_t a_which) const;
       private:
        std::vector<Common::Handle> m_sort;
        std::map<Common::Handle, std::shared_ptr<Impl::Prefab>> m_builtins; // need shared_ptr to appease forward dec.

        Common::Data::IUidGenerator *m_uidGenerator;
    };
}  // namespace SDF::Editor::DataLayer::Repositories

#endif  // SDF_EDITOR_DATALAYER_REPOSITORIES_IMAGEPREFAB_HPP