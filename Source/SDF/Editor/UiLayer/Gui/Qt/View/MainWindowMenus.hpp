#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_MAINWINDOWMENUS_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_MAINWINDOWMENUS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MainWindowMenus.hpp
// PURPOSE: Defines the menus for the main window.

#include "MenuItemDef.hpp"

#include "MainWindow.hpp"

#include <QTranslator>
#include <QKeySequence>
#include <QString>
#include <QList>

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    typedef MainWindow MW;

    static const QList<MenuItemDef<MainWindow>> g_mainWindowFileMenu = {
        { MW::tr("&New..."), MW::tr("Create a new image document"), { }, nullptr },
        { MW::tr("E&xit"), MW::tr("Exit the program"), { }, &MainWindow::onExit }
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif // SDF_EDITOR_UILAYER_GUI_QT_VIEW_MAINWINDOWMENUS_HPP