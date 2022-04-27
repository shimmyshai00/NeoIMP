#ifndef SDF_COMMON_LISTENER_LISTENERLIST_HPP
#define SDF_COMMON_LISTENER_LISTENERLIST_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ListenerList.hpp
// PURPOSE: Defines the ListenerList template.

#include <list>
#include <memory>

#include "../Connection.hpp"
#include "../IDisconnector.hpp"
#include "IListener.hpp"

namespace SDF::Common::Listener {
    // CLASS:   ListenerList
    // PURPOSE: Defines a list-like collection of listeners, i.e. it just accumulates listeners.
    template <class... Args>
    class ListenerList : private IDisconnector {
       public:
        // FUNCTION: ListenerList
        // PURPOSE:  Construct a new listener list.
        // NOTES:    None.
        ListenerList();

        // FUNCTION: addListener
        // PURPOSE:  Adds a listener to the listener list.
        // NOTES:    A variant that takes ownership of the listener is also provided for cases where that is more
        //           useful.
        Connection addListener(IListener<Args...> *pa_listener);
        Connection addListener(std::shared_ptr<IListener<Args...>> pa_listener);

       private:
        std::list<IListener<Args...> *> m_listenerPtrs;
        std::list<std::shared_ptr<IListener<Args...>>> m_listenerOwnerPtrs;

        void disconnectConnectable(IConnectable *pa_connectable);
    };
}  // namespace SDF::Common::Listener

#include "ListenerList.tpp"

#endif  // SDF_COMMON_LISTENER_LISTENERLIST_HPP