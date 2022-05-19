#ifndef SDF_COMMON_HSM_HSMINNERSTATE_HPP
#define SDF_COMMON_HSM_HSMINNERSTATE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmInnerState.hpp
// PURPOSE: Defines the HsmInnerState base template.

namespace SDF::Common::Hsm {
    // CLASS:   HsmInnerState
    // PURPOSE: Defines a base template for an inner (i.e. not a leaf, or valid, but not the root) substate of the HSM.
    template <class ParentT>
    class HsmInnerState : public ParentT {
       public:
        typedef ParentT _parent_t;
        typedef typename ParentT::_hsm_t _hsm_t;
        typedef typename ParentT::_input_t _input_t;
    };
}  // namespace SDF::Common::Hsm

#endif  // SDF_COMMON_HSM_HSMINNERSTATE_HPP