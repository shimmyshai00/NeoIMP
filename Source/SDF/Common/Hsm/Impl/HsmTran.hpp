#ifndef SDF_COMMON_HSM_IMPL_HSMTRAN_HPP
#define SDF_COMMON_HSM_IMPL_HSMTRAN_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    HsmTran.hpp
// PURPOSE: Defines the HsmTran template.

#include <type_traits>

#include "../HsmLeafState.hpp"
#include "HsmSingleton.hpp"

namespace SDF::Common::Hsm::Impl {
    // Transition *downward* from the non-leaf state FromT to the leaf state ToT. Note FromT must be an ancestor of
    // ToT. This is tricky because there are no downward-pointing links from FromT, which is also why we cannot use
    // this to do a non-leaf ToT. Hence, to perform this leg of the transition, we must first start at the bottom of
    // the tree, then recurse *up to* the upper node, then *on the unspool*, we call the enter() methods of each
    // parent class.
    template <class StageT, class FromT, class ToT, class T>
    struct TranDownwardHelper {
        static void tranEnter(T *a_hsm) {
            TranDownwardHelper<typename ToT::_parent_t, FromT, ToT, T>::tranEnter(a_hsm);
            a_hsm->m_curState = HsmSingleton<ToT>::getInstance();
            HsmSingleton<ToT>::getInstance()->StageT::enter(a_hsm);
        }
    };

    template <class FromT, class ToT, class T>
    struct TranDownwardHelper<FromT, FromT, ToT, T> {
        static void tranEnter(T *a_hsm) {}
    };

    template <class FromT, class ToT, class T>
    struct TranDownward {
        static void tranEnter(T *a_hsm) { TranDownwardHelper<ToT, FromT, ToT, T>::tranEnter(a_hsm); }
    };

    // Defines the special downward stroke used for a transition to a non-leaf state by transitioning to its default
    // states. Just as before, FromT must be an ancestor of ToT, but ToT need not be a leaf state.
    template <class FromT, class ToT, class T>
    struct TranDownwardByDefaults {
        static void tranEnter(T *a_hsm) {
            printf("default\n");

            // Here, we *do* have downward-pointing linkages from ToT.
            std::conditional<std::is_base_of<HsmLeafState<ToT>, typename ToT::Default>::value,
                             TranDownward<FromT, typename ToT::Default, T>,
                             TranDownwardByDefaults<FromT, typename ToT::Default, T>>::type::tranEnter(a_hsm);
        }
    };

    // Transition upward from FromT to its ancestor ToT (i.e. the part calling the exit() methods). This is easy
    // because upward-pointing links are always available. Note that no exit or enter method is called on ToT, because
    // we are "always in" it.
    template <class FromT, class ToT, class T>
    struct TranUpward {
        template <class StageU, class FromU, class ToU, class U>
        struct TranUpwardInner {
            static void tranExit(U *a_hsm) {
                HsmSingleton<FromU>::getInstance()->StageU::exit(a_hsm);
                TranUpwardInner<typename StageU::_parent_t, FromU, ToU, U>::tranExit(a_hsm);
            }
        };

        template <class FromU, class ToU, class U>
        struct TranUpwardInner<ToU, FromU, ToU, U> {
            static void tranExit(U *a_hsm) { printf("q9\n"); }
        };

        static void tranExit(T *a_hsm) { TranUpwardInner<FromT, FromT, ToT, T>::tranExit(a_hsm); }
    };

    // Finally, the main transition method: transition from the leaf FromT to an arbitrary ToT in the state tree.
    template <class FromT, class ToT, class T>
    struct HsmTran {
        static void execute(T *a_hsm) {
            typedef typename std::common_type<FromT, ToT>::type common_t;
            TranUpward<FromT, common_t, T>::tranExit(a_hsm);
            std::conditional<std::is_base_of<HsmLeafState<typename ToT::_parent_t>, ToT>::value,
                             TranDownward<common_t, ToT, T>,
                             TranDownwardByDefaults<common_t, ToT, T>>::type::tranEnter(a_hsm);
        }
    };
}  // namespace SDF::Common::Hsm::Impl

#endif  // SDF_COMMON_HSM_IMPL_HSMTRAN_HPP