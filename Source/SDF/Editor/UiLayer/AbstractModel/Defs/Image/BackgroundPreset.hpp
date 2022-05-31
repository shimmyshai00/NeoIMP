#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_BACKGROUNDPRESET_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_BACKGROUNDPRESET_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    BackgroundPreset.hpp
// PURPOSE: Enumerates the available background color presets.

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Image {
    enum BackgroundPreset {
        PRE_BACKGROUND_WHITE,
        PRE_BACKGROUND_BLACK,
        PRE_BACKGROUND_TRANSPARENT,
        PRE_BACKGROUND_CUSTOM,
        PRE_BACKGROUND_MAX
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Image

#endif // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_IMAGE_BACKGROUNDPRESET_HPP