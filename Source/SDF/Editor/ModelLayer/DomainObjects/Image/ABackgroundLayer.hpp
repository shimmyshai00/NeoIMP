#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_ABACKGROUNDLAYER_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_ABACKGROUNDLAYER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ABackgroundLayer.hpp
// PURPOSE: Defines the ABackgroundLayer base template.

#include <cstddef>
#include <string>

#include "Defs.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image {
    // CLASS:   ABackgroundLayer
    // PURPOSE: Defines an abstract base for the part of background layers that does not include the implementation-
    //          specific data structures. Background layers are defined separately because they are required to always
    //          be raster.
    template <class ImplementationTagT>
    class ABackgroundLayer {
       public:
        virtual ~ABackgroundLayer() = default;

        // FUNCTION: getName
        // PURPOSE:  Gets the name of the background layer.
        // NOTES:    None.
        std::string getName() const;

        // FUNCTION: getWidth
        // PURPOSE:  Gets the width of the background layer in pixels.
        // NOTES:    None.
        virtual std::size_t getWidth() const = 0;

        // FUNCTION: getHeight
        // PURPOSE:  Gets the height of the background layer in pixels.
        // NOTES:    None.
        virtual std::size_t getHeight() const = 0;

        // FUNCTION: getDimensionsRect
        // PURPOSE:  Gets the dimensions of the background layer as a rectangle.
        // NOTES:    None.
        virtual Image::ImplIndepRect getDimensionsRect() const = 0;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image

#include "ABackgroundLayer.tpp"

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_ABACKGROUNDLAYER_HPP