#ifndef SDF_COMMON_SINGLETON_SINGLETON_HPP
#define SDF_COMMON_SINGLETON_SINGLETON_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Singleton.hpp
// PURPOSE: Defines the Singleton template.

namespace SDF::Common::Singleton {
    // CLASS:   Singleton
    // PURPOSE: Defines a singular global object. Note that because it contains global state, one should use it with
    //          great reserve: in particular, it should not be used in such a way that information is communicated from 
    //          one part of the program to another "spookily". Generally singletons should be stateless and/or 
    //          immutable (effectively a rich function object), and dependency injection (here via Fruit) used for 
    //          mutable and/or stateful objects who are needed in multiple places.
    template<class T>
    class Singleton {
       private:
        static T *g_instance;

       public:
        static T *getInstance() {
            if(g_instance == nullptr) {
                g_instance = new T();
            }

            return g_instance;
        }
    };

    template<class T>
    T *Singleton<T>::g_instance = nullptr;
}  // namespace SDF::Common::Singleton

#endif // SDF_COMMON_SINGLETON_SINGLETON_HPP