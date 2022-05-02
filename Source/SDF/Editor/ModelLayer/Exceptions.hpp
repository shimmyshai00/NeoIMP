#ifndef SDF_EDITOR_MODELLAYER_EXCEPTIONS_HPP
#define SDF_EDITOR_MODELLAYER_EXCEPTIONS_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
// 
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Exceptions.hpp
// PURPOSE: Defines the exceptions that can be thrown from the model layer.

#include "../../Error/Exception.hpp"

namespace SDF::Editor::ModelLayer {
    struct ModelException : public Error::Exception {};

    struct UnknownLengthUnitException : public Error::LikelyBug<ModelException> {
        UnknownLengthUnitException(int a_whichUnit) {
            whatPrintf("Tried to do a unit conversion using an unknown length unit indexed by '%d'.", a_whichUnit);
        }
    };

    struct UnknownResolutionUnitException : public Error::LikelyBug<ModelException> {
        UnknownResolutionUnitException(int a_whichUnit) {
            whatPrintf("Tried to do a unit conversion using an unknown resolution unit indexed by '%d'.", a_whichUnit);
        }
    };
}

#endif // SDF_EDITOR_MODELLAYER_EXCEPTIONS_HPP