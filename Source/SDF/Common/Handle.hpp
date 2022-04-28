#ifndef SDF_COMMON_HANDLE_HPP
#define SDF_COMMON_HANDLE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Handle.hpp
// PURPOSE: Defines the data type for handles.

#include <limits>

namespace SDF::Common {
    typedef unsigned int Handle;

    static constexpr Handle HANDLE_INVALID = std::numeric_limits<Handle>::max();
}  // namespace SDF::Common

#endif // SDF_COMMON_HANDLE_HPP