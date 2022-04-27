#ifndef SDF_EDITOR_UILAYER_GUI_ENTRYPOINT_HPP
#define SDF_EDITOR_UILAYER_GUI_ENTRYPOINT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    EntryPoint.hpp
// PURPOSE: Defines the EntryPoint class.

#include "../../../Common/Mvc/IViewProducer.hpp"

#include "../IUiEntryPoint.hpp"

#include <fruit/fruit.h>

namespace SDF::Editor::UiLayer::Gui {
    // CLASS:   EntryPoint
    // PURPOSE: Defines the entry point for the GUI.
    class EntryPoint : public IUiEntryPoint {
       public:
        INJECT(EntryPoint(Common::Mvc::IViewProducer<> *a_mainWindowProducer));

        void startUi();
       private:
        Common::Mvc::IViewProducer<> *m_mainWindowProducer;
    };
}  // namespace SDF::Editor::UiLayer::Gui

#endif  // SDF_EDITOR_UILAYER_GUI_ENTRYPOINT_HPP