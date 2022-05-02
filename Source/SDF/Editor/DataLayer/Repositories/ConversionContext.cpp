// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ConversionContext.cpp
// PURPOSE: Implements the ConversionContext class.

#include "ConversionContext.hpp"

#include "../Exceptions.hpp"

namespace SDF::Editor::DataLayer::Repositories {
    ConversionContext::ConversionContext(Common::Data::IUidGenerator *a_uidGenerator)
        : m_uidGenerator(a_uidGenerator) {}

    Common::Handle ConversionContext::saveContext(
        std::unique_ptr<ModelLayer::DomainObjects::Metrics::AConversionContext> a_ctx) {
        Common::Handle handle = m_uidGenerator->getNextHandle();
        m_ctxMap[handle] = std::move(a_ctx);

        return handle;
    }

    ModelLayer::DomainObjects::Metrics::AConversionContext *ConversionContext::getContext(
        Common::Handle a_handle) {
        if (m_ctxMap.find(a_handle) == m_ctxMap.end()) {
            throw ObjectNotFoundException(a_handle);
        }

        return m_ctxMap[a_handle].get();
    }

    void ConversionContext::updateContext(
        Common::Handle a_handle, std::unique_ptr<ModelLayer::DomainObjects::Metrics::AConversionContext> a_newCtx) {
        if (m_ctxMap.find(a_handle) == m_ctxMap.end()) {
            throw ObjectNotFoundException(a_handle);
        }

        m_ctxMap[a_handle] = std::move(a_newCtx);
    }

    void ConversionContext::deleteContext(Common::Handle a_handle) {
        if (m_ctxMap.find(a_handle) == m_ctxMap.end()) {
            throw ObjectNotFoundException(a_handle);
        }

        m_ctxMap.erase(a_handle);
        m_uidGenerator->retireHandle(a_handle);
    }
}  // namespace SDF::Editor::DataLayer::Repositories