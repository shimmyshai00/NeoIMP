#ifndef SDF_EDITOR_MODELLAYER_ABSTRACTDATA_ICONVERSIONCONTEXTREPOSITORY_HPP
#define SDF_EDITOR_MODELLAYER_ABSTRACTDATA_ICONVERSIONCONTEXTREPOSITORY_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IConversionContextRepository.hpp
// PURPOSE: Defines the IConversionContextRepository interface.

#include <memory>

#include "../../../Common/Handle.hpp"
#include "../DomainObjects/Metrics/AConversionContext.hpp"

namespace SDF::Editor::ModelLayer::AbstractData {
    // CLASS:   IConversionContextRepository
    // PURPOSE: Defines a repository interface for storing conversion contexts.
    class IConversionContextRepository {
       public:
        virtual ~IConversionContextRepository() = default;

        // FUNCTION: saveContext
        // PURPOSE:  Stores a context in the repository.
        // NOTES:    The handle must not be Common::HANDLE_INVALID.
        virtual Common::Handle saveContext(std::unique_ptr<DomainObjects::Metrics::AConversionContext> a_ctx) = 0;

        // FUNCTION: getContext
        // PURPOSE:  Gets a conversion context in the repository.
        // NOTES:    None.
        virtual DomainObjects::Metrics::AConversionContext *getContext(Common::Handle a_handle) = 0;

        // FUNCTION: updateContext
        // PURPOSE:  Updates a conversion context with a new version.
        // NOTES:    None.
        virtual void updateContext(Common::Handle a_handle,
                                   std::unique_ptr<DomainObjects::Metrics::AConversionContext> a_newCtx) = 0;

        // FUNCTION: deleteContext
        // PURPOSE:  Deletes a context from the repository.
        // NOTES:    None.
        virtual void deleteContext(Common::Handle a_handle) = 0;
    };
}  // namespace SDF::Editor::ModelLayer::AbstractData

#endif  // SDF_EDITOR_MODELLAYER_ABSTRACTDATA_ICONVERSIONCONTEXTREPOSITORY_HPP