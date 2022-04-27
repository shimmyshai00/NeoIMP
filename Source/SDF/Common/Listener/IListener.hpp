#ifndef SDF_COMMON_LISTENER_ILISTENER_HPP
#define SDF_COMMON_LISTENER_ILISTENER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IListener.hpp
// PURPOSE: Defines the IListener interface.

#include "../IConnectable.hpp"

namespace SDF::Common::Listener
{
    // CLASS:   IListener
    // PURPOSE: Defines an interface for generic listeners.
    template <class... Args> class IListener : public IConnectable
    {
      public:
        virtual ~IListener() = default;

        // FUNCTION: notify
        // PURPOSE:  Notifies the listener of an event.
        // NOTES:    None.
        virtual void notify(Args... as_args) = 0;
    };
} // namespace SDF::Common::Listener

#endif // SDF_COMMON_LISTENER_ILISTENER_HPP