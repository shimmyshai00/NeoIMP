// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindowProducer.cpp
// PURPOSE: Implements the MainWindowProducer class.

#include "MainWindowProducer.hpp"

#include "../../Controller/MainWindow/OnExit.hpp"
#include "../View/MainWindow.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    MainWindowProducer::MainWindowProducer() {}

    void MainWindowProducer::requestView() {
        m_mainWindow = new View::MainWindow();
        m_mainWindow->setAttribute(::Qt::WA_DeleteOnClose);
        m_mainWindow->show();

        auto onExit = std::unique_ptr<Common::Mvc::IController<>>(new Controller::MainWindow::OnExit(this));
        m_mainWindow->attachController(&View::MainWindow::onExit, std::move(onExit));
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    // Private member.
    void MainWindowProducer::terminateUi() { m_mainWindow->close(); }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers
