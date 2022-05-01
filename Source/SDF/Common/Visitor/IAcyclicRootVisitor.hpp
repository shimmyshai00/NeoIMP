#ifndef SDF_COMMON_VISITOR_IROOTVISITOR_HPP
#define SDF_COMMON_VISITOR_IROOTVISITOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IAcyclicRootVisitor.hpp
// PURPOSE: Defines the IAcyclicRootVisitor interface.

namespace SDF::Common::Visitor {
    // CLASS:   IAcyclicRootVisitor
    // PURPOSE: Defines an interface for the root of an acyclic object visitor.
    template <class RootT>
    class IAcyclicRootVisitor {
       public:
        virtual ~IAcyclicRootVisitor() = 0;  // prevent instantiation
    };

    template <class RootT>
    IAcyclicRootVisitor<RootT>::~IAcyclicRootVisitor() {}
}  // namespace SDF::Common::Visitor

#endif
