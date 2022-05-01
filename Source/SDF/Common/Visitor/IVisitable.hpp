#ifndef SDF_COMMON_VISITOR_IVISITABLE_HPP
#define SDF_COMMON_VISITOR_IVISITABLE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IVisitable.hpp
// PURPOSE: Defines the IVisitable interface.

namespace SDF::Common::Visitor {
    // CLASS:   IVisitable
    // PURPOSE: Defines an interface for classically visitable objects, using a classical visitor pattern. This should
    //          only be used when we are sure that we are not going to be adding more visitables in the future.
    template <class VisitorIfaceT>
    class IVisitable {
       public:
        virtual ~IVisitable() = default;

        // FUNCTION: accept
        // PURPOSE:  Accepts a visitor into the visitable object.
        // NOTES:    None.
        virtual void accept(VisitorIfaceT &a_visitor) = 0;

        virtual void accept(VisitorIfaceT &a_visitor) const = 0;
    };
}  // namespace SDF::Common::Visitor

#endif
