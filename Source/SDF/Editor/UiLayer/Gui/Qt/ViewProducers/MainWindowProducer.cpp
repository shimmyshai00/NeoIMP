// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindowProducer.cpp
// PURPOSE: Implements the MainWindowProducer class.

#include "MainWindowProducer.hpp"

#include "../../Controller/MainWindow/OnExit.hpp"
#include "../../Controller/MainWindow/OnNew.hpp"
#include "../View/MainWindow.hpp"
#include "NewDocumentDialogProducer.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    MainWindowProducer::MainWindowProducer(deps_t a_deps) : m_services(a_deps) {}

    void MainWindowProducer::requestView() {
        using namespace Common;

        m_mainWindow = new View::MainWindow();
        m_mainWindow->setAttribute(::Qt::WA_DeleteOnClose);
        m_mainWindow->show();

        auto onNew = std::unique_ptr<Mvc::IController<>>(new Controller::MainWindow::OnNew(
            std::unique_ptr<Mvc::IViewProducer<>>(new NewDocumentDialogProducer(m_services, m_mainWindow))));
        m_mainWindow->attachController(&View::MainWindow::onNew, std::move(onNew));

        auto onExit = std::unique_ptr<Mvc::IController<>>(new Controller::MainWindow::OnExit(this));
        m_mainWindow->attachController(&View::MainWindow::onExit, std::move(onExit));
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers {
    // Private member.
    void MainWindowProducer::terminateUi() { m_mainWindow->close(); }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers
