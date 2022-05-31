#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_COLORFORMAT_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_COLORFORMAT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ColorFormat.hpp
// PURPOSE: Enumerates the available color formats.

#include <vector>

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    enum ColorFormat { 
        COLOR_FMT_RGB24_888, 
        COLOR_FMT_RGBA32_8888, 
        COLOR_FMT_MAX 
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    // Provides some extra information about the above.
    enum ColorModel { 
        COLOR_MODEL_RGB, 
        COLOR_MODEL_RGBA, 
        COLOR_MODEL_MAX 
    };

    static const std::vector<ColorFormat> g_colorFormatsForRgb = {
        COLOR_FMT_RGB24_888
    };

    static const std::vector<ColorFormat> g_colorFormatsForRgba = {
        COLOR_FMT_RGBA32_8888
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_COLORFORMAT_HPP