#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_AIMAGE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_AIMAGE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    AImage.hpp
// PURPOSE: Defines the AImage base class.

#include <cstddef>
#include <string>

#include "../../../Common/Visitor/IAcyclicVisitable.hpp"
#include "Image/Defs.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects {
    // CLASS:   AImage
    // PURPOSE: Defines the abstract base image class. Images are built up using an "entity-component" type of
    //          compositional fashion in that they are collections of Layers, who in turn get their identity from the
    //          types of Components attached thereto. Components are mostly data and should contain little logic.
    //          However, to avoid mixing raster engine implementations, while also permitting homogeneous inclusion
    //          into a container to represent documents under editing, we do not expose methods to manipulate the inner
    //          structures directly; instead we use a visitation interface.
    class AImage : public Common::Visitor::IAcyclicVisitable<AImage> {
       public:
        virtual ~AImage() = default;

        // FUNCTION: AImage
        // PURPOSE:  Constructs a new image base.
        // NOTES:    None.
        AImage(std::string a_name, float a_resolutionPpi);

        // FUNCTION: getName
        // PURPOSE:  Gets the name of the image.
        // NOTES:    None.
        std::string getName() const;

        // FUNCTION: getWidth
        // PURPOSE:  Gets the width of the image in pixels.
        // NOTES:    None.
        virtual std::size_t getWidth() const = 0;

        // FUNCTION: getHeight
        // PURPOSE:  Gets the height of the image in pixels.
        // NOTES:    None.
        virtual std::size_t getHeight() const = 0;

        // FUNCTION: getDimensionsRect
        // PURPOSE:  Gets the dimensions of the image as a rectangle.
        // NOTES:    None.
        virtual Image::ImplIndepRect getDimensionsRect() const = 0;

        // FUNCTION: getResolutionPpi
        // PURPOSE:  Gets the image resolution in PPI.
        // NOTES:    None.
        float getResolutionPpi() const;

        // FUNCTION: getNumLayers
        // PURPOSE:  Gets the number of layers in the image.
        // NOTES:    Because of the background layer, the return value from this is always at least 1.
        virtual std::size_t getNumLayers() const = 0;

       protected:
        std::string m_name;
        float m_resolutionPpi;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_AIMAGE_HPP