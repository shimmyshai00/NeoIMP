// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    EngineInfo.cpp
// PURPOSE: Implements the EngineInfo class.

#include "EngineInfo.hpp"

#include "../DomainObjects/Image/Defs.hpp"

namespace SDF::Editor::ModelLayer::Services {
    EngineInfo::EngineInfo() {}

    std::size_t EngineInfo::getMaximumImageWidth() const { return DomainObjects::Image::MAX_IMAGE_WIDTH; }
    std::size_t EngineInfo::getMaximumImageHeight() const { return DomainObjects::Image::MAX_IMAGE_HEIGHT; }
}  // namespace SDF::Editor::ModelLayer::Services