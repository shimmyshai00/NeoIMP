#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_NEWDOCUMENTDIALOGPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_NEWDOCUMENTDIALOGPRODUCER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialogProducer.hpp
// PURPOSE: Defines the NewDocumentDialogProducer class.

#include <QWidget>

#include "../../../../../Common/Mvc/IViewProducer.hpp"
#include "../../../../../Common/Mvc/ServicePack.hpp"
#include "../../Controller/IUiTerminator.hpp"
#include "../View/NewDocumentDialog.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    // CLASS:   NewDocumentDialogProducer
    // PURPOSE: Produces the new-document dialog view.
    class NewDocumentDialogProducer : public Common::Mvc::IViewProducer<> {
       public:
        typedef Common::Mvc::UnionPack<View::NewDocumentDialog::deps_t> deps_t;

       public:
        NewDocumentDialogProducer(deps_t a_deps, QWidget *a_parent);

        void requestView();

       private:
        deps_t m_services;

        QWidget *m_parent;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_NEWDOCUMENTDIALOGPRODUCER_HPP