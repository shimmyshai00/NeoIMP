#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_UNIT_NAMES_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_UNIT_NAMES_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    unit_names.hpp
// PURPOSE: Defines constants giving the names and symbols for measurement units.

#include <QString>
#include <QStringList>

#include "../../../../AbstractModel/Defs/Metrics/LengthUnit.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // should mirror the enumeration in AbstractModel::Defs::Metrics::LengthUnit
    static const QStringList g_lengthUnitNames = {
        "pixels",
        "points",
        "millimeters",
        "picas",
        "centimeters",
        "inches"
    };

    static const QStringList g_lengthUnitSymbols = {
        "px",
        "pt",
        "mm",
        "pica",
        "cm",
        "in"
    };

    // should mirror the enumeration in AbstractModel::Defs::Metrics::ResolutionUnit
    static const QStringList g_resolutionUnitNames = {
        "pixels per inch",
        "pixels per centimeter",
        "pixels per millimeter"
    };

    static const QStringList g_resolutionUnitSymbols = {
        "ppi",
        "px/cm",
        "px/mm"
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#endif // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_UNIT_NAMES_HPP