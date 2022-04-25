#ifndef SDF_COMMON_CONNECTION_HPP
#define SDF_COMMON_CONNECTION_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Connection.hpp
// PURPOSE: Defines the Connection class.

#include "IDisconnector.hpp"
#include "IConnectable.hpp"

namespace SDF::Common {
    // CLASS:   Connection
    // PURPOSE: Defines a connection handle for NeoIMP connectable objects to permit their disconnection after registry.
    class Connection {
       public:
        // FUNCTION: Connection
        // PURPOSE:  Constructs a new connection.
        // NOTES:    This function is NOT to be used by user code. IConnectable interfaces should NOT be publicly
        //           exposed.
        Connection(IDisconnector *pa_disconnector, IConnectable *pa_connectable);

        // FUNCTION: disconnect
        // PURPOSE:  Disconnects the connection.
        // NOTES:    None.
        void disconnect();

       private:
        IDisconnector *pm_disconnector;
        IConnectable *pm_connectable;
    };
}  // namespace SDF::Common

#endif  // SDF_COMMON_CONNECTION_HPP