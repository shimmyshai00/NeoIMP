#ifndef SDF_COMMON_HSM_IMPL_HSMSINGLETON_HPP
#define SDF_COMMON_HSM_IMPL_HSMSINGLETON_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmSingleton.hpp
// PURPOSE: Defines the HsmSingleton template.

#include "../../Singleton/Singleton.hpp"

namespace SDF::Common::Hsm::Impl {
    // CLASS:   HsmSingleton
    // PURPOSE: Defines the singleton used to instantiate an HSM leaf.
    template<class LeafT>
    struct HsmSingleton : public Singleton::Singleton<LeafT> {};
}  // namespace SDF::Common::Hsm::Impl

#endif // SDF_COMMON_HSM_IMPL_HSMSINGLETON_HPP