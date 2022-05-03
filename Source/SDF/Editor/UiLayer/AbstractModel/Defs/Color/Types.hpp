#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_TYPES_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_TYPES_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Types.hpp
// PURPOSE: Defines the color data types for the different formats.

#include "ColorFormat.hpp"
#include "DocumentColor.hpp"

#include <memory>

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    typedef DocumentColor<COLOR_FMT_RGB24_888, 8, 8, 8> RGB24_888;
    typedef DocumentColor<COLOR_FMT_RGBA32_8888, 8, 8, 8, 8> RGBA32_8888;
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    // Helper method
    template<class ColorT>
    std::shared_ptr<ColorT> make_shared_color(const std::initializer_list<int> &a_il) {
        return std::shared_ptr<ColorT>(new ColorT(a_il));
    }
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_TYPES_HPP