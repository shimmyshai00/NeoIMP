#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_MEASUREMENTEDIT_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_MEASUREMENTEDIT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MeasurementEdit.hpp
// PURPOSE: Defines the MeasurementEdit class.

#include <QBoxLayout>
#include <QComboBox>
#include <QLineEdit>
#include <QPointer>
#include <QWidget>

#include "../../../../../../Common/Handle.hpp"
#include "../../../../../../Common/Mvc/ServicePack.hpp"
#include "../../../../AbstractModel/Services/IConvertLength.hpp"
#include "../../../../AbstractModel/Services/IConvertResolution.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // CLASS:   MeasurementEdit
    // PURPOSE: Defines a custom widget for editing quantities representing measurements.
    class MeasurementEdit : public QWidget {
        Q_OBJECT
       public:
        enum MeasurementType { MEASUREMENT_LENGTH, MEASUREMENT_RESOLUTION };

        typedef Common::Mvc::ServicePack<AbstractModel::Services::IConvertLength,
                                         AbstractModel::Services::IConvertResolution>
            deps_t;

       public:
        // FUNCTION: MeasurementEdit
        // PURPOSE:  Construct the new widget.
        // NOTES:    None.
        MeasurementEdit(deps_t a_deps, QWidget *a_parent = nullptr);

        // FUNCTION: measurementType
        // PURPOSE:  Gets the type of measurement being requested.
        // NOTES:    None.
        MeasurementType measurementType() const;

        // FUNCTION: quantity
        // PURPOSE:  Gets the quantity entered.
        // NOTES:    None.
        float quantity() const;

        // FUNCTION: unit
        // PURPOSE:  Gets the enumerated index of unit of measurement (will match one of the enum structures in
        //           AbstractModel).
        // NOTES:    None.
        int unit() const;

        // FUNCTION: conversionContext
        // PURPOSE:  Gets the conversion context used by this widget.
        // NOTES:    None.
        Common::Handle conversionContext() const;

        // FUNCTION: setMeasurementType
        // PURPOSE:  Sets the measurement type.
        // NOTES:    None.
        void setMeasurementType(MeasurementType a_measurementType);

        // FUNCTION: setQuantity
        // PURPOSE:  Sets the quantity.
        // NOTES:    None.
        void setQuantity(float a_quantity);

        // FUNCTION: setUnit
        // PURPOSE:  Sets the unit of measurement.
        // NOTES:    None.
        void setUnit(int a_unit);

        // FUNCTION: setConversionContext
        // PURPOSE:  Sets the conversion context.
        // NOTES:    None.
        void setConversionContext(Common::Handle a_ctx);
       public slots:

       signals:
        void quantityChanged(float a_quantity);
        void unitChanged(int a_unit);

       private:
        deps_t m_services;
        
        QPointer<QBoxLayout> m_boxLayout;
        QPointer<QLineEdit> m_quantityLineEdit;
        QPointer<QComboBox> m_unitSelectComboBox;

        MeasurementType m_measurementType;
        Common::Handle m_conversionCtx;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_MEASUREMENTEDIT_HPP