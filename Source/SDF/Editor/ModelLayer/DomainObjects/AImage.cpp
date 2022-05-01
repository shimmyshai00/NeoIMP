// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    AImage.cpp
// PURPOSE: Implements the AImage base class.

#include "AImage.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects {
    AImage::AImage(std::string a_name, float a_resolutionPpi) : m_name(a_name), m_resolutionPpi(a_resolutionPpi) {}

    std::string AImage::getName() const { return m_name; }

    float AImage::getResolutionPpi() const { return m_resolutionPpi; }
}  // namespace SDF::Editor::ModelLayer::DomainObjects