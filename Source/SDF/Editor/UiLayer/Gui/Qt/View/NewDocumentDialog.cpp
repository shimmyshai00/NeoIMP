// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialog.cpp
// PURPOSE: Implements the NewDocumentDialog class.

#include "NewDocumentDialog.hpp"

#include <QtUiTools>

#include "Resources/Forms/ui_NewDocumentDialog.h"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    NewDocumentDialog::NewDocumentDialog(QWidget *a_parent)
        : QtView<QDialog, NewDocumentDialog>(a_parent), m_ui(new Ui::NewDocumentDialog) {
        m_ui->setupUi(this);
    }

    NewDocumentDialog::~NewDocumentDialog() { delete m_ui; }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View