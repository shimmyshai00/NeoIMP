#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGECOMPOSITE_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGECOMPOSITE_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ImageComposite.tpp
// PURPOSE: Implements the ImageComposite template.

namespace SDF::Editor::ModelLayer::DomainObjects::Image {
    template <class ImplementationTagT>
    ImageComposite<ImplementationTagT>::ImageComposite(
        std::unique_ptr<ABackgroundLayer<ImplementationTagT>> a_backgroundLayer)
        : m_backgroundLayer(std::move(a_backgroundLayer)) {}

    template <class ImplementationTagT>
    std::size_t ImageComposite<ImplementationTagT>::getWidth() const {
        return m_backgroundLayer->getWidth();
    }

    template <class ImplementationTagT>
    std::size_t ImageComposite<ImplementationTagT>::getHeight() const {
        return m_backgroundLayer->getHeight();
    }

    template <class ImplementationTagT>
    Image::ImplIndepRect ImageComposite<ImplementationTagT>::getDimensionsRect() const {
        return Image::ImplIndepRect(0, 0, getWidth(), getHeight());
    }

    template <class ImplementationTagT>
    std::size_t ImageComposite<ImplementationTagT>::getNumLayers() const {
        return 1;
    }

    template <class ImplementationTagT>
    ABackgroundLayer<ImplementationTagT> &ImageComposite<ImplementationTagT>::getBackgroundLayer() {
        return *m_backgroundLayer;
    }

    template <class ImplementationTagT>
    const ABackgroundLayer<ImplementationTagT> &ImageComposite<ImplementationTagT>::getBackgroundLayer() const {
        return *m_backgroundLayer;
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_IMAGECOMPOSITE_TPP