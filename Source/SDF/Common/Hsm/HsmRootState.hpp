#ifndef SDF_COMMON_HSM_HSMROOTSTATE_HPP
#define SDF_COMMON_HSM_HSMROOTSTATE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmRootState.hpp
// PURPOSE: Defines the HsmRootState base template.

#include "Impl/HsmTran.hpp"

namespace SDF::Common::Hsm {
    // CLASS:   HsmRootState
    // PURPOSE: Defines a base template for the root state of the HSM. Each HSM state is expected to be stateless. Non-
    //          leaf ("non-valid") states are not instantiated, but only members of the inheritance hierarchy. Moreover,
    //          each non-leaf state must have a default substate, which is obtained by supplying a class typedef in
    //          the inheritance with the type name "Default", e.g. "typedef class MyDerivedState1 Default;".
    template <class T>
    class HsmRootState {
       public:
        // attributes for the implementation to make it easier to traverse the tree
        typedef void _parent_t;
        typedef typename T::_hsm_t _hsm_t;
        typedef typename T::_input_t _input_t;

       public:
        virtual ~HsmRootState() = 0;

        // FUNCTION: processInput
        // PURPOSE:  Processes a given input and transitions if needed.
        // NOTES:    None.
        virtual void processInput(_hsm_t *a_hsm, const _input_t &a_input) const {}

        // FUNCTION: enter
        // PURPOSE:  Performs all the necessary start-up for state entry.
        // NOTES:    Note that HSM states are expected to be stateless objects - this is why we pass a copy of the HSM
        //           object. Any other state that needs modification during transition should be kept there. Also note
        //           that with the current transition implementation the enter/exit methods of your root state will not
        //           be processed because it in effect assumes the HSM is always in that state inherently and it saves
        //           a little extra special case handling, so you should not override these methods for the root, only
        //           the states derived from it.
        virtual void enter(_hsm_t *a_hsm) const {}

        // FUNCTION: exit
        // PURPOSE:  Performs all the necessary tear-down for state exit.
        // NOTES:    Same as for enter().
        virtual void exit(_hsm_t *a_hsm) const {}

       protected:
        // FUNCTION: hsmTran
        // PURPOSE:  Performs a transition of the HSM from one state to another.
        // NOTES:    None.
        template <class ThisT, class DestStateT>
        void hsmTran(_hsm_t *a_hsm) const {
            Impl::HsmTran<ThisT, DestStateT, T>::execute(a_hsm);
        }
    };

    template <class T>
    HsmRootState<T>::~HsmRootState() {}
}  // namespace SDF::Common::Hsm

#endif  // SDF_COMMON_HSM_HSMROOTSTATE_HPP