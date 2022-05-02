// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    UnitConversion.hpp
// PURPOSE: Implements the UnitConversion class.

#include "UnitConversion.hpp"

#include "../DomainObjects/Metrics/AConversionContext.hpp"
#include "../DomainObjects/Metrics/CustomConversionContext.hpp"
#include "../DomainObjects/Metrics/LengthConverter.hpp"
#include "../DomainObjects/Metrics/ResolutionConverter.hpp"

namespace SDF::Editor::ModelLayer::Services {
    UnitConversion::UnitConversion(AbstractData::IConversionContextRepository *a_conversionContextRepository)
        : m_conversionContextRepository(a_conversionContextRepository) {}

    Common::Handle UnitConversion::createUnitConversionContext(float a_resolutionPpi) { 
        using namespace DomainObjects::Metrics;

        std::unique_ptr<AConversionContext> newCtx(new CustomConversionContext(a_resolutionPpi));
        return m_conversionContextRepository->saveContext(std::move(newCtx));
    }

    void UnitConversion::deleteUnitConversionContext(Common::Handle a_ctx) {
        m_conversionContextRepository->deleteContext(a_ctx);
    }

    void UnitConversion::setConversionResolution(Common::Handle a_ctx, float a_resolutionPpi) {
        using namespace DomainObjects::Metrics;

        std::unique_ptr<AConversionContext> newCtx(new CustomConversionContext(a_resolutionPpi));
        m_conversionContextRepository->updateContext(a_ctx, std::move(newCtx));
    }

    float UnitConversion::convert(float a_quant,
                                  UiLayer::AbstractModel::Defs::Metrics::LengthUnit a_from,
                                  UiLayer::AbstractModel::Defs::Metrics::LengthUnit a_to,
                                  Common::Handle a_ctx) {
        using namespace DomainObjects::Metrics;

        LengthConverter lconv;

        if(a_ctx != Common::HANDLE_INVALID) {
            AConversionContext *ctx = m_conversionContextRepository->getContext(a_ctx);
            return lconv.convert(a_quant, a_from, a_to, *ctx);
        } else {
            // convert via the default of 72 PPI
            CustomConversionContext ctx(72.0f);
            return lconv.convert(a_quant, a_from, a_to, ctx);
        }
    }

    float UnitConversion::convert(float a_quant,
                                  UiLayer::AbstractModel::Defs::Metrics::ResolutionUnit a_from,
                                  UiLayer::AbstractModel::Defs::Metrics::ResolutionUnit a_to) {
        using namespace DomainObjects::Metrics;

        CustomConversionContext ctx(72.0f);
        ResolutionConverter rconv;

        return rconv.convert(a_quant, a_from, a_to, ctx);
    }
}  // namespace SDF::Editor::ModelLayer::Services