// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindow.cpp
// PURPOSE: Implements the MainWindow class.

#include "MainWindow.hpp"

#include <QAction>
#include <QMenuBar>

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    MainWindow::MainWindow() {
        QWidget *centralWidget = new QWidget();
        setCentralWidget(centralWidget);

        m_centralLayout = new QGridLayout(centralWidget);

        createMenus();

        setMinimumWidth(menuBar()->width());
        resize(QSize(800, 600));
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // Private members.
    void MainWindow::addMenuItem(QMenu *a_menu,
                                 QString a_caption,
                                 QString a_statusTip,
                                 const QList<QKeySequence> &a_shortcuts,
                                 void (MainWindow::*a_signalFunc)()) {
        QAction *qAction = new QAction(a_caption, this);
        qAction->setStatusTip(a_statusTip);
        qAction->setShortcuts(a_shortcuts);
        if (a_signalFunc != nullptr) {
            connect(qAction, &QAction::triggered, this, a_signalFunc);
        }

        a_menu->addAction(qAction);
    }

    void MainWindow::createMenus() {
        QMenu *m_fileMenu;
        QMenu *m_editMenu;
        QMenu *m_imageMenu;
        QMenu *m_layerMenu;
        QMenu *m_selectMenu;
        QMenu *m_filterMenu;
        QMenu *m_viewMenu;
        QMenu *m_windowMenu;
        QMenu *m_helpMenu;

        m_fileMenu = menuBar()->addMenu(tr("&File"));
        addMenuItem(m_fileMenu, tr("&New"), tr("Create a new image document"), { QKeySequence::New }, nullptr);
        addMenuItem(m_fileMenu, tr("E&xit"), tr("Exit the program"), { tr("Ctrl+Q") }, &MainWindow::onExit);

        m_editMenu = menuBar()->addMenu(tr("&Edit"));
        m_imageMenu = menuBar()->addMenu(tr("&Image"));
        m_layerMenu = menuBar()->addMenu(tr("&Layer"));
        m_selectMenu = menuBar()->addMenu(tr("&Select"));
        m_filterMenu = menuBar()->addMenu(tr("Fil&ter"));
        m_viewMenu = menuBar()->addMenu(tr("&View"));
        m_windowMenu = menuBar()->addMenu(tr("&Window"));
        m_helpMenu = menuBar()->addMenu(tr("&Help"));
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View