#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindowProducer.hpp
// PURPOSE: Defines the MainWindowProducer class.

#include <fruit/fruit.h>

#include <QPointer>

#include "../../../../../Common/Mvc/IViewProducer.hpp"
#include "../../../../../Common/Mvc/ServicePack.hpp"
#include "../../Controller/IUiTerminator.hpp"
#include "../View/MainWindow.hpp"

#include "NewDocumentDialogProducer.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    // CLASS:   MainWindowProducer
    // PURPOSE: Produces the main window view.
    class MainWindowProducer : public Common::Mvc::IViewProducer<>, private Controller::IUiTerminator {
       public:
        typedef Common::Mvc::UnionPack<NewDocumentDialogProducer::deps_t> deps_t;
       public:
        INJECT(MainWindowProducer(deps_t a_deps));

        void requestView();

       private:
        deps_t m_services;
        
        QPointer<View::MainWindow> m_mainWindow;

        void terminateUi();
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP