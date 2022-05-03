// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ImagePrefab.cpp
// PURPOSE: Implements the ImagePrefab class.

#include "ImagePrefab.hpp"

#include "../../UiLayer/AbstractModel/Defs/Color/Types.hpp"
#include "../../UiLayer/AbstractModel/Defs/Metrics/LengthUnit.hpp"
#include "../../UiLayer/AbstractModel/Defs/Metrics/ResolutionUnit.hpp"
#include "../Exceptions.hpp"

namespace SDF::Editor::DataLayer::Repositories::Impl {
    using namespace UiLayer::AbstractModel::Defs::Image;
    using namespace UiLayer::AbstractModel::Defs::Metrics;
    using namespace UiLayer::AbstractModel::Defs::Color;

    // Built-in prefabs for image document creation.
    struct Prefab {
        std::string name;
        Spec spec;
    };

    static const std::vector<Prefab> g_builtinPrefabs = {
        {"U.S. Letter, 8.5\" x 11\", 150 DPI",
         Spec{"",                    // name placeholder
              8.5f,                  // width
              LENGTH_UNIT_INCH,      // width unit
              11.0f,                 // height
              LENGTH_UNIT_INCH,      // height unit
              150.0f,                // resolution
              RESOLUTION_UNIT_PPI,   // resolution unit
              COLOR_FMT_RGB24_888,   // color format
              PRE_BACKGROUND_WHITE,  // background preset
              make_shared_color<RGB24_888>({255, 255, 255})}},
        {"U.S. Letter, 8.5\" x 11\", 300 DPI",
         Spec{"", 8.5f, LENGTH_UNIT_INCH, 11.0f, LENGTH_UNIT_INCH, 300.0f, RESOLUTION_UNIT_PPI, COLOR_FMT_RGB24_888,
              PRE_BACKGROUND_WHITE, make_shared_color<RGB24_888>({255, 255, 255})}}};
}  // namespace SDF::Editor::DataLayer::Repositories::Impl

namespace SDF::Editor::DataLayer::Repositories {
    ImagePrefab::ImagePrefab(Common::Data::IUidGenerator *a_uidGenerator) : m_uidGenerator(a_uidGenerator) {
        for (const Impl::Prefab &pfb : Impl::g_builtinPrefabs) {
            Common::Handle handle = m_uidGenerator->getNextHandle();

            m_sort.push_back(handle);
            m_builtins[handle] = std::make_shared<Impl::Prefab>(pfb);
        }
    }

    std::size_t ImagePrefab::getNumPrefabs() const { return m_sort.size(); }

    std::string ImagePrefab::getPrefabTitle(std::size_t a_which) const {
        if (a_which >= m_sort.size()) {
            throw IndexOutOfRangeException(a_which, "ImagePrefab");
        } else {
            return m_builtins.at(m_sort[a_which])->name;
        }
    }

    UiLayer::AbstractModel::Defs::Image::Spec ImagePrefab::getPrefabSpec(std::size_t a_which) const {
        if (a_which >= m_sort.size()) {
            throw IndexOutOfRangeException(a_which, "ImagePrefab");
        } else {
            return m_builtins.at(m_sort[a_which])->spec;
        }
    }
}  // namespace SDF::Editor::DataLayer::Repositories