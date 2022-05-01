#ifndef SDF_COMMON_VISITOR_IACYCLICVISITOR_HPP
#define SDF_COMMON_VISITOR_IACYCLICVISITOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IAcyclicVisitor.hpp
// PURPOSE: Defines the IAcyclicVisitor interface.

#include "IAcyclicRootVisitor.hpp"

namespace SDF::Common::Visitor {
    // CLASS:   IAcyclicVisitor
    // PURPOSE: Defines an interface for a node of an acyclic visitor.
    template <class RootT, class ObjT>
    class IAcyclicVisitor : public IAcyclicRootVisitor<RootT> {
       public:
        virtual ~IAcyclicVisitor() = default;

        // FUNCTION: visit
        // PURPOSE:  Visits an object.
        // NOTES:    None.
        virtual void visit(ObjT &obj) = 0;
    };
}  // namespace SDF::Common::Visitor

#endif
