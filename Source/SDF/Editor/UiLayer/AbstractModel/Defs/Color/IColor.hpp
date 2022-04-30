#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ICOLOR_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ICOLOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    IColor.hpp
// PURPOSE: Defines the IColor interface.

#include <cstddef>

#include "ColorFormat.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    // CLASS:   IColor
    // PURPOSE: Defines an interface for communicating single-pixel color information across the UI-model boundary.
    //          This interface is NOT EFFICIENT for large amounts of information, such as image renders.
    template <class EnumT>
    class IColor {
       public:
        virtual ~IColor() = default;

        // FUNCTION: getFormat
        // PURPOSE:  Gets the format enum value for this color.
        // NOTES:    None.
        virtual EnumT getFormat() const = 0;

        // FUNCTION: getNumChannels
        // PURPOSE:  Get the number of color channels available.
        // NOTES:    None.
        virtual std::size_t getNumChannels() const = 0;

        // FUNCTION: getChannelMin
        // PURPOSE:  Get the minimum value allowed in a color channel.
        // NOTES:    This is typically 0 for most formats. The channels are indexed in semantic order, e.g. for RGB,
        //           "R" is channel 0.
        virtual float getChannelMin(std::size_t a_which) const = 0;

        // FUNCTION: getChannelMax
        // PURPOSE:  Get the maximum value allowed in a color channel.
        // NOTES:    None.
        virtual float getChannelMax(std::size_t a_which) const = 0;

        // FUNCTION: get
        // PURPOSE:  Get the value of a particular color channel.
        // NOTES:    None.
        virtual float get(std::size_t a_which) const = 0;

        // FUNCTION: set
        // PURPOSE:  Set the value of a particular color channel.
        // NOTES:    If the value is out of range, it will be clamped.
        virtual void set(std::size_t a_which, float a_to) = 0;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_ICOLOR_HPP