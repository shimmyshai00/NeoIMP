#ifndef SDF_COMMON_LISTENER_LISTENERMAP_HPP
#define SDF_COMMON_LISTENER_LISTENERMAP_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ListenerMap.hpp
// PURPOSE: Defines the ListenerMap template.

#include <list>
#include <map>
#include <memory>

#include "../Connection.hpp"
#include "../IDisconnector.hpp"
#include "IListener.hpp"

namespace SDF::Common::Listener {
    // CLASS:   ListenerMap
    // PURPOSE: Defines a map-like (actually multimap-like) collection of listeners, i.e. it indexes listeners for
    //          different "keys".
    template <class KeyT, class... Args>
    class ListenerMap : private IDisconnector {
       public:
        // FUNCTION: ListenerMap
        // PURPOSE:  Construct a new listener map.
        // NOTES:    None.
        ListenerMap();

        // FUNCTION: addListener
        // PURPOSE:  Adds a listener to the listener map.
        // NOTES:    A variant that takes ownership of the listener is also provided for cases where that is more
        //           useful.
        Connection addListener(const KeyT &a_key, IListener<Args...> *pa_listener);
        Connection addListener(const KeyT &a_key, std::shared_ptr<IListener<Args...>> pa_listener);

       private:
        // to ensure the listeners are called in the order they are added
        template <class T, class U>
        using multimap_t = std::map<T, std::list<U>>;

        multimap_t<KeyT, IListener<Args...> *> m_listenerPtrs;
        multimap_t<KeyT, std::shared_ptr<IListener<Args...>>> m_listenerOwnerPtrs;

        void disconnectConnectable(IConnectable *pa_connectable);
    };
}  // namespace SDF::Common::Listener

#include "ListenerMap.tpp"

#endif  // SDF_COMMON_LISTENER_LISTENERMAP_HPP