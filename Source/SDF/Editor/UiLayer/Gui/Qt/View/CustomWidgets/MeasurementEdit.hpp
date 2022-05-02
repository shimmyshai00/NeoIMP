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
#include <QDoubleValidator>
#include <QLineEdit>
#include <QPointer>
#include <QWidget>
#include <memory>

#include "../../../../../../Common/Handle.hpp"
#include "IConverter.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    namespace Impl {
        class QuantityModulator;
        class MeasurementValidator;
    }

    // CLASS:   MeasurementEdit
    // PURPOSE: Defines a custom widget for editing quantities representing measurements.
    class MeasurementEdit : public QWidget {
        Q_OBJECT
       public:
        // FUNCTION: MeasurementEdit
        // PURPOSE:  Construct the new widget.
        // NOTES:    None.
        MeasurementEdit(QWidget *a_parent = nullptr);

        // FUNCTION: setConversionContext
        // PURPOSE:  Sets the conversion context to be used by this widget.
        // NOTES:    None.
        void setConversionContext(Common::Handle a_conversionCtx);

        // FUNCTION: setConverter
        // PURPOSE:  Sets the converter to be used by this widget.
        // NOTES:    None.
        void setConverter(std::unique_ptr<IConverter> a_converter);

        // FUNCTION: quantity
        // PURPOSE:  Gets the quantity entered.
        // NOTES:    None.
        float quantity() const;

        // FUNCTION: quantityIn
        // PURPOSE:  Gets the quantity entered in the given unit.
        // NOTES:    None.
        float quantityIn(int a_unit) const;

        // FUNCTION: unit
        // PURPOSE:  Gets the enumerated index of unit of measurement (will match one of the enum structures in
        //           AbstractModel).
        // NOTES:    None.
        int unit() const;

        // FUNCTION: setQuantity
        // PURPOSE:  Sets the quantity.
        // NOTES:    When set with this method, the quantity is set in the unit last given to setUnit(), or else the
        //           one selected by the user in the widget's drop-down box.
        void setQuantity(float a_quantity);

        // FUNCTION: setUnit
        // PURPOSE:  Sets the unit of measurement.
        // NOTES:    None.
        void setUnit(int a_unit);

        // FUNCTION: setMin
        // PURPOSE:  Sets the minimum of the acceptable range of inputs.
        // NOTES:    None.
        void setMin(float a_minQuantity, int a_unit);

        // FUNCTION: setMax
        // PURPOSE:  Sets the maximum of the acceptable range of inputs.
        // NOTES:    None.
        void setMax(float a_maxQuantity, int a_unit);
       signals:
        void quantityChanged(float a_quantity, int a_unit);
        void unitChanged(int a_unit);
       private:
        QPointer<QBoxLayout> m_boxLayout;
        QPointer<QLineEdit> m_quantityLineEdit;
        QPointer<QComboBox> m_unitSelectComboBox;

        std::shared_ptr<Impl::QuantityModulator> m_quantityModulator;
        QPointer<Impl::MeasurementValidator> m_measurementValidator;

        std::unique_ptr<IConverter> m_converter;
        Common::Handle m_conversionContext;

        float m_lastEnteredQuantity;
        int m_lastEnteredQuantityUnit;

        int m_displayUnit;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_MEASUREMENTEDIT_HPP