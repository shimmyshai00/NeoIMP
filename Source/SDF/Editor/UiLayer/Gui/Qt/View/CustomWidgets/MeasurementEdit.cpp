// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MeasurementEdit.cpp
// PURPOSE: Implements the MeasurementEdit class.

#include "MeasurementEdit.hpp"

#include <QString>
#include <QWidget>
#include <algorithm>

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::Impl {
    // CLASS:   QuantityModulator
    // PURPOSE: Provides a helper to modulate a quantity to within a range.
    class QuantityModulator {
       public:
        QuantityModulator(float a_min, float a_max)
            : m_min(a_min),
              m_max(a_max),
              m_converter(nullptr),
              m_conversionCtx(Common::HANDLE_INVALID),
              m_entryUnit(0),
              m_dimensionfulMin(0.0f),
              m_dimensionfulMinUnit(0),
              m_dimensionfulMax(1.0f),
              m_dimensionfulMaxUnit(0) {}

        float getMin() const { return m_min; }
        float getMax() const { return m_max; }

        int getEntryUnit() const { return m_entryUnit; }

        float getDimensionfulMin() const { return m_dimensionfulMin; }
        int getDimensionfulMinUnit() const { return m_dimensionfulMinUnit; }
        float getDimensionfulMax() const { return m_dimensionfulMax; }
        int getDimensionfulMaxUnit() const { return m_dimensionfulMaxUnit; }

        void setMin(float a_min) { m_min = a_min; }
        void setMax(float a_max) { m_max = a_max; }

        void setConverter(IConverter *a_converter) { m_converter = a_converter; }
        void setConversionCtx(Common::Handle a_conversionCtx) { m_conversionCtx = a_conversionCtx; }

        void setEntryUnit(int a_unit) { m_entryUnit = a_unit; }

        void setDimensionfulMin(float a_min, int a_unit) {
            m_dimensionfulMin = a_min;
            m_dimensionfulMinUnit = a_unit;
        }

        void setDimensionfulMax(float a_max, int a_unit) {
            m_dimensionfulMax = a_max;
            m_dimensionfulMaxUnit = a_unit;
        }

        bool isInRange(float a_quantity) { return (getActiveMin() <= a_quantity) && (a_quantity <= getActiveMax()); }

        float clampToRange(float a_quantity) { return std::clamp(a_quantity, getActiveMin(), getActiveMax()); }

       private:
        float m_min;
        float m_max;

        // Dynamic min and max based on converter.
        IConverter *m_converter;
        Common::Handle m_conversionCtx;

        int m_entryUnit;

        float m_dimensionfulMin;
        int m_dimensionfulMinUnit;

        float m_dimensionfulMax;
        int m_dimensionfulMaxUnit;

       private:
        float getActiveMin() const {
            if (m_converter != nullptr) {
                return m_converter->convert(m_dimensionfulMin, m_dimensionfulMinUnit, m_entryUnit, m_conversionCtx);
            } else {
                return m_min;
            }
        }

        float getActiveMax() const {
            if (m_converter != nullptr) {
                return m_converter->convert(m_dimensionfulMax, m_dimensionfulMaxUnit, m_entryUnit, m_conversionCtx);
            } else {
                return m_max;
            }
        }
    };

    // FUNCTION: formatQuantity
    // PURPOSE:  A helper method to format a quantity to the widget's standard format.
    // NOTES:    None.
    QString formatQuantity(float a_quantity, int a_decimals) { return QString::number(a_quantity, 'f', a_decimals); }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::Impl

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::Impl {
    // CLASS:   MeasurementValidator
    // PURPOSE: Provides a custom validator to clamp the range.
    class MeasurementValidator : public QValidator {
       public:
        MeasurementValidator(QuantityModulator *a_modulator, int a_decimals, QObject *a_parent = nullptr)
            : QValidator(a_parent), m_modulator(a_modulator), m_decimals(a_decimals) {}

        QValidator::State validate(QString &input, int &pos) const {
            // Validate it even makes sense as a float to begin with.
            bool ok(false);
            float gotFloat = locale().toFloat(input, &ok);
            if (!ok) {
                return QValidator::State::Invalid;
            } else {
                // Passed primary validation. Now do range check.
                if (!m_modulator->isInRange(gotFloat)) {
                    return QValidator::State::Intermediate;
                } else {
                    return QValidator::State::Acceptable;
                }
            }
        }

        virtual void fixup(QString &input) const override {
            bool ok(false);
            float gotFloat = locale().toFloat(input, &ok);
            if (ok) {
                gotFloat = m_modulator->clampToRange(gotFloat);
                input = formatQuantity(gotFloat, m_decimals);
            }
        }

       private:
        QuantityModulator *m_modulator;

        int m_decimals;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::Impl

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    MeasurementEdit::MeasurementEdit(QWidget *a_parent)
        : QWidget(a_parent),
          m_boxLayout(new QBoxLayout(QBoxLayout::LeftToRight, this)),
          m_quantityLineEdit(new QLineEdit("0.0")),
          m_unitSelectComboBox(new QComboBox(this)),
          m_quantityModulator(new Impl::QuantityModulator(0.0f, 1.0f)),
          m_measurementValidator(new Impl::MeasurementValidator(m_quantityModulator.get(), 2, this)),
          m_conversionContext(Common::HANDLE_INVALID),
          m_lastEnteredQuantity(0.0f),
          m_lastEnteredQuantityUnit(0),
          m_displayUnit(0) {
        // Create the layout for this widget, which consists of a line edit to enter the quantity, with
        // a combo box to the right for selecting the unit.
        m_boxLayout->setContentsMargins(0, 0, 0, 0);
        m_boxLayout->addWidget(m_quantityLineEdit);
        m_boxLayout->addWidget(m_unitSelectComboBox);

        m_quantityLineEdit->setValidator(m_measurementValidator);

        // Disable the widget until primed with a converter.
        m_quantityLineEdit->setEnabled(false);
        m_unitSelectComboBox->setEnabled(false);

        // Hook signals.
        connect(m_quantityLineEdit, &QLineEdit::editingFinished, [=]() {
            printf("entered text: %s\n", m_quantityLineEdit->text().toStdString().c_str());
            m_lastEnteredQuantity = m_quantityLineEdit->text().toFloat();
            m_lastEnteredQuantityUnit = m_displayUnit;

            quantityChanged(m_lastEnteredQuantity, m_lastEnteredQuantityUnit);
        });

        connect(m_unitSelectComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index) {
            printf("selecting unit index %d\n", index);
            m_quantityModulator->setEntryUnit(index);
            m_displayUnit = index;

            float convertedQuantity = m_converter->convert(m_lastEnteredQuantity, m_lastEnteredQuantityUnit,
                                                           m_displayUnit, m_conversionContext);
            m_quantityLineEdit->setText(Impl::formatQuantity(convertedQuantity, 2));

            unitChanged(index);
        });
    }

    void MeasurementEdit::setConversionContext(Common::Handle a_conversionCtx) {
        m_quantityModulator->setConversionCtx(a_conversionCtx);
        m_conversionContext = a_conversionCtx;
    }

    void MeasurementEdit::setConverter(std::unique_ptr<IConverter> a_converter) {
        if (a_converter) {
            m_converter = std::move(a_converter);
            m_quantityModulator->setConverter(m_converter.get());

            m_quantityLineEdit->setEnabled(true);
            m_unitSelectComboBox->setEnabled(true);

            // Populate the combo box with units.
            m_unitSelectComboBox->clear();
            for (QString str : m_converter->getUnitSymbols()) {
                m_unitSelectComboBox->addItem(str);
            }
        }
    }

    float MeasurementEdit::quantity() const { return m_lastEnteredQuantity; }

    float MeasurementEdit::quantityIn(int a_unit) const {
        if (m_converter) {
            return m_converter->convert(m_lastEnteredQuantity, m_lastEnteredQuantityUnit, a_unit, m_conversionContext);
        } else {
            return 0.0f;
        }
    }

    int MeasurementEdit::unit() const { return m_displayUnit; }

    void MeasurementEdit::setQuantity(float a_quantity) {
        if (m_converter) {
            m_lastEnteredQuantity = m_quantityModulator->clampToRange(a_quantity);
            m_lastEnteredQuantityUnit = m_displayUnit;

            m_quantityLineEdit->setText(Impl::formatQuantity(a_quantity, 2));

            quantityChanged(m_lastEnteredQuantity, m_lastEnteredQuantityUnit);
        }
    }

    void MeasurementEdit::setUnit(int a_unit) {
        if (m_converter) {
            m_unitSelectComboBox->setCurrentIndex(a_unit);
        }
    }

    void MeasurementEdit::setMin(float a_minQuantity, int a_unit) {
        if (m_converter) {
            m_quantityModulator->setDimensionfulMin(a_minQuantity, a_unit);
        }
    }

    void MeasurementEdit::setMax(float a_maxQuantity, int a_unit) {
        if (m_converter) {
            m_quantityModulator->setDimensionfulMax(a_maxQuantity, a_unit);
        }
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets