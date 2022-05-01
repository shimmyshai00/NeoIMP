#ifndef SDF_COMMON_VISITOR_AACYCLICVISITABLE_HPP
#define SDF_COMMON_VISITOR_AACYCLICVISITABLE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    AAcyclicVisitable.hpp
// PURPOSE: Defines the AAcyclicVisitable base class.

#include "IAcyclicConstVisitor.hpp"
#include "IAcyclicRootVisitor.hpp"
#include "IAcyclicVisitable.hpp"
#include "IAcyclicVisitor.hpp"

namespace SDF::Common::Visitor {
    // CLASS:   AAcyclicVisitable
    // PURPOSE: Defines a base mixin for visitable objects using an acyclic visitor.
    template <class RootT, class ObjT>
    class AAcyclicVisitable : public IAcyclicVisitable<RootT> {
       public:
        virtual ~AAcyclicVisitable() = 0;

        void accept(IAcyclicRootVisitor<RootT> &a_visitor) {
            if (auto *p = dynamic_cast<IAcyclicVisitor<RootT, ObjT> *>(&a_visitor)) {
                p->visit(static_cast<ObjT *>(this));
            }
        }

        void accept(IAcyclicRootVisitor<RootT> &a_visitor) const {
            if (auto *p = dynamic_cast<IAcyclicConstVisitor<RootT, ObjT> *>(&a_visitor)) {
                p->visit(static_cast<const ObjT *>(this));
            }
        }
    };

    template <class RootT, class ObjT>
    AAcyclicVisitable<RootT, ObjT>::~AAcyclicVisitable() {}
}  // namespace SDF::Common::Visitor

#endif
