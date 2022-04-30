#ifndef SDF_COMMON_META_DYNAMIC_TYPE_ENVIRONMENT_HPP
#define SDF_COMMON_META_DYNAMIC_TYPE_ENVIRONMENT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    dynamic_type_environment.hpp
// PURPOSE: Defines metaprogramming features to create a lambda environment where that the types of certain values can
//          be controlled dynamically at runtime.

#include <boost/hana/for_each.hpp>
#include <boost/hana/integral_constant.hpp>
#include <boost/hana/map.hpp>
#include <boost/hana/pair.hpp>
#include <boost/hana/type.hpp>
#include <functional>
#include <map>

// The lambda that is passed should have a parameter to receive the type value, which can be
// recovered via (if it's named "a_typ"), decltype(a_typ)::type.
template <class MapT, class EnumT, class LambdaT>
void dynamic_type_environment(const MapT &a_typeMap, EnumT a_typeSelector, LambdaT a_innerOp) {
    using namespace boost::hana;

    static std::map<EnumT, std::function<void()>> exec_map;
    if (exec_map.empty()) {
        for_each(typ_map,
                 [&](auto kvp) { exec_map[static_cast<EnumT>(first(kvp).value)] = [=]() { a_innerOp(second(kvp)); }; });
    }

    exec_map[a_typeSelector]();
}

// ease making a map into an enumerated traits struct
template <template <typename> typename TraitsT, typename EnumT>
constexpr decltype(auto) make_trait_pair(EnumT typeEnum) {
    return boost::hana::make_pair(boost::hana::int_c<typeEnum>, TraitsT<typeEnum>);
}

#endif  // SDF_COMMON_META_DYNAMIC_TYPE_ENVIRONMENT_HPP