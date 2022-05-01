#ifndef SDF_COMMON_VISITOR_IACYCLICCONSTVISITOR_HPP
#define SDF_COMMON_VISITOR_IACYCLICCONSTVISITOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IAcyclicConstVisitor.hpp
// PURPOSE: Defines the IAcyclicConstVisitor interface.

#include "IAcyclicRootVisitor.hpp"

namespace SDF::Common::Visitor {
    // CLASS:   IAcyclicConstVisitor
    // PURPOSE: Defines a const version of IAcyclicVisitor.
    template <class RootT, class ObjT>
    class IAcyclicConstVisitor : public IAcyclicRootVisitor<RootT> {
       public:
        virtual ~IAcyclicConstVisitor() = default;

        // FUNCTION: visit
        // PURPOSE:  Visits an object.
        // NOTES:    None.
        virtual void visit(const ObjT &obj) = 0;
    };
}  // namespace SDF::Common::Visitor

#endif
