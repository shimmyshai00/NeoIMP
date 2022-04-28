#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IUNITCONVERSIONCONTEXTMANIPULATOR_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IUNITCONVERSIONCONTEXTMANIPULATOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IUnitConversionContextManipulator.hpp
// PURPOSE: Defines the IUnitConversionContextManipulator interface.

#include "../../../../Common/Handle.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Services {
    // CLASS:   IUnitConversionContextManipulator
    // PURPOSE: Defines a class to manipulate unit conversion contexts.
    class IUnitConversionContextManipulator {
       public:
        virtual ~IUnitConversionContextManipulator() = default;

        // FUNCTION: createUnitConversionContext
        // PURPOSE:  Creates a new unit conversion context.
        // NOTES:    None.
        virtual Common::Handle createUnitConversionContext(float a_resolutionPpi) = 0;

        // FUNCTION: deleteUnitConversionContext
        // PURPOSE:  Deletes a unit conversion context.
        // NOTES:    None.
        virtual void deleteUnitConversionContext(Common::Handle a_ctx) = 0;

        // FUNCTION: setConversionResolution
        // PURPOSE:  Sets the conversion resolution used in a context.
        // NOTES:    None.
        virtual void setConversionResolution(Common::Handle a_ctx, float a_resolutionPpi) = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Services

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_SERVICES_IUNITCONVERSIONCONTEXTMANIPULATOR_HPP