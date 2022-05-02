#ifndef SDF_EDITOR_MODELLAYER_SERVICES_ENGINEINFO_HPP
#define SDF_EDITOR_MODELLAYER_SERVICES_ENGINEINFO_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    EngineInfo.hpp
// PURPOSE: Defines the EngineInfo class.

#include <fruit/fruit.h>

#include <cstddef>

#include "../../UiLayer/AbstractModel/Services/IGetImageLimits.hpp"

namespace SDF::Editor::ModelLayer::Services {
    // CLASS:   EngineInfo
    // PURPOSE: Defines an MVC service to get descriptive information about the engine and capabilities.
    class EngineInfo : public UiLayer::AbstractModel::Services::IGetImageLimits {
       public:
        INJECT(EngineInfo());

        std::size_t getMaximumImageWidth() const;
        std::size_t getMaximumImageHeight() const;
    };
}  // namespace SDF::Editor::ModelLayer::Services

#endif  // SDF_EDITOR_MODELLAYER_SERVICES_ENGINEINFO_HPP