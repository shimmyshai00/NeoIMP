#ifndef SDF_COMMON_DATA_SIMPLEUIDGENERATOR_HPP
#define SDF_COMMON_DATA_SIMPLEUIDGENERATOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    SimpleUidGenerator.hpp
// PURPOSE: Defines the SimpleUidGenerator class.

#include <fruit/fruit.h>

#include <set>

#include "../Handle.hpp"
#include "IUidGenerator.hpp"

namespace SDF::Common::Data {
    // CLASS:   SimpleUidGenerator
    // PURPOSE: Defines a basic handle generator.
    class SimpleUidGenerator : public IUidGenerator {
       public:
        INJECT(SimpleUidGenerator());

        Handle getNextHandle() const;

        void retireHandle(Handle a_handle);

       private:
        mutable std::set<Common::Handle> m_usedHandles;
    };
}  // namespace SDF::Common::Data

#endif  // SDF_COMMON_DATA_SIMPLEUIDGENERATOR_HPP