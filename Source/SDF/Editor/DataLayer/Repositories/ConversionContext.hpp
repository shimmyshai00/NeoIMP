#ifndef SDF_EDITOR_DATALAYER_REPOSITORIES_CONVERSIONCONTEXT_HPP
#define SDF_EDITOR_DATALAYER_REPOSITORIES_CONVERSIONCONTEXT_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    ConversionContext.hpp
// PURPOSE: Defines the ConversionContext class.

#include <fruit/fruit.h>

#include <map>
#include <memory>

#include "../../../Common/Data/IUidGenerator.hpp"
#include "../../../Common/Handle.hpp"
#include "../../ModelLayer/AbstractData/IConversionContextRepository.hpp"
#include "../../ModelLayer/DomainObjects/Metrics/AConversionContext.hpp"

namespace SDF::Editor::DataLayer::Repositories {
    // CLASS:   ConversionContext
    // PURPOSE: Defines a memory-only repository for conversion contexts.
    class ConversionContext : public ModelLayer::AbstractData::IConversionContextRepository {
       public:
        INJECT(ConversionContext(Common::Data::IUidGenerator *a_uidGenerator));

        Common::Handle saveContext(std::unique_ptr<ModelLayer::DomainObjects::Metrics::AConversionContext> a_ctx);

        ModelLayer::DomainObjects::Metrics::AConversionContext *getContext(Common::Handle a_handle);

        void updateContext(Common::Handle a_handle,
                           std::unique_ptr<ModelLayer::DomainObjects::Metrics::AConversionContext> a_newCtx);

        void deleteContext(Common::Handle a_handle);

       private:
        Common::Data::IUidGenerator *m_uidGenerator;

        std::map<Common::Handle, std::unique_ptr<ModelLayer::DomainObjects::Metrics::AConversionContext>> m_ctxMap;
    };
}  // namespace SDF::Editor::DataLayer::Repositories

#endif  // SDF_EDITOR_DATALAYER_REPOSITORIES_CONVERSIONCONTEXT_HPP