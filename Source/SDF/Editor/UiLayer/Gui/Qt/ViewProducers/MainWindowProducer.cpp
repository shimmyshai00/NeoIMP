// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindowProducer.cpp
// PURPOSE: Implements the MainWindowProducer class.

#include "MainWindowProducer.hpp"

#include "../View/MainWindow.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers
{
    MainWindowProducer::MainWindowProducer() {}

    void MainWindowProducer::requestView() {
        auto *mainWindow = new View::MainWindow();
    }
} // namespace SDF::Editor::UiLayer::Gui::Qt::ViewProducers
