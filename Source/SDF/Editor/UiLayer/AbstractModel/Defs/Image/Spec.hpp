#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_SPEC_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_SPEC_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Spec.hpp
// PURPOSE: Defines a data structure holding a specification for a new document.

#include <cstddef>
#include <memory>
#include <string>

#include "../Color/ColorFormat.hpp"
#include "../Color/IColor.hpp"
#include "../Metrics/LengthUnit.hpp"
#include "../Metrics/ResolutionUnit.hpp"
#include "BackgroundPreset.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Image {
    struct Spec {
        std::string name;

        float width;
        Metrics::LengthUnit widthUnit;

        float height;
        Metrics::LengthUnit heightUnit;

        float resolution;
        Metrics::ResolutionUnit resolutionUnit;

        Color::ColorFormat colorFormat;
        BackgroundPreset backgroundPreset;
        std::shared_ptr<Color::IColor<Color::ColorFormat>> customBackgroundColor;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Image

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_SPEC_HPP