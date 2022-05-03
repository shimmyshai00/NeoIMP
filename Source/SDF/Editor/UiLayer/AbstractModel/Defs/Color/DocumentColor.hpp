#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DOCUMENTCOLOR_HPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DOCUMENTCOLOR_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    DocumentColor.hpp
// PURPOSE: Defines the DocumentColor template.

#include <array>
#include <boost/mp11/list.hpp>

#include "ColorFormat.hpp"
#include "IColor.hpp"

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    // CLASS:   DocumentColor
    // PURPOSE: Defines a generic format for specifying document color values.
    template <ColorFormat Fmt, std::size_t... ChannelBits>
    class DocumentColor : public IColor<ColorFormat> {
       public:
        DocumentColor();
        DocumentColor(const std::initializer_list<int> &a_il);

        ColorFormat getFormat() const;
        std::size_t getNumChannels() const;
        int getChannelMin(std::size_t a_which) const;
        int getChannelMax(std::size_t a_which) const;

        int get(std::size_t a_which) const;
        float getF(std::size_t a_which) const;

        void set(std::size_t a_which, int a_to);
        void setF(std::size_t a_which, float a_to);

       private:
        static constexpr std::size_t NUM_CHANNELS =
            boost::mp11::mp_size<boost::mp11::mp_list<boost::mp11::mp_int<ChannelBits>...>>::value;

        std::array<int, NUM_CHANNELS> m_mins;
        std::array<int, NUM_CHANNELS> m_maxes;

        std::array<int, NUM_CHANNELS> m_values;
    };
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

#include "DocumentColor.tpp"

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DOCUMENTCOLOR_HPP