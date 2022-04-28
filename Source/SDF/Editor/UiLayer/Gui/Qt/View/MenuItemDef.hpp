#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_MENUITEMDEF_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_MENUITEMDEF_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    MenuItemDef.hpp
// PURPOSE: Defines a struct for specifying prototypes for menu items.

#include <QKeySequence>
#include <QList>
#include <QString>

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    template <class QWidgetT>
    struct MenuItemDef {
        QString name;
        QString statusTip;
        QList<QKeySequence> shortcuts;
        void (QWidgetT::*triggerFuncPtr)();
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_MENUITEMDEF_HPP