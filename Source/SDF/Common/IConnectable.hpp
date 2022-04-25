#ifndef SDF_COMMON_ICONNECTABLE_HPP
#define SDF_COMMON_ICONNECTABLE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IConnectable.hpp
// PURPOSE: Defines the IConnectable interface.

namespace SDF::Common {
    // CLASS:   IConnectable
    // PURPOSE: Defines an interface for objects that can be connected to others to produce a Connection handle.
    class IConnectable {
       public:
        virtual ~IConnectable() = 0;

        // the interface itself is null; just meant to serve as a reference.
    };
}  // namespace SDF::Common

#endif  // SDF_COMMON_ICONNECTABLE_HPP