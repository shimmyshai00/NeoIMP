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
#include "../../../../../Common/Hsm/Hsm.hpp"
#include "../../../../../Common/Handle.hpp"
#include "../../../AbstractModel/Services/IGetImageLimits.hpp"
#include "../../../AbstractModel/Services/IGetImagePrefab.hpp"
#include "../../../AbstractModel/Services/IConversionContextManipulator.hpp"
#include "../../../AbstractModel/Services/IConvertLength.hpp"
#include "../../../AbstractModel/Services/IConvertResolution.hpp"
#include "HsmManagedView.hpp"

namespace Ui {
    class NewDocumentDialog;
}

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // CLASS:   NewDocumentDialog
    // PURPOSE: Defines a dialog for getting the information required to create a new image document from the user.
    class NewDocumentDialog : public HsmManagedView<QDialog, NewDocumentDialog> {
        Q_OBJECT
       public:
        typedef Common::Mvc::ServicePack<AbstractModel::Services::IGetImageLimits,
                                         AbstractModel::Services::IGetImagePrefab,
                                         AbstractModel::Services::IUnitConversionContextManipulator,
                                         AbstractModel::Services::IConvertLength,
                                         AbstractModel::Services::IConvertResolution>
            deps_t;

       public:
        NewDocumentDialog(deps_t a_deps, QWidget *a_parent = nullptr);
       private:
        friend class NewDocumentDialogRootState;

        View::NewDocumentDialog::deps_t m_services;
        Ui::NewDocumentDialog *m_ui;

        Common::Handle m_conversionContext;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_NEWDOCUMENTDIALOG_HPP