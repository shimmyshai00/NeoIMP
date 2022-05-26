#ifndef SDF_COMMON_HSM_HSM_TPP
#define SDF_COMMON_HSM_HSM_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Hsm.tpp
// PURPOSE: Implements the Hsm template.

#include "Impl/HsmTran.hpp"

namespace SDF::Common::Hsm {
    template<class Input, class T>
    Hsm<Input, T>::Hsm() : m_curState(nullptr) {}

    template<class Input, class T>
    Hsm<Input, T>::~Hsm() {}

    template<class Input, class T>
    template<class RootT>
    void Hsm<Input, T>::beginHsm() {
        printf("beginning HSM\n");
        Impl::HsmTran<RootT, RootT, T>::execute(static_cast<T *>(this));
    }

    template<class Input, class T>
    void Hsm<Input, T>::stimulate(const Input &a_input) {
        m_curState->processInput(static_cast<_hsm_t *>(this), a_input);
    }
}  // namespace SDF::Common::Hsm

#endif // SDF_COMMON_HSM_HSM_TPP