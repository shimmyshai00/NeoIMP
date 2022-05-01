#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_ABACKGROUNDLAYER_TPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_ABACKGROUNDLAYER_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ABackgroundLayer.tpp
// PURPOSE: Implements the ABackgroundLayer template.

#include "ABackgroundLayer.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Image {
    template <class ImplementationTagT>
    std::string ABackgroundLayer<ImplementationTagT>::getName() const {
        return "Background";
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Image

#endif  // SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_IMAGE_ABACKGROUNDLAYER_TPP