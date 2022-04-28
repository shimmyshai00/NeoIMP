#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_SPEC_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_SPEC_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Spec.hpp
// PURPOSE: Defines a data structure holding a specification for a new document.

#include <cstddef>
#include <string>

#include "../Color/ColorFormat.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Image {
    struct Spec {
        std::string name;

        std::size_t widthPx;
        std::size_t heightPx;

        float resolutionPpi;

        Color::ColorFormat colorFormat;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Image

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_SPEC_HPP