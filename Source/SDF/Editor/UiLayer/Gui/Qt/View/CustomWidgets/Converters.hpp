#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_CONVERTERS_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_CONVERTERS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Converters.hpp
// PURPOSE: Defines unit converter wrappers for the measurement edit widget.

#include "../../../../../../Common/Mvc/ServicePack.hpp"
#include "../../../../../../Common/Handle.hpp"
#include "../../../../AbstractModel/Services/IConvertLength.hpp"

#include "IConverter.hpp"

#include <QStringList>

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // CLASS:   LengthConverter
    // PURPOSE: Defines a converter for length units.
    class LengthConverter : public IConverter {
       public:
        typedef Common::Mvc::ServicePack<AbstractModel::Services::IConvertLength> deps_t;
       public:
        LengthConverter(deps_t a_deps);

        QStringList getUnitNames() const;
        QStringList getUnitSymbols() const;

        float convert(float a_quantity, int a_fromUnit, int a_toUnit, Common::Handle a_conversionCtx);
       private:
        deps_t m_services;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#endif // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_CONVERTERS_HPP