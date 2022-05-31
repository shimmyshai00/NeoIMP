#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_ENUMLISTMODEL_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_ENUMLISTMODEL_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    EnumListModel.hpp
// PURPOSE: Defines the EnumListModel template.

#include <QAbstractListModel>
#include <QList>
#include <QMap>
#include <QModelIndex>
#include <QPair>
#include <QString>
#include <QVariant>
#include <functional>

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    // CLASS:   EnumListModel
    // PURPOSE: Defines a Qt view model for adapting and mapping enum values to combo/list values with automatic
    //          translation mapping.
    template <class E, E MaxVal>
    class EnumListModel : public QAbstractListModel {
       public:
        EnumListModel(std::initializer_list<QPair<E, QString>> a_mapping);
        EnumListModel(std::initializer_list<QPair<E, QString>> a_mapping, std::function<bool(E)> a_filter);
        EnumListModel(const EnumListModel &a_elm, std::function<bool(E)> a_filter);

        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = ::Qt::DisplayRole) const;
        QVariant headerData(int section, ::Qt::Orientation orientation, int role = ::Qt::DisplayRole) const;

       private:
        QMap<E, int> m_dataMap;
        QList<QString> m_stringList;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#include "EnumListModel.tpp"

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_ENUMLISTMODEL_HPP