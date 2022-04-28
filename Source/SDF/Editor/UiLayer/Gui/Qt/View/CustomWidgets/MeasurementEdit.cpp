// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MeasurementEdit.cpp
// PURPOSE: Implements the MeasurementEdit class.

#include "MeasurementEdit.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    MeasurementEdit::MeasurementEdit(deps_t a_deps, QWidget *a_parent) : QWidget(a_parent), m_services(a_deps) {}

    MeasurementEdit::MeasurementType MeasurementEdit::measurementType() const { return MEASUREMENT_LENGTH; }

    float MeasurementEdit::quantity() const { return 0.0f; }

    int MeasurementEdit::unit() const { return -1; }

    Common::Handle MeasurementEdit::conversionContext() const { return Common::HANDLE_INVALID; }

    void MeasurementEdit::setMeasurementType(MeasurementType a_measurementType) {}

    void MeasurementEdit::setQuantity(float a_quantity) {}

    void MeasurementEdit::setUnit(int a_unit) {}

    void MeasurementEdit::setConversionContext(Common::Handle a_ctx) {}
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets
