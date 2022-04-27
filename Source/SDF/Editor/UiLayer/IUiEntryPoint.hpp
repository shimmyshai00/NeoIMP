#ifndef SDF_EDITOR_UILAYER_IUIENTRYPOINT_HPP
#define SDF_EDITOR_UILAYER_IUIENTRYPOINT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IUiEntryPoint.hpp
// PURPOSE: Defines the IUiEntryPoint interface.

namespace SDF::Editor::UiLayer
{
    // CLASS:   IUiEntryPoint
    // PURPOSE: Defines an entry point interface for starting an editor's user interface.
    class IUiEntryPoint
    {
      public:
        virtual ~IUiEntryPoint() = default;

        // FUNCTION: startUi
        // PURPOSE:  Starts the UI.
        // NOTES:    None.
        virtual void startUi() = 0;
    };
} // namespace SDF::Editor::UiLayer

#endif // SDF_EDITOR_UILAYER_IUIENTRYPOINT_HPP