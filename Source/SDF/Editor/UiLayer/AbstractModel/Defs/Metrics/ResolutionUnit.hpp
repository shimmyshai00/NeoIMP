#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_METRICS_RESOLUTIONUNIT_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_METRICS_RESOLUTIONUNIT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ResolutionUnit.hpp
// PURPOSE: Enumerates the available units of measurement for measuring document resolution.

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Metrics {
    enum ResolutionUnit { 
        RESOLUTION_UNIT_PPI, 
        RESOLUTION_UNIT_PPCM, 
        RESOLUTION_UNIT_PPMM, 
        RESOLUTION_UNIT_MAX 
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Metrics

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_METRICS_RESOLUTIONUNIT_HPP