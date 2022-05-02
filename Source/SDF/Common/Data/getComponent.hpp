#ifndef SDF_COMMON_DATA_GETCOMPONENT_HPP
#define SDF_COMMON_DATA_GETCOMPONENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    getComponent.hpp
// PURPOSE: Defines the DI component for the common data layer facilities.

#include <fruit/fruit.h>

#include "IUidGenerator.hpp"

namespace SDF::Common::Data {
    typedef fruit::Component<IUidGenerator> Component;

    Component getComponent();
}  // namespace SDF::Common::Data

#endif // SDF_COMMON_DATA_GETCOMPONENT_HPP