#ifndef SDF_COMMON_MVC_SERVICEPACK_TPP
#define SDF_COMMON_MVC_SERVICEPACK_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ServicePack.tpp
// PURPOSE: Implements the ServicePack template.

#include <boost/mp11/integral.hpp>
#include <boost/mp11/list.hpp>
#include <boost/mp11/algorithm.hpp>

namespace SDF::Common::Mvc {
    template <class... Ss>
    ServicePack<Ss...>::ServicePack(Ss *...as_services) : m_serviceTuple(as_services...) {}

    template <class... Ss>
    template <class... Supers>
    ServicePack<Ss...>::ServicePack(const ServicePack<Supers...> &superPack)
        : m_serviceTuple(std::get<boost::mp11::mp_find<typename ServicePack<Supers...>::tuple_t, Ss *>::value>(
              superPack.m_serviceTuple)...) {}

    template <class... Ss>
    template <class S>
    S *ServicePack<Ss...>::get() const {
        return std::get<boost::mp11::mp_find<tuple_t, S *>::value>(m_serviceTuple);
    }
}  // namespace SDF::Common::Mvc

#endif  // SDF_COMMON_MVC_SERVICEPACK_TPP