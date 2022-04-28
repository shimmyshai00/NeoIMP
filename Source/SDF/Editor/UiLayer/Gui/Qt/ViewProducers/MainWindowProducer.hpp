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
#include "../../Controller/IUiTerminator.hpp"
#include "../View/MainWindow.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    // CLASS:   MainWindowProducer
    // PURPOSE: Produces the main window view.
    class MainWindowProducer : public Common::Mvc::IViewProducer<>, private Controller::IUiTerminator {
       public:
        INJECT(MainWindowProducer());

        void requestView();

       private:
        QPointer<View::MainWindow> m_mainWindow;

        void terminateUi();
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEWPRODUCERS_MAINWINDOWPRODUCER_HPP