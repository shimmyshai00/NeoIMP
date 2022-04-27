#ifndef SDF_COMMON_LISTENER_LISTENERMAP_TPP
#define SDF_COMMON_LISTENER_LISTENERMAP_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ListenerMap.tpp
// PURPOSE: Implements the ListenerMap template.

#include <algorithm>

#include "../Exceptions.hpp"

namespace SDF::Common::Listener {
    template <class KeyT, class... Args>
    ListenerMap<KeyT, Args...>::ListenerMap() {}

    template <class KeyT, class... Args>
    Connection ListenerMap<KeyT, Args...>::addListener(const KeyT &a_key, IListener<Args...> *pa_listener) {
        if (m_listenerPtrs.find(a_key) == m_listenerPtrs.end()) {
            m_listenerPtrs[a_key].push_back(pa_listener);

            return Connection(this, pa_listener);
        } else {
            if (std::find(m_listenerPtrs.at(a_key).begin(), m_listenerPtrs.at(a_key).end(), pa_listener) ==
                m_listenerPtrs.end()) {
                m_listenerPtrs[a_key].push_back(pa_listener);
                return Connection(this, pa_listener);
            } else {
                throw DuplicateListenerException();
            }
        }
    }

    template <class KeyT, class... Args>
    Connection ListenerMap<KeyT, Args...>::addListener(const KeyT &a_key,
                                                       std::shared_ptr<IListener<Args...>> pa_listener) {
        if (m_listenerOwnerPtrs.find(a_key) == m_listenerOwnerPtrs.end()) {
            m_listenerOwnerPtrs[a_key].push_back(pa_listener);

            return Connection(this, pa_listener.get());
        } else {
            for (auto it = m_listenerOwnerPtrs[a_key].begin(); it != m_listenerOwnerPtrs[a_key].end(); ++it) {
                if (it->get() == pa_listener.get()) {
                    throw DuplicateListenerException();
                }
            }

            m_listenerPtrs[a_key].push_back(pa_listener);
            return Connection(this, pa_listener.get());
        }
    }
}  // namespace SDF::Common::Listener

namespace SDF::Common::Listener {
    // Private members
    template <class KeyT, class... Args>
    void ListenerMap<KeyT, Args...>::disconnectConnectable(IConnectable *pa_connectable) {
        // Comb the whole map looking for this connectable, unfortunately
        for (auto it = m_listenerPtrs.begin(); it != m_listenerPtrs.end(); ++it) {
            for (auto innerIt = it.second->begin(); innerIt != it.second->end(); ++innerIt) {
                if (*innerIt == pa_connectable) {
                    it->erase(innerIt);
                    if (it->empty()) {
                        m_listenerPtrs.erase(it.first);
                        return;
                    }
                }
            }
        }

        for (auto it = m_listenerOwnerPtrs.begin(); it != m_listenerOwnerPtrs.end(); ++it) {
            for (auto innerIt = it.second->begin(); innerIt != it.second->end(); ++innerIt) {
                if (innerIt->get() == pa_connectable) {
                    it->erase(innerIt);
                    if (it->empty()) {
                        m_listenerPtrs.erase(it.first);
                        return;
                    }
                }
            }
        }
    }
}  // namespace SDF::Common::Listener

#endif  // SDF_COMMON_LISTENER_LISTENERMAP_TPP