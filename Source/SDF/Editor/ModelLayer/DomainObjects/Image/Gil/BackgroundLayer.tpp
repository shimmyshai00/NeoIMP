#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_BACKGROUNDLAYER_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_BACKGROUNDLAYER_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    BackgroundLayer.tpp
// PURPOSE: Implements the BackgroundLayer template.

#include <boost/gil/image.hpp>

#include "Types.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil {
    template <class ImplementationTagT>
    BackgroundLayer<ImplementationTagT>::BackgroundLayer(std::size_t a_width,
                                                         std::size_t a_height,
                                                         typename ImplTraits<ImplementationTagT>::pixel_t a_fillColor)
        : m_data(a_width, a_height, a_fillColor) {}

    template <class ImplementationTagT>
    std::size_t BackgroundLayer<ImplementationTagT>::getWidth() const {
        return m_data.width();
    }

    template <class ImplementationTagT>
    std::size_t BackgroundLayer<ImplementationTagT>::getHeight() const {
        return m_data.height();
    }

    template <class ImplementationTagT>
    typename ImplTraits<ImplementationTagT>::bg_view_t BackgroundLayer<ImplementationTagT>::getView() {
        return boost::gil::view(m_data);
    }

    template <class ImplementationTagT>
    typename ImplTraits<ImplementationTagT>::bg_view_t::const_t BackgroundLayer<ImplementationTagT>::getView() const {
        return boost::gil::const_view(m_data);
    }

    template <class ImplementationTagT>
    typename ImplTraits<ImplementationTagT>::bg_view_t BackgroundLayer<ImplementationTagT>::getView(
        typename ImplTraits<ImplementationTagT>::bg_point_t a_upperLeft,
        typename ImplTraits<ImplementationTagT>::bg_point_t a_lowerRight) {
        // Clip the rectangle if it exceeds the bounds (neatly allows for large selections, for example).
        NeoRectBg<ImplementationTagT> requestRect = NeoRectBg<ImplementationTagT>(a_upperLeft, a_lowerRight);
        NeoRectBg<ImplementationTagT> clipRect = this->getDimensionsRect().intersect(requestRect);
        return boost::gil::subimage_view(
            boost::gil::view(m_data), typename ImplTraits<ImplementationTagT>::bg_point_t(clipRect.x1(), clipRect.y1()),
            typename ImplTraits<ImplementationTagT>::bg_point_t(clipRect.getWidth(), clipRect.getHeight()));
    }

    template <class ImplementationTagT>
    typename ImplTraits<ImplementationTagT>::bg_view_t::const_t BackgroundLayer<ImplementationTagT>::getView(
        typename ImplTraits<ImplementationTagT>::bg_point_t a_upperLeft,
        typename ImplTraits<ImplementationTagT>::bg_point_t a_lowerRight) const {
        NeoRectBg<ImplementationTagT> requestRect = NeoRectBg<ImplementationTagT>(a_upperLeft, a_lowerRight);
        NeoRectBg<ImplementationTagT> clipRect = this->getDimensionsRect().intersect(requestRect);
        return boost::gil::subimage_view(
            boost::gil::const_view(m_data),
            typename ImplTraits<ImplementationTagT>::bg_point_t(clipRect.x1(), clipRect.y1()),
            typename ImplTraits<ImplementationTagT>::bg_point_t(clipRect.getWidth(), clipRect.getHeight()));
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_BACKGROUNDLAYER_TPP