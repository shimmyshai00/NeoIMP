#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_MAINWINDOW_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_MAINWINDOW_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindow.hpp
// PURPOSE: Defines the MainWindow class.

#include <QGridLayout>
#include <QKeySequence>
#include <QList>
#include <QMainWindow>
#include <QMenu>
#include <QString>

#include "../MvcAdapter/QtView.hpp"
#include "MenuItemDef.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // CLASS:   MainWindow
    // PURPOSE: Defines the Qt main window.
    class MainWindow : public MvcAdapter::QtView<QMainWindow> {
        Q_OBJECT
       public:
        MainWindow();

       private:
        void addMenuItem(QMenu *a_menu,
                         QString a_caption,
                         QString a_statusTip,
                         const QList<QKeySequence> &a_shortcuts,
                         void (MainWindow::*a_signalFunc)());

        void createMenus();

        QGridLayout *m_centralLayout;

        QMenu *m_fileMenu;
        QMenu *m_editMenu;
        QMenu *m_imageMenu;
        QMenu *m_layerMenu;
        QMenu *m_selectMenu;
        QMenu *m_filterMenu;
        QMenu *m_viewMenu;
        QMenu *m_windowMenu;
        QMenu *m_helpMenu;

       signals:
        // File
        void onExit();

        // Edit

        // View

        // Image

        // Layer

        // Select

        // Filter

        // Help
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_MAINWINDOW_HPP