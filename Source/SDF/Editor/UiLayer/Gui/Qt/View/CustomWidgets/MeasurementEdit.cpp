// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MeasurementEdit.cpp
// PURPOSE: Implements the MeasurementEdit class.

#include "MeasurementEdit.hpp"

#include <QString>
#include <QWidget>

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::Impl {
    // CLASS:   MeasurementValidator
    // PURPOSE: Provides a custom validator to properly validate the floating-point ranges on the entered input.
    class MeasurementValidator : public QDoubleValidator {
       public:
        explicit MeasurementValidator(QObject *parent = nullptr) : QDoubleValidator(parent) {}

        MeasurementValidator(double bottom, double top, int decimals, QObject *parent = nullptr)
            : QDoubleValidator(bottom, top, decimals, parent) {}

        virtual void fixup(QString &input) const override {
            bool ok(false);
            double attemptConv(input.toDouble(&ok));
            if (ok) {
                // valid number, just out of range
                input = QString::number(std::clamp(attemptConv, bottom(), top()), 'f', decimals());
            } else {
                // not a valid number; can't do nothing, sorry :(
            }
        }
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets::Impl

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    MeasurementEdit::MeasurementEdit(QWidget *a_parent)
        : QWidget(a_parent),
          m_boxLayout(new QBoxLayout(QBoxLayout::LeftToRight, this)),
          m_quantityLineEdit(new QLineEdit("0.0")),
          m_unitSelectComboBox(new QComboBox),
          m_rangeValidator(new Impl::MeasurementValidator(0.0, 1.0, 2)) {
        // Create the layout for this widget, which consists of a line edit to enter the quantity, with
        // a combo box to the right for selecting the unit.
        m_boxLayout->setContentsMargins(0, 0, 0, 0);
        m_boxLayout->addWidget(m_quantityLineEdit);
        m_boxLayout->addWidget(m_unitSelectComboBox);

        m_rangeValidator->setNotation(QDoubleValidator::StandardNotation);
        m_quantityLineEdit->setValidator(m_rangeValidator);

        // Disable the widget until primed with a converter.
        m_quantityLineEdit->setEnabled(false);
        m_unitSelectComboBox->setEnabled(false);

        // Hook signals.
        connect(m_quantityLineEdit, &QLineEdit::editingFinished, [=]() {
            bool ok(false);
            double enteredValue(m_quantityLineEdit->text().toDouble(&ok));
            if (ok) {
                if (m_quantityLineEdit->text() != m_lastTextEntered) {
                    m_lastTextEntered = m_quantityLineEdit->text();
                    userEditedQuantity(m_lastTextEntered);
                }
            }
        });

        connect(m_unitSelectComboBox, QOverload<int>::of(&QComboBox::activated), [&](int index) {
            m_lastUnitIndex = index;
            userChangedUnit(index);
        });

        connect(m_unitSelectComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), [&](int index) {
            if (m_converter) {
                float quant = internalGetQuantity();
                float conv = m_converter->convert(quant, m_lastUnitIndex, index, m_conversionCtx);

                internalSetQuantity(conv);
            }
        });
    }

    void MeasurementEdit::setConversionContext(Common::Handle a_conversionCtx) { m_conversionCtx = a_conversionCtx; }

    void MeasurementEdit::setConverter(std::unique_ptr<IConverter> a_converter) {
        m_converter = std::move(a_converter);
        if (m_converter) {
            repopulateComboBox();

            m_quantityLineEdit->setEnabled(true);
            m_unitSelectComboBox->setEnabled(true);
        } else {
            m_quantityLineEdit->setEnabled(false);
            m_unitSelectComboBox->setEnabled(false);
        }
    }

    float MeasurementEdit::quantity() const { return m_lastTextEntered.toDouble(); }

    int MeasurementEdit::unit() const { return m_unitSelectComboBox->currentIndex(); }

    void MeasurementEdit::setQuantity(float a_quantity) {
        internalSetQuantity(a_quantity);

        quantityChanged(a_quantity);
    }

    void MeasurementEdit::setUnit(int a_unit) {
        internalSetUnit(a_unit);

        unitChanged(a_unit);
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // Private members.
    void MeasurementEdit::userEditedQuantity(const QString &a_editedQuantity) {
        quantityChanged(a_editedQuantity.toDouble());
    }

    void MeasurementEdit::userChangedUnit(int a_newUnit) { unitChanged(a_newUnit); }

    void MeasurementEdit::repopulateComboBox() {
        m_unitSelectComboBox->clear();

        QStringList unitSymbols = m_converter->getUnitSymbols();
        for (QString sym : unitSymbols) {
            m_unitSelectComboBox->addItem(sym);
        }
    }

    float MeasurementEdit::internalGetQuantity() { return m_lastTextEntered.toFloat(); }

    void MeasurementEdit::internalSetQuantity(float a_quantity) {
        m_lastTextEntered = QString::number(a_quantity, 'f', 2);
        m_quantityLineEdit->setText(m_lastTextEntered);
    }

    int MeasurementEdit::internalGetUnit() { return m_lastUnitIndex; }

    void MeasurementEdit::internalSetUnit(int a_unit) {
        m_lastUnitIndex = a_unit;
        m_unitSelectComboBox->setCurrentIndex(a_unit);
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets