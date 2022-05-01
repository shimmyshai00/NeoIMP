#ifndef SDF_COMMON_VISITOR_IACYCLICVISITABLE_HPP
#define SDF_COMMON_VISITOR_IACYCLICVISITABLE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IAcyclicVisitable.hpp
// PURPOSE: Defines the IAcyclicVisitable interface.

#include "IAcyclicRootVisitor.hpp"

namespace SDF::Common::Visitor {
    // CLASS:   IAcyclicVisitable
    // PURPOSE: Defines an interface for visitable objects. This is meant to implement the "acyclic visitor" approach
    //          described in https://condor.depaul.edu/dmumaugh/OOT/Design-Principles/acv.pdf. This visitor style should
    //          be used if we expect to be continually adding new kinds of visitables. The drawback is there is a
    //          dynamic_cast involved, which can be slow if visitation must be made frequently and the visits are cheap.
    template <class RootT>
    class IAcyclicVisitable {
       public:
        virtual ~IAcyclicVisitable() = default;

        // FUNCTION: accept
        // PURPOSE:  Accepts a visitor into the object.
        // NOTES:    None.
        virtual void accept(IAcyclicRootVisitor<RootT> &a_visitor) = 0;

        virtual void accept(IAcyclicRootVisitor<RootT> &a_visitor) const = 0;
    };
}  // namespace SDF::Common::Visitor

#endif
