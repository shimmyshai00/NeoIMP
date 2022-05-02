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

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // CLASS:   WidgetModel
    // PURPOSE: Provides the inner behavioral model for the measurement edit widget. This separates out the logic of the
    //          widget from its display aspects. The interface of this model mirrors the for-user behavior.
    class MeasurementEdit::WidgetModel {
       public:
        WidgetModel()
            : m_conversionContext(Common::HANDLE_INVALID),
              m_quantity(0.0f),
              m_unit(-1),
              m_displayQuantity("0.00"),
              m_displayUnit(-1),
              m_minQuantity(0.0f),
              m_minUnit(-1),
              m_maxQuantity(0.0f),
              m_maxUnit(-1) {}

        bool hasConverter() const { return m_converter.get() != nullptr; }

        void setConverter(std::unique_ptr<IConverter> a_converter) { m_converter = std::move(a_converter); }

        void setConversionContext(Common::Handle a_conversionContext) { m_conversionContext = a_conversionContext; }

        // Like the user entering text. Enters the given quantity in the display.
        void enterQuantity(QString a_enteredText) {
            if (m_converter) {
                bool ok(false);
                double quantity(a_enteredText.toDouble(&ok));
                if (ok) {
                    m_displayQuantity = QString::number(quantity, 'f', 2);

                    m_quantity = clampQuantity(quantity, m_displayUnit);
                    m_unit = m_displayUnit;
                }
            }
        }

        // Same behavior but float input.
        void enterQuantityF(float a_quantity) {
            if (m_converter) {
                m_displayQuantity = QString::number(a_quantity, 'f', 2);

                m_quantity = clampQuantity(a_quantity, m_displayUnit);
                m_unit = m_displayUnit;
            }
        }

        // Like selecting with the dropdown box. Does not immediately alter the stored quantity.
        void selectUnit(int unit) {
            if (m_converter) {
                m_displayUnit = unit;
            }
        }

        QStringList getUnitNames() const {
            if (m_converter) {
                return m_converter->getUnitNames();
            } else {
                return QStringList();
            }
        }

        QStringList getUnitSymbols() const {
            if (m_converter) {
                return m_converter->getUnitSymbols();
            } else {
                return QStringList();
            }
        }

        float getQuantity() const {
            if (m_converter) {
                return m_quantity;
            } else {
                return 0.0f;
            }
        }

        int getUnit() const {
            if (m_converter) {
                return m_unit;
            } else {
                return -1;
            }
        }

        const QString &getDisplayQuantity() const {
            if (m_converter) {
                return m_displayQuantity;
            } else {
                static QString nullStr = "0.0";

                return nullStr;
            }
        }

        int getDisplayUnit() const {
            if (m_converter) {
                return m_displayUnit;
            } else {
                return -1;
            }
        }

        void setMinQuantity(float a_minQuantity, int a_unit) {
            if (m_converter) {
                m_minQuantity = a_minQuantity;
                m_minUnit = a_unit;
            }
        }

        void setMaxQuantity(float a_maxQuantity, int a_unit) {
            if (m_converter) {
                m_maxQuantity = a_maxQuantity;
                m_maxUnit = a_unit;
            }
        }

       private:
        std::unique_ptr<IConverter> m_converter;
        Common::Handle m_conversionContext;

        float m_quantity;
        int m_unit;

        QString m_displayQuantity;
        int m_displayUnit;

        float m_minQuantity;
        int m_minUnit;

        float m_maxQuantity;
        int m_maxUnit;

        // Clamps a quantity to the inner range.
        float clampQuantity(float quantity, int unit) {
            float minQuantityInUnit = m_converter->convert(m_minQuantity, m_minUnit, unit, m_conversionContext);
            float maxQuantityInUnit = m_converter->convert(m_maxQuantity, m_maxUnit, unit, m_conversionContext);

            return std::clamp(quantity, minQuantityInUnit, maxQuantityInUnit);
        }
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    MeasurementEdit::MeasurementEdit(QWidget *a_parent)
        : QWidget(a_parent),
          m_boxLayout(new QBoxLayout(QBoxLayout::LeftToRight, this)),
          m_quantityLineEdit(new QLineEdit("0.0")),
          m_unitSelectComboBox(new QComboBox(this)),
          m_doubleValidator(new QDoubleValidator(this)),
          m_widgetModel(new WidgetModel()) {
        // Create the layout for this widget, which consists of a line edit to enter the quantity, with
        // a combo box to the right for selecting the unit.
        m_boxLayout->setContentsMargins(0, 0, 0, 0);
        m_boxLayout->addWidget(m_quantityLineEdit);
        m_boxLayout->addWidget(m_unitSelectComboBox);

        m_doubleValidator->setNotation(QDoubleValidator::StandardNotation);
        m_doubleValidator->setDecimals(2);
        m_quantityLineEdit->setValidator(m_doubleValidator);

        // Disable the widget until primed with a converter.
        m_quantityLineEdit->setEnabled(false);
        m_unitSelectComboBox->setEnabled(false);

        // Hook signals.
        connect(m_quantityLineEdit, &QLineEdit::editingFinished, [=]() {
            m_widgetModel->enterQuantity(m_quantityLineEdit->text());
            quantityChanged(m_widgetModel->getQuantity());
        });

        connect(m_unitSelectComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index) {
            printf("selecting unit index %d\n", index);
            m_widgetModel->selectUnit(index);
            unitChanged(index);
        });
    }

    void MeasurementEdit::setConversionContext(Common::Handle a_conversionCtx) {
        m_widgetModel->setConversionContext(a_conversionCtx);
    }

    void MeasurementEdit::setConverter(std::unique_ptr<IConverter> a_converter) {
        if (a_converter) {
            m_widgetModel->setConverter(std::move(a_converter));

            m_quantityLineEdit->setEnabled(true);
            m_unitSelectComboBox->setEnabled(true);

            // Populate the combo box with units.
            m_unitSelectComboBox->clear();
            for (QString str : m_widgetModel->getUnitSymbols()) {
                m_unitSelectComboBox->addItem(str);
            }
        }
    }

    float MeasurementEdit::quantity() const { return m_widgetModel->getQuantity(); }

    int MeasurementEdit::unit() const { return m_widgetModel->getUnit(); }

    void MeasurementEdit::setQuantity(float a_quantity) {
        if (m_widgetModel->hasConverter()) {
            m_widgetModel->enterQuantityF(a_quantity);
            m_quantityLineEdit->setText(m_widgetModel->getDisplayQuantity());

            quantityChanged(a_quantity);
        }
    }

    void MeasurementEdit::setUnit(int a_unit) {
        if (m_widgetModel->hasConverter()) {
            m_unitSelectComboBox->setCurrentIndex(a_unit);
            m_quantityLineEdit->setText(m_widgetModel->getDisplayQuantity());
        }
    }

    void MeasurementEdit::setMin(float a_minQuantity, int a_unit) {
        if (m_widgetModel->hasConverter()) {
            m_widgetModel->setMinQuantity(a_minQuantity, a_unit);
            m_quantityLineEdit->setText(m_widgetModel->getDisplayQuantity());
        }
    }

    void MeasurementEdit::setMax(float a_maxQuantity, int a_unit) {
        if (m_widgetModel->hasConverter()) {
            m_widgetModel->setMaxQuantity(a_maxQuantity, a_unit);
            m_quantityLineEdit->setText(m_widgetModel->getDisplayQuantity());
        }
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets