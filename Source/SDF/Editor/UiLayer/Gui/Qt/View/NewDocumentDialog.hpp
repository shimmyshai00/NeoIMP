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

#include "../../../../../Common/Mvc/ServicePack.hpp"
#include "../MvcAdapter/QtView.hpp"

#include "CustomWidgets/MeasurementEdit.hpp"

namespace Ui {
    class NewDocumentDialog;
}

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // CLASS:   NewDocumentDialog
    // PURPOSE: Defines a dialog for getting the information required to create a new image document from the user.
    class NewDocumentDialog : public MvcAdapter::QtView<QDialog, NewDocumentDialog> {
        Q_OBJECT
       public:
        typedef Common::Mvc::UnionPack<CustomWidgets::MeasurementEdit::deps_t> deps_t;
       public:
        NewDocumentDialog(deps_t a_deps, QWidget *a_parent = nullptr);
        ~NewDocumentDialog();

       private:
        deps_t m_services;
        Ui::NewDocumentDialog *m_ui;

        CustomWidgets::MeasurementEdit *m_widthEdit;
        CustomWidgets::MeasurementEdit *m_heightEdit;
        CustomWidgets::MeasurementEdit *m_resolutionEdit;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP