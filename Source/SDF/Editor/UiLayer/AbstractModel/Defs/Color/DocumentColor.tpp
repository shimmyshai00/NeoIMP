#ifndef SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DOCUMENTCOLOR_TPP
#define SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DOCUMENTCOLOR_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    DocumentColor.tpp
// PURPOSE: Implements the DocumentColor class.

#include <cmath>

namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color {
    template <ColorFormat Fmt, std::size_t... ChannelBits>
    DocumentColor<Fmt, ChannelBits...>::DocumentColor() {
        std::array<int, NUM_CHANNELS> bitDepths = {ChannelBits...};
        for (std::size_t i(0); i < NUM_CHANNELS; ++i) {
            m_mins[i] = 0;
            m_maxes[i] = (1 << bitDepths[i]) - 1;
            m_values[i] = 0;
        }
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    DocumentColor<Fmt, ChannelBits...>::DocumentColor(const std::initializer_list<int> &a_il) : DocumentColor() {
        std::vector<int> vec(a_il);

        for (std::size_t i(0); i < NUM_CHANNELS; ++i) {
            m_values[i] = vec[i];
        }
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    ColorFormat DocumentColor<Fmt, ChannelBits...>::getFormat() const {
        return Fmt;
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    std::size_t DocumentColor<Fmt, ChannelBits...>::getNumChannels() const {
        return NUM_CHANNELS;
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    int DocumentColor<Fmt, ChannelBits...>::getChannelMin(std::size_t a_which) const {
        return m_mins.at(a_which);
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    int DocumentColor<Fmt, ChannelBits...>::getChannelMax(std::size_t a_which) const {
        return m_maxes.at(a_which);
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    int DocumentColor<Fmt, ChannelBits...>::get(std::size_t a_which) const {
        return m_values.at(a_which);
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    float DocumentColor<Fmt, ChannelBits...>::getF(std::size_t a_which) const {
        float channelWidth = 0.0f + m_maxes.at(a_which) - m_mins.at(a_which);

        return (0.0f + m_values.at(a_which) - m_mins.at(a_which)) / channelWidth;
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    void DocumentColor<Fmt, ChannelBits...>::set(std::size_t a_which, int a_to) {
        m_values.at(a_which) = std::clamp(a_to, m_mins.at(a_which), m_maxes.at(a_which));
    }

    template <ColorFormat Fmt, std::size_t... ChannelBits>
    void DocumentColor<Fmt, ChannelBits...>::setF(std::size_t a_which, float a_to) {
        float channelWidth = 0.0f + m_maxes.at(a_which) - m_mins.at(a_which);
        float channelVal = channelWidth * a_to + m_mins.at(a_which);

        m_values.at(a_which) = std::clamp<float>(floor(channelVal + 0.5f), m_mins.at(a_which), m_maxes.at(a_which));
    }
}  // namespace SDF::Editor::UiLayer::AbstractModel::Defs::Color

#endif  // SDF_EDITOR_UILAYER_ABSTRACTMODEL_DEFS_COLOR_DOCUMENTCOLOR_TPP