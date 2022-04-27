#ifndef SDF_COMMON_IDISCONNECTOR_HPP
#define SDF_COMMON_IDISCONNECTOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IDisconnector.hpp
// PURPOSE: Defines the IDisconnector interface.

#include "IConnectable.hpp"

namespace SDF::Common {
    // CLASS:   IDisconnector
    // PURPOSE: Defines an interface for disconnecting an IConnectable from an object (this is usually an interface to
    //          that object).
    class IDisconnector {
       public:
        virtual ~IDisconnector() = default;

        // FUNCTION: disconnectConnectable
        // PURPOSE:  Disconnects an IConnectable from this object.
        // NOTES:    If the IConnectable is already disconnected, does nothing.
        virtual void disconnectConnectable(IConnectable *pa_connectable) = 0;
    };
}  // namespace SDF::Common

#endif  // SDF_COMMON_IDISCONNECTOR_HPP