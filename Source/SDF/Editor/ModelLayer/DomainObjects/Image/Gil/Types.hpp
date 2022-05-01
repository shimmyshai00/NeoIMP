#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_TYPES_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_TYPES_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Types.hpp
// PURPOSE: Defines helper data types for the Boost.GIL image implementation.

#include "../../Math/Point2D.hpp"
#include "../../Math/Rect.hpp"
#include "../../Math/Vec2D.hpp"

#include "Traits.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil {
    template<class ImplementationTagT>
    using NeoPointBg = Math::Point2D<typename ImplTraits<ImplementationTagT>::bg_coord_t>;

    template<class ImplementationTagT>
    using NeoVecBg = Math::Vec2D<typename ImplTraits<ImplementationTagT>::bg_coord_t>;

    template<class ImplementationTagT>
    using NeoRectBg = Math::Rect<typename ImplTraits<ImplementationTagT>::bg_coord_t>;

    template<class ImplementationTagT>
    using NeoPointFg = Math::Point2D<typename ImplTraits<ImplementationTagT>::fg_coord_t>;

    template<class ImplementationTagT>
    using NeoVecFg = Math::Vec2D<typename ImplTraits<ImplementationTagT>::fg_coord_t>;

    template<class ImplementationTagT>
    using NeoRectFg = Math::Rect<typename ImplTraits<ImplementationTagT>::fg_coord_t>;
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_TYPES_HPP