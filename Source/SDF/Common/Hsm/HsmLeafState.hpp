#ifndef SDF_COMMON_HSM_HSMLEAFSTATE_HPP
#define SDF_COMMON_HSM_HSMLEAFSTATE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmLeafState.hpp
// PURPOSE: Defines the HsmLeafState base template.

namespace SDF::Common::Hsm {
    // CLASS:   HsmLeafState
    // PURPOSE: Defines a base template for a leaf substate of the HSM.
    template <class ParentT>
    class HsmLeafState : public ParentT {
       public:
        typedef ParentT _parent_t;
        typedef typename ParentT::_hsm_t _hsm_t;
        typedef typename ParentT::_input_t _input_t;
    };
}  // namespace SDF::Common::Hsm

#endif  // SDF_COMMON_HSM_HSMLEAFSTATE_HPP