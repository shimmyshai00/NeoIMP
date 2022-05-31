#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_ENUMLISTMODEL_TPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_ENUMLISTMODEL_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    EnumListModel.tpp
// PURPOSE: Implements the EnumListModel template.

namespace SDF::Editor::UiLayer::Gui::Qt::View {
    template <class E, E MaxVal>
    EnumListModel<E, MaxVal>::EnumListModel(std::initializer_list<QPair<E, QString>> a_mapping)
        : EnumListModel(a_mapping, [](bool b_item) { return true; }) {}

    template <class E, E MaxVal>
    EnumListModel<E, MaxVal>::EnumListModel(std::initializer_list<QPair<E, QString>> a_mapping,
                                            std::function<bool(E)> a_filter) {
        for (auto it = a_mapping.begin(); it != a_mapping.end(); ++it) {
            if (a_filter(it->first)) {
                m_dataMap[it->first] = m_stringList.size();
                m_stringList.push_back(it->second);
            }
        }
    }

    template <class E, E MaxVal>
    EnumListModel<E, MaxVal>::EnumListModel(const EnumListModel &a_elm, std::function<bool(E)> a_filter) {
        for (auto key : a_elm.m_dataMap.keys()) {
            if (a_filter(key)) {
                m_dataMap[key] = m_stringList.size();
                m_stringList.push_back(a_elm.m_stringList[a_elm.m_dataMap[key]]);
            }
        }
    }

    template <class E, E MaxVal>
    int EnumListModel<E, MaxVal>::rowCount(const QModelIndex &parent) const {
        if (parent == QModelIndex()) {
            return m_stringList.size();
        } else {
            return 0;
        }
    }

    template <class E, E MaxVal>
    QVariant EnumListModel<E, MaxVal>::data(const QModelIndex &index, int role) const {
        if (index.row() < m_stringList.size()) {
            return tr(m_stringList[index.row()].toStdString().c_str());
        } else {
            return "";
        }
    }

    template <class E, E MaxVal>
    QVariant EnumListModel<E, MaxVal>::headerData(int section, ::Qt::Orientation orientation, int role) const {
        return "";
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_ENUMLISTMODEL_TPP