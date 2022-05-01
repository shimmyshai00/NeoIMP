#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_TRAITS_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_TRAITS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Traits.hpp
// PURPOSE: Defines the traits of Boost.GIL image implementations.

#include "Tags.hpp"

#include <boost/gil/image.hpp>
#include <boost/gil/typedefs.hpp>

namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil {
    template<class ImplementationTagT>
    struct ImplTraits {};

    template<>
    struct ImplTraits<RGB24_888_Impl> {
        typedef boost::gil::rgb8_image_t bg_image_t;
        typedef boost::gil::rgb8_view_t bg_view_t;
        typedef boost::gil::rgb8_view_t::const_t bg_const_view_t;
        typedef boost::gil::rgb8_pixel_t bg_pixel_t;
        typedef boost::gil::rgb8_image_t::point_t bg_point_t;
        typedef boost::gil::rgb8_image_t::point_t::value_type bg_coord_t;

        typedef boost::gil::rgba8_image_t fg_image_t;
        typedef boost::gil::rgba8_view_t fg_view_t;
        typedef boost::gil::rgba8_view_t::const_t fg_const_view_t;
        typedef boost::gil::rgba8_pixel_t fg_pixel_t;
        typedef boost::gil::rgba8_image_t::point_t fg_point_t;
        typedef boost::gil::rgba8_image_t::point_t::value_type fg_coord_t;
    };

    template<>
    struct ImplTraits<RGBA32_8888_Impl> {
        typedef boost::gil::rgba8_image_t bg_image_t;
        typedef boost::gil::rgba8_view_t bg_view_t;
        typedef boost::gil::rgba8_view_t::const_t bg_const_view_t;
        typedef boost::gil::rgba8_pixel_t bg_pixel_t;
        typedef boost::gil::rgba8_image_t::point_t bg_point_t;
        typedef boost::gil::rgba8_image_t::point_t::value_type bg_coord_t;

        typedef boost::gil::rgba8_image_t fg_image_t;
        typedef boost::gil::rgba8_view_t fg_view_t;
        typedef boost::gil::rgba8_view_t::const_t fg_const_view_t;
        typedef boost::gil::rgba8_pixel_t fg_pixel_t;
        typedef boost::gil::rgba8_image_t::point_t fg_point_t;
        typedef boost::gil::rgba8_image_t::point_t::value_type fg_coord_t;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image::Gil

#endif // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_GIL_TRAITS_HPP