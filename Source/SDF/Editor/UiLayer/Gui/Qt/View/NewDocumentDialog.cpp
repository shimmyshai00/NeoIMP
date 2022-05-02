// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialog.cpp
// PURPOSE: Implements the NewDocumentDialog class.

#include "NewDocumentDialog.hpp"

#include <QtUiTools>

#include "../../../AbstractModel/Defs/Metrics/LengthUnit.hpp"
#include "../../../AbstractModel/Defs/Metrics/ResolutionUnit.hpp"
#include "../../../AbstractModel/Defs/Image/Spec.hpp"
#include "CustomWidgets/Converters.hpp"
#include "CustomWidgets/MeasurementEdit.hpp"
#include "Resources/Forms/ui_NewDocumentDialog.h"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    NewDocumentDialog::NewDocumentDialog(deps_t a_deps, QWidget *a_parent)
        : QtView<QDialog, NewDocumentDialog>(a_parent), m_services(a_deps), m_ui(new Ui::NewDocumentDialog) {
        using namespace UiLayer::AbstractModel::Defs::Metrics;
        using namespace UiLayer::AbstractModel::Services;

        const float c_defaultResPpi = 72.0f;

        m_ui->setupUi(this);

        // Create a measurement unit conversion context.
        m_conversionContext = m_services.get<IUnitConversionContextManipulator>()->createUnitConversionContext(c_defaultResPpi);

        // Inject and setup the measurement edit widgets.
        m_ui->widthEdit->setConverter(std::make_unique<CustomWidgets::LengthConverter>(a_deps));
        m_ui->heightEdit->setConverter(std::make_unique<CustomWidgets::LengthConverter>(a_deps));
        m_ui->resolutionEdit->setConverter(std::make_unique<CustomWidgets::ResolutionConverter>(a_deps));

        m_ui->widthEdit->setConversionContext(m_conversionContext);
        m_ui->heightEdit->setConversionContext(m_conversionContext);
        m_ui->resolutionEdit->setConversionContext(m_conversionContext);

        m_ui->widthEdit->setMin(1.0f, LENGTH_UNIT_PIXEL);
        m_ui->widthEdit->setMax(a_deps.get<IGetImageLimits>()->getMaximumImageWidth(), LENGTH_UNIT_PIXEL);

        m_ui->heightEdit->setMin(1.0f, LENGTH_UNIT_PIXEL);
        m_ui->heightEdit->setMax(a_deps.get<IGetImageLimits>()->getMaximumImageHeight(), LENGTH_UNIT_PIXEL);

        m_ui->resolutionEdit->setMin(1.0f, RESOLUTION_UNIT_PPI);
        m_ui->resolutionEdit->setMax(1000.0f, RESOLUTION_UNIT_PPI);

        // Set defaults
        m_ui->widthEdit->setUnit(LENGTH_UNIT_PIXEL);
        m_ui->widthEdit->setQuantity(1280.0f);

        m_ui->heightEdit->setUnit(LENGTH_UNIT_PIXEL);
        m_ui->heightEdit->setQuantity(720.0f);

        m_ui->resolutionEdit->setUnit(RESOLUTION_UNIT_PPI);
        m_ui->resolutionEdit->setQuantity(c_defaultResPpi);

        // Hook signals
        connect(m_ui->resolutionEdit, &CustomWidgets::MeasurementEdit::quantityChanged, [&](float a_newQuantity) {
            float resPpi = m_ui->resolutionEdit->quantityIn(RESOLUTION_UNIT_PPI);
            m_services.get<IUnitConversionContextManipulator>()->setConversionResolution(m_conversionContext, resPpi);
        });
    }

    NewDocumentDialog::~NewDocumentDialog() { 
        using namespace UiLayer::AbstractModel::Services;

        delete m_ui; 

        m_services.get<IUnitConversionContextManipulator>()->deleteUnitConversionContext(m_conversionContext);
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View