// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.cpp
// PURPOSE: Implements the DI component for the common data layer facilities.

#include "getComponent.hpp"

#include "SimpleUidGenerator.hpp"

namespace SDF::Common::Data {
    Component getComponent() { return fruit::createComponent().bind<IUidGenerator, SimpleUidGenerator>(); }
}  // namespace SDF::Common::Data
