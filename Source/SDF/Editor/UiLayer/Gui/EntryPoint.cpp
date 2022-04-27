// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    EntryPoint.cpp
// PURPOSE: Implements the EntryPoint class.

#include "EntryPoint.hpp"

namespace SDF::Editor::UiLayer::Gui {
    EntryPoint::EntryPoint(Common::Mvc::IViewProducer<> *a_mainWindowProducer)
        : m_mainWindowProducer(a_mainWindowProducer) {}

    void EntryPoint::startUi() { m_mainWindowProducer->requestView(); }
}  // namespace SDF::Editor::UiLayer::Gui
