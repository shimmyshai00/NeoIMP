#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_NEWDOCUMENTDIALOGPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_NEWDOCUMENTDIALOGPRODUCER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    NewDocumentDialogProducer.hpp
// PURPOSE: Defines the NewDocumentDialogProducer class.

#include <QPointer>

#include "../../../../../Common/Mvc/IViewProducer.hpp"
#include "../../Controller/IUiTerminator.hpp"
#include "../View/MainWindow.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    // CLASS:   NewDocumentDialogProducer
    // PURPOSE: Produces the new-document dialog view.
    class NewDocumentDialogProducer : public Common::Mvc::IViewProducer<> {
       public:
        NewDocumentDialogProducer();

        void requestView();
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers

#endif // SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_NEWDOCUMENTDIALOGPRODUCER_HPP