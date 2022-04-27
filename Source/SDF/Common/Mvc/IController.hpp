#ifndef SDF_COMMON_MVC_ICONTROLLER_HPP
#define SDF_COMMON_MVC_ICONTROLLER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IController.hpp
// PURPOSE: Defines the IController interface.

namespace SDF::Common::Mvc
{
    // CLASS:   IController
    // PURPOSE: Defines the interface for MVC controllers. An MVC controller is an event handler to be hooked to a UI
    //          element, or View.
    template <class... Args> class IController
    {
      public:
        virtual ~IController() = default;

        // FUNCTION: onTriggered
        // PURPOSE:  Called when the controller is triggered.
        // NOTES:    None.
        virtual void onTriggered(Args... as_args) = 0;
    };
} // namespace SDF::Common::Mvc

#endif // SDF_COMMON_MVC_ICONTROLLER_HPP