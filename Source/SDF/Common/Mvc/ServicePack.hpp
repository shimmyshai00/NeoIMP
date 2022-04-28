#ifndef SDF_COMMON_MVC_SERVICEPACK_HPP
#define SDF_COMMON_MVC_SERVICEPACK_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ServicePack.hpp
// PURPOSE: Defines a pack for holding MVC model layer service dependencies.

#include <fruit/fruit.h>

#include <boost/mp11/algorithm.hpp>
#include <tuple>

namespace SDF::Common::Mvc {
    // CLASS:   ServicePack
    // PURPOSE: Provides a type-referenced container of types meant to be dependency-injected (DI) as services from a
    //          model layer. This allows to bundle together the dependency requirements for a UI layer client without
    //          having to respecify them again in DI components and especially factories.
    template <class... Ss>
    class ServicePack {
       public:
        INJECT(ServicePack(Ss *...as_services));

        // Obtains a subset of a service pack.
        template <class... Supers>
        ServicePack(const ServicePack<Supers...> &superPack);

        template <class S>
        S *get() const;

       private:
        typedef std::tuple<Ss *...> tuple_t;
        tuple_t m_serviceTuple;

        template <class... Ts>
        friend class ServicePack;  // nb: hackish
    };

    // ... aaaaaand for pooling dependencies, I found Boost::Mp11 to have some real gems!
    template <class... Packs>
    using UnionPack = boost::mp11::mp_apply<ServicePack, boost::mp11::mp_set_union<Packs...>>;
}  // namespace SDF::Common::Mvc

#include "ServicePack.tpp"

#endif  // SDF_COMMON_MVC_SERVICEPACK_HPP