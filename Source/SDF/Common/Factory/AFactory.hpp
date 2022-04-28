#ifndef SDF_COMMON_FACTORY_AFACTORY_HPP
#define SDF_COMMON_FACTORY_AFACTORY_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    AFactory.hpp
// PURPOSE: Defines the AFactory base type.

#include <memory>

namespace SDF::Common::Factory {
    // CLASS:   IFactoryP/U/S
    // PURPOSE: Defines an interface for factory objects (objects whose purpose is to create other objects). Each
    //          interface returns a different kind of pointer reflecting different ownership management methods.
    template <class ObjT, class... ConstructionArgs>
    class IFactoryP {
       public:
        virtual ~IFactoryP() = default;

        // FUNCTION: create
        // PURPOSE:  Creates a new object instance.
        // NOTES:    None.
        virtual ObjT *createP(ConstructionArgs... as_args) = 0;
    };

    template <class ObjT, class... ConstructionArgs>
    class IFactoryU {
       public:
        virtual ~IFactoryU() = default;

        virtual std::unique_ptr<ObjT> createU(ConstructionArgs... as_args) = 0;
    };

    template <class ObjT, class... ConstructionArgs>
    class IFactoryS {
       public:
        virtual ~IFactoryS() = default;

        virtual std::shared_ptr<ObjT> createS(ConstructionArgs... as_args) = 0;
    };

    // CLASS:   AFactory
    // PURPOSE: Defines an abstract base for factories.
    template <class ObjT, class... ConstructionArgs>
    class AFactory : public IFactoryP<ObjT, ConstructionArgs...>,
                     public IFactoryU<ObjT, ConstructionArgs...>,
                     public IFactoryS<ObjT, ConstructionArgs...> {
       public:
        virtual ~AFactory() = default;

        std::unique_ptr<ObjT> createU(ConstructionArgs... as_args) {
            return std::unique_ptr<ObjT>(createP(as_args...));
        }

        std::shared_ptr<Obj> createS(ConstructionArgs... as_args) { 
            return std::shared_ptr<ObjT>(createP(as_args...)); 
        }
    };
}  // namespace SDF::Common::Factory

#endif  // SDF_COMMON_FACTORY_AFACTORY_HPP