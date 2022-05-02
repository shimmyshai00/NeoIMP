// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    SimpleUidGenerator.cpp
// PURPOSE: Implements the SimpleUidGenerator class.

#include "SimpleUidGenerator.hpp"

namespace SDF::Common::Data {
    SimpleUidGenerator::SimpleUidGenerator() {}

    Handle SimpleUidGenerator::getNextHandle() const {
        Handle freeHandle(0);
        while (m_usedHandles.find(freeHandle) != m_usedHandles.end()) {
            ++freeHandle;
        }

        m_usedHandles.insert(freeHandle);

        return freeHandle;
    }

    void SimpleUidGenerator::retireHandle(Handle a_handle) { m_usedHandles.erase(a_handle); }
}  // namespace SDF::Common::Data