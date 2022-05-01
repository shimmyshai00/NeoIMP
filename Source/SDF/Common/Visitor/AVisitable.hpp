#ifndef SDF_COMMON_VISITOR_AVISITABLE_HPP
#define SDF_COMMON_VISITOR_AVISITABLE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    AVisitable.hpp
// PURPOSE: Defines the AVisitable base class.

#include "IVisitable.hpp"

namespace SDF::Common::Visitor {
    // CLASS:   AVisitable
    // PURPOSE: Defines the mixin for classically visitable objects.
    template <class VisitorIfaceT, class ObjT>
    class AVisitable : public IVisitable<VisitorIfaceT> {
       public:
        virtual ~IVisitable() = default;

        void accept(VisitorIfaceT &a_visitor) { a_visitor.visit(static_cast<ObjT *>(this)); }

        void accept(VisitorIfaceT &a_visitor) const { a_visitor.visit(static_cast<const ObjT *>(this)); }
    };
}  // namespace SDF::Common::Visitor

#endif
