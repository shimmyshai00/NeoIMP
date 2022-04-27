// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindow.cpp
// PURPOSE: Implements the MainWindow class.

#include "MainWindow.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    MainWindow::MainWindow() {
        QWidget *centralWidget = new QWidget();
        setCentralWidget(centralWidget);

        m_centralLayout = new QGridLayout(centralWidget);
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View