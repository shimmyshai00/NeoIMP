#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_DEFS_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_DEFS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Defs.hpp
// PURPOSE: Defines data types common across different image implementation frameworks.

#include "../Math/Point2D.hpp"
#include "../Math/Rect.hpp"
#include "../Math/Vec2D.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image {
    typedef int ImplIndepMeasure;

    typedef Math::Point2D<ImplIndepMeasure> ImplIndepPoint2D;
    typedef Math::Vec2D<ImplIndepMeasure> ImplIndepVec2D;
    typedef Math::Rect<ImplIndepMeasure> ImplIndepRect;

    // We choose these values to hopefully! ensure that any other image implementation facilities we might want to use 
    // will be able to still work. In particular, these are ensured to fit within a signed 16-bit integer, and provides 
    // for images up to 1.07 Gpx in size.
    static const ImplIndepMeasure MAX_IMAGE_WIDTH = 32767;
    static const ImplIndepMeasure MAX_IMAGE_HEIGHT = 32767;
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image

#endif