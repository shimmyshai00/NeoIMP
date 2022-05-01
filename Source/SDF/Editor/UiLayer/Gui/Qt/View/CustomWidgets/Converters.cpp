// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Converters.cpp
// PURPOSE: Implements converters for the measurement edit widget.

#include "Converters.hpp"

#include "unit_names.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    LengthConverter::LengthConverter(deps_t a_deps) : m_services(a_deps) {}

    QStringList LengthConverter::getUnitNames() const { return g_lengthUnitNames; }

    QStringList LengthConverter::getUnitSymbols() const { return g_lengthUnitSymbols; }

    float LengthConverter::convert(float a_quantity, int a_fromUnit, int a_toUnit, Common::Handle a_conversionCtx) {
        using namespace AbstractModel::Defs::Metrics;
        using namespace AbstractModel::Services;

        return m_services.get<IConvertLength>()->convert(a_quantity, static_cast<LengthUnit>(a_fromUnit),
                                                         static_cast<LengthUnit>(a_toUnit), a_conversionCtx);
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets