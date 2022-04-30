#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_UICOLORFORMAT_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_UICOLORFORMAT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    UiColorFormat.hpp
// PURPOSE: Defines an enumeration of the color formats that should be returned for UI use.

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    // These formats are broader since the IColor interface lets us return the ranges dynamically. We could do the
    // same for documents as well, but it is also useful to provide a "hint" to the model as to what the data is 
    // supposed to be.
    enum UiColorFormat {
        UI_COLOR_FMT_RGB,
        UI_COLOR_FMT_MAX
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

#endif // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_UICOLORFORMAT_HPP