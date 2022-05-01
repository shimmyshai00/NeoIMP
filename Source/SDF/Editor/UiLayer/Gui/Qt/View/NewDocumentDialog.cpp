// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialog.cpp
// PURPOSE: Implements the NewDocumentDialog class.

#include "NewDocumentDialog.hpp"

#include <QtUiTools>

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    NewDocumentDialog::NewDocumentDialog(QWidget *a_parent)
        : QtView<QDialog, NewDocumentDialog>(a_parent)
    {
        // Load the form from the resources.
        QUiLoader uiLoader;
        QFile resFile(":/Forms/newdocumentdialog.ui");

        resFile.open(QFile::ReadOnly);
        m_form = uiLoader.load(&resFile, this);
        resFile.close();
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View