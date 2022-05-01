#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGECOMPOSITE_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGECOMPOSITE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ImageComposite.hpp
// PURPOSE: Defines the ImageComposite template.

#include <cstddef>
#include <memory>

#include "../AImage.hpp"
#include "ABackgroundLayer.hpp"
#include "Defs.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image {
    // CLASS:   ImageComposite
    // PURPOSE: Defines the composition structure of an image. This still does not implement the actual data, which
    //          depends on the specific libraries used, but manages the "entity-component" design aspects while also
    //          restricting compositions so as to avoid permitting mixing incompatible implementations.
    template <class ImplementationTagT>
    class ImageComposite : public AImage,
                           public Common::Visitor::IAcyclicVisitable<AImage, ImageComposite<ImplementationTagT>> {
       public:
        // FUNCTION: ImageComposite
        // PURPOSE:  Constructs the new image composite.
        // NOTES:    Each composite requires a background layer, so it must be provided in the construction.
        ImageComposite(std::unique_ptr<ABackgroundLayer<ImplementationTagT>> a_backgroundLayer);

        std::size_t getWidth() const;
        std::size_t getHeight() const;
        Image::ImplIndepRect getDimensionsRect() const;
        std::size_t getNumLayers() const;

        // FUNCTION: getBackgroundLayer
        // PURPOSE:  Accesses the background layer.
        // NOTES:    None.
        ABackgroundLayer<ImplementationTagT> &getBackgroundLayer();
        const ABackgroundLayer<ImplementationTagT> &getBackgroundLayer() const;

       private:
        std::unique_ptr<ABackgroundLayer<ImplementationTagT>> m_backgroundLayer;
    };
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image

#include "ImageComposite.tpp"

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGECOMPOSITE_HPP