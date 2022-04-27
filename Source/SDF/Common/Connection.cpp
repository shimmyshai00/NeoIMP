// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Connection.cpp
// PURPOSE: Implements the Connection class.

#include "Connection.hpp"

namespace SDF::Common
{
    Connection::Connection(IDisconnector *pa_disconnector, IConnectable *pa_connectable)
        : pm_disconnector(pa_disconnector), pm_connectable(pa_connectable)
    {
    }

    void Connection::disconnect()
    {
        if (pm_disconnector != nullptr)
        {
            pm_disconnector->disconnectConnectable(pm_connectable);
            pm_disconnector = nullptr;
        }
    }
} // namespace SDF::Common
