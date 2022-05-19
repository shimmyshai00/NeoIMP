#ifndef SDF_COMMON_HSM_HSM_HPP
#define SDF_COMMON_HSM_HSM_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Hsm.hpp
// PURPOSE: Defines the Hsm template.

#include "HsmRootState.hpp"

namespace SDF::Common::Hsm {
    // CLASS:   Hsm
    // PURPOSE: Defines a base for hierarchical finite state machines (HSMs). An HSM is like an FSM except that the
    //          states themselves are, in effect, FSMs (although not exactly - they need not be closed under 
    //          transitions), which allows for a neat and powerful representation of things like GUIs where that
    //          the state of a particular widget may affect others in just such a nested manner (for example, enabling
    //          a combo box that then enables/disables other widgets, resulting in a 2-level hierarchy of states). This
    //          code is a modernized version of that described in https://state-machine.com/doc/Heinzmann04.pdf, which
    //          was written before the advent of powerful C++ metaprogramming facilities. This version leverages the
    //          latest in C++ and Boost to deliver a sleek and clean HSM implementation for NeoIMP.
    template<class Input, class T>
    class Hsm {
       public:
        typedef T _hsm_t;
        typedef Input _input_t;
       public:
        Hsm();
        virtual ~Hsm() = 0;

        // FUNCTION: beginHsm
        // PURPOSE:  Initiates the HSM to its initial state.
        // NOTES:    The initial state is the default starting from the passed template root, which should be the root
        //           of your HSM's state hierarchy.
        template<class RootT>
        void beginHsm();

        // FUNCTION: stimulate
        // PURPOSE:  Stimulates the HSM with a given input.
        // NOTES:    None.
        void stimulate(Input a_input);
       private:
        const HsmRootState<T> *m_curState;
    };
}  // namespace SDF::Common::Hsm

#include "Hsm.tpp"

#endif // SDF_COMMON_HSM_HSM_HPP