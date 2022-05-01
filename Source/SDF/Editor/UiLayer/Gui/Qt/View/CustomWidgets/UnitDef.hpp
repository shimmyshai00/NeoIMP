// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    UnitDef.hpp
// PURPOSE: Defines the UnitDef class.

#include <QStringList>

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // CLASS:   IConverter
    // PURPOSE: Defines an interface for converters.
    class IConverter {
       public:
        virtual ~IConverter() = default;

        // FUNCTION: convert
        // PURPOSE:  Do the unit conversion.
        // NOTES:    None.
        virtual float convert(float a_quantity, int a_fromUnit, int a_toUnit) = 0;
    };

    // CLASS:   UnitDef
    // PURPOSE: Wraps the information required to install support for a unit into MeasurementEdit.
    class UnitDef {
       public:
        // FUNCTION: UnitDef
        // PURPOSE:  Construct the new definition.
        // NOTES:    None.
        UnitDef(const QStringList *a_unitNames, const QStringList *a_unitSymbols, std::unique_ptr<IConverter> a_converter);
    };
    
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets