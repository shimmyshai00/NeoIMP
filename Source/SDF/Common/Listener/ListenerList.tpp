#ifndef SDF_COMMON_LISTENER_LISTENERLIST_TPP
#define SDF_COMMON_LISTENER_LISTENERLIST_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ListenerList.tpp
// PURPOSE: Implements the ListenerList template.

#include <algorithm>

#include "../Exceptions.hpp"

namespace SDF::Common::Listener {
    template <class... Args>
    ListenerList<Args...>::ListenerList() {}

    template <class... Args>
    Connection ListenerList<Args...>::addListener(IListener<Args...> *pa_listener) {
        if (std::find(m_listenerPtrs.begin(), m_listenerPtrs.end(), pa_listener) == m_listenerPtrs.end()) {
            m_listenerPtrs.push_back(pa_listener);
            return Connection(this, pa_listener);
        } else {
            throw DuplicateListenerException();
        }
    }

    template <class... Args>
    Connection ListenerList<Args...>::addListener(std::shared_ptr<IListener<Args...>> pa_listener) {
        for (auto it = m_listenerOwnerPtrs.begin(); it != m_listenerOwnerPtrs.end(); ++it) {
            if(it->get() == pa_listener) {
                throw DuplicateListenerException();
            }
        }

        m_listenerOwnerPtrs.push_back(pa_listener);
        return Connection(this, pa_listener.get());
    }
}  // namespace SDF::Common::Listener

namespace SDF::Common::Listener {
    // Private members
    template <class... Args>
    void ListenerList<Args...>::disconnectConnectable(IConnectable *pa_connectable) {
        if (std::find(m_listenerPtrs.begin(), m_listenerPtrs.end(), pa_connectable) != m_listenerPtrs.end()) {
            m_listenerPtrs.remove(pa_connectable);
        } else {
            // It may be an owning reference. Eliminate this possibility.
            for (auto it = m_listenerPtrs.begin(); it != m_listenerPtrs.end(); ++it) {
                if (it->get() == pa_connectable) {
                    m_listenerPtrs.erase(it);
                    break;
                }
            }
        }
    }
}  // namespace SDF::Common::Listener

#endif  // SDF_COMMON_LISTENER_LISTENERLIST_TPP
