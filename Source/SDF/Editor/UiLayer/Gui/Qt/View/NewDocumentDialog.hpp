#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialog.hpp
// PURPOSE: Defines the NewDocumentDialog class.

#include <QDialog>
#include <QPointer>
#include <QWidget>

#include "../MvcAdapter/QtView.hpp"

namespace Ui {
    class NewDocumentDialog;
}

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // CLASS:   NewDocumentDialog
    // PURPOSE: Defines a dialog for getting the information required to create a new image document from the user.
    class NewDocumentDialog : public MvcAdapter::QtView<QDialog, NewDocumentDialog> {
        Q_OBJECT
       public:
        NewDocumentDialog(QWidget *a_parent = nullptr);
        ~NewDocumentDialog();

       private:
        Ui::NewDocumentDialog *m_ui;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP