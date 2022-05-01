#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_BACKGROUNDLAYER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_BACKGROUNDLAYER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    BackgroundLayer.hpp
// PURPOSE: Defines the BackgroundLayer template.

#include <cstddef>

#include "../ABackgroundLayer.hpp"
#include "ImageComposite.hpp"
#include "Traits.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil {
    // CLASS:   BackgroundLayer
    // PURPOSE: Defines the fully-implemented background layer using the Boost.GIL primitives package.
    template <class ImplementationTagT>
    class BackgroundLayer : public ABackgroundLayer<ImplementationTagT> {
       public:
        // FUNCTION: BackgroundLayer
        // PURPOSE:  Construct the new background layer.
        // NOTES:    None.
        BackgroundLayer(std::size_t a_width,
                        std::size_t a_height,
                        typename ImplTraits<ImplementationTagT>::pixel_t a_fillColor);

        std::size_t getWidth() const;
        std::size_t getHeight() const;
        Image::ImplIndepRect getDimensionsRect() const;

        // FUNCTION: getView
        // PURPOSE:  Gets a view onto the raster data.
        // NOTES:    None.
        typename ImplTraits<ImplementationTagT>::bg_view_t getView();
        typename ImplTraits<ImplementationTagT>::bg_view_t::const_t getView() const;

        typename ImplTraits<ImplementationTagT>::bg_view_t getView(
            typename ImplTraits<ImplementationTagT>::bg_point_t a_upperLeft,
            typename ImplTraits<ImplementationTagT>::bg_point_t a_lowerRight);
        typename ImplTraits<ImplementationTagT>::bg_view_t::const_t getView(
            typename ImplTraits<ImplementationTagT>::bg_point_t a_upperLeft,
            typename ImplTraits<ImplementationTagT>::bg_point_t a_lowerRight) const;

       private:
        ImplTraits<ImplementationTagT>::bg_image_t m_data;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil

#include "BackgroundLayer.tpp"

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_BACKGROUNDLAYER_HPP