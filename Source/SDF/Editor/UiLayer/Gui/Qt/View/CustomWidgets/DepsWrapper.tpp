#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DEPSWRAPPER_TPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DEPSWRAPPER_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    DepsWrapper.tpp
// PURPOSE: Implements the DepsWrapper template.

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    template <class... Ss>
    DepsWrapper<Ss...>::DepsWrapper() {}

    template <class... Ss>
    DepsWrapper<Ss...>::DepsWrapper(Common::Mvc::ServicePack<Ss...> a_deps)
        : m_services(new Common::Mvc::ServicePack<Ss...>(a_deps)) {}

    template <class... Ss>
    bool DepsWrapper<Ss...>::areDepsAvailable() const {
        return m_services;
    }

    template <class... Ss>
    Common::Mvc::ServicePack<Ss...> *DepsWrapper<Ss...>::pack() {
        return m_services.get();
    }

    template <class... Ss>
    const Common::Mvc::ServicePack<Ss...> *DepsWrapper<Ss...>::pack() const {
        return m_services.get();
    }
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DEPSWRAPPER_TPP