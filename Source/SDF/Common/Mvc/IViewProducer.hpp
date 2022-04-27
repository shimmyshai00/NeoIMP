#ifndef SDF_COMMON_MVC_IVIEWPRODUCER_HPP
#define SDF_COMMON_MVC_IVIEWPRODUCER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IViewProducer.hpp
// PURPOSE: Defines the IViewProducer interface.

namespace SDF::Common::Mvc {
    // CLASS:   IViewProducer
    // PURPOSE: Defines an interface for requesting creation of a new view by a controller.
    template <class... Args>
    class IViewProducer {
       public:
        virtual ~IViewProducer() = default;

        // FUNCTION: requestView
        // PURPOSE:  Request the creation of the view.
        // NOTES:    The class below allows this method to return an interface for interacting with the new view. The
        //           view itself should not be returned to the Controller because it typically depends on the widget
        //           libraries being employed and we don't want to leak those 3rd party implementation choices into the
        //           Controller subsystem of the MVC pattern.
        virtual void requestView(Args... as_args) = 0;
    };

    template <class ReturnIface, class... Args>
    class AInteractiveViewProducer : public IViewProducer<ReturnIface, Args...> {
       public:
        virtual ~AInteractiveViewProducer() = default;

        virtual ReturnIface *requestInteractiveView(Args... as_args) = 0;

        // just discard the interface, so we can adapt one to the other
        void requestView(Args... as_args) { requestInteractiveView(as_args...); }
    };
}  // namespace SDF::Common::Mvc

#endif  // SDF_COMMON_MVC_IVIEWPRODUCER_HPP