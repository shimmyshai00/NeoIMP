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
#include "Resources/Forms/ui_NewDocumentDialog.h"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    NewDocumentDialog::NewDocumentDialog(deps_t a_deps, QWidget *a_parent)
        : QtView<QDialog, NewDocumentDialog>(a_parent), m_services(a_deps), m_ui(new Ui::NewDocumentDialog) {
        using namespace UiLayer::AbstractModel::Defs::Metrics;
        using namespace UiLayer::AbstractModel::Services;

        m_ui->setupUi(this);

        // Inject and setup the measurement edit widgets.
        m_ui->widthEdit->setConverter(std::make_unique<CustomWidgets::LengthConverter>(a_deps));
        m_ui->heightEdit->setConverter(std::make_unique<CustomWidgets::LengthConverter>(a_deps));

        m_ui->widthEdit->setMin(1.0f, LENGTH_UNIT_PIXEL);
        m_ui->widthEdit->setMax(a_deps.get<IGetImageLimits>()->getMaximumImageWidth(), LENGTH_UNIT_PIXEL);

        m_ui->heightEdit->setMin(1.0f, LENGTH_UNIT_PIXEL);
        m_ui->heightEdit->setMax(a_deps.get<IGetImageLimits>()->getMaximumImageHeight(), LENGTH_UNIT_PIXEL);

        // Set defaults
        m_ui->widthEdit->setUnit(LENGTH_UNIT_PIXEL);
        m_ui->widthEdit->setQuantity(1280.0f);

        m_ui->heightEdit->setUnit(LENGTH_UNIT_PIXEL);
        m_ui->heightEdit->setQuantity(720.0f);
    }

    NewDocumentDialog::~NewDocumentDialog() { delete m_ui; }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View