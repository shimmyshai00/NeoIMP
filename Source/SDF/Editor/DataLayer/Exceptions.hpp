#ifndef SDF_EDITOR_DATALAYER_EXCEPTIONS_HPP
#define SDF_EDITOR_DATALAYER_EXCEPTIONS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Exceptions.hpp
// PURPOSE: Defines the exceptions that can be thrown out of the data layer.

#include "../../Common/Handle.hpp"
#include "../../Error/Exception.hpp"

namespace SDF::Editor::DataLayer {
    struct DataException : public Error::Exception {};

    struct InvalidHandleException : public Error::LikelyBug<DataException> {
        InvalidHandleException(Common::Handle a_handle) {
            whatPrintf("Tried to use an invalid domain object handle %u!", a_handle);
        }
    };

    struct ObjectNotFoundException : public Error::LikelyBug<DataException> {
        ObjectNotFoundException(Common::Handle a_handle) {
            whatPrintf("The domain object with handle %u was not found.", a_handle);
        }
    };

    struct IndexOutOfRangeException : public Error::LikelyBug<DataException> {
        IndexOutOfRangeException(std::size_t a_index, const char *a_whichColl) {
            whatPrintf("The index '%d' outstripped the range of the indexed collection '%s'.", a_index, a_whichColl);
        }
    };
}  // namespace SDF::Editor::DataLayer

#endif  // SDF_EDITOR_DATALAYER_EXCEPTIONS_HPP