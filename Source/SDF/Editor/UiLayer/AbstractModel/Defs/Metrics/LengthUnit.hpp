#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_METRICS_LENGTHUNIT_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_METRICS_LENGTHUNIT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    LengthUnit.hpp
// PURPOSE: Enumerates the available units of measurement for measuring lengths.

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Metrics {
    enum LengthUnit {
        LENGTH_UNIT_PIXEL,
        LENGTH_UNIT_POINT,
        LENGTH_UNIT_MILLIMETER,
        LENGTH_UNIT_PICA,
        LENGTH_UNIT_CENTIMETER,
        LENGTH_UNIT_INCH,
        LENGTH_UNIT_MAX
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Metrics

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_METRICS_LENGTHUNIT_H
