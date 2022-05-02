// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    CustomConversionContext.cpp
// PURPOSE: Implements the CustomConversionContext class.

#include "CustomConversionContext.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Metrics {
    CustomConversionContext::CustomConversionContext(float a_resolutionPpi) : m_resolutionPpi(a_resolutionPpi) {}

    float CustomConversionContext::getResolutionPpi() const { return m_resolutionPpi; }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Metrics