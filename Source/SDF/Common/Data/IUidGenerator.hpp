#ifndef SDF_COMMON_DATA_IUIDGENERATOR_HPP
#define SDF_COMMON_DATA_IUIDGENERATOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IUidGenerator.hpp
// PURPOSE: Defines the IUidGenerator interface.

#include "../Handle.hpp"

namespace SDF::Common::Data {
    // CLASS:   IUidGenerator
    // PURPOSE: Defines an interface for generating unique object handles.
    class IUidGenerator {
       public:
        virtual ~IUidGenerator() = default;

        // FUNCTION: getNextHandle
        // PURPOSE:  Gets the next available handle.
        // NOTES:    None.
        virtual Handle getNextHandle() const = 0;

        // FUNCTION: retireHandle
        // PURPOSE:  Signals the generator that a handle is no longer being used so it can be reclaimed.
        // NOTES:    None.
        virtual void retireHandle(Handle a_handle) = 0;
    };
}  // namespace SDF::Common::Data

#endif  // SDF_COMMON_DATA_IUIDGENERATOR_HPP