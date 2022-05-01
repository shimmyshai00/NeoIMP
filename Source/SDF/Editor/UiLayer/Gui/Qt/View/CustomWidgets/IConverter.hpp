#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_ICONVERTER_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_ICONVERTER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IConverter.hpp
// PURPOSE: Defines the IConverter interface.

#include <QStringList>

#include "../../../../../../Common/Handle.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // CLASS:   IConverter
    // PURPOSE: Defines an interface for unit converter wrappers.
    class IConverter {
       public:
        virtual ~IConverter() = default;

        // FUNCTION: getUnitNames
        // PURPOSE:  Gets the names of the units.
        // NOTES:    They should be returned in enumeration order (i.e. element 0 is the name of unit 0, etc.).
        virtual QStringList getUnitNames() const = 0;

        // FUNCTION: getUnitSymbols
        // PURPOSE:  Gets the symbols of the units.
        // NOTES:    They should be returned in enumeration order.
        virtual QStringList getUnitSymbols() const = 0;

        // FUNCTION: convert
        // PURPOSE:  Converts a quantity from one unit to another.
        // NOTES:    Requires specifying a model-layer conversion context as conversions are presumed to be performed
        //           there.
        virtual float convert(float a_quantity, int a_fromUnit, int a_toUnit, Common::Handle a_conversionCtx) = 0;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_ICONVERTER_HPP