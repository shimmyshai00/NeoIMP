#ifndef SDF_COMMON_EXCEPTIONS_HPP
#define SDF_COMMON_EXCEPTIONS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Exceptions.hpp
// PURPOSE: Defines the exceptions that can be thrown from the common library.

#include "../Error/Exception.hpp"

namespace SDF::Common {
    struct CommonException : Error::Exception {};

    struct DuplicateListenerException : Error::LikelyBug<CommonException> {
        DuplicateListenerException() { whatPrintf("Tried to add duplicate of listener to container"); }
    };
}  // namespace SDF::Common

#endif  // SDF_COMMON_EXCEPTIONS_HPP
