#ifndef SDF_EDITOR_UILAYER_GUI_CONTROLLER_IUITERMINATOR_HPP
#define SDF_EDITOR_UILAYER_GUI_CONTROLLER_IUITERMINATOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IUiTerminator.hpp
// PURPOSE: Defines the IUiTerminator interface.

namespace SDF::Editor::UiLayer::Gui::Controller {
    // CLASS:   IUiTerminator
    // PURPOSE: Defines an interface to terminate the UI.
    class IUiTerminator {
       public:
        virtual ~IUiTerminator() = default;

        virtual void terminateUi() = 0;
    };
}  // namespace SDF::Editor::UiLayer::Gui::Controller

#endif  // SDF_EDITOR_UILAYER_GUI_CONTROLLER_IUITERMINATOR_HPP