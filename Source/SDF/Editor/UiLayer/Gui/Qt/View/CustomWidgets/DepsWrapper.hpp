#ifndef SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DEPSWRAPPER_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DEPSWRAPPER_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    DepsWrapper.hpp
// PURPOSE: Defines the DepsWrapper template.

#include <boost/mp11/list.hpp>
#include <memory>

#include "../../../../../../Common/Mvc/ServicePack.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets {
    // CLASS:   DepsWrapper
    // PURPOSE: Provides a means of delaying the injection of service dependencies from hitting custom widgets
    //          immediately by capturing them so method injection can be used. This is needed in order to appease Qt's
    //          Qt Designer forms system because it cannot be made to generate the necessary injection code itself
    //          when it constructs a widget. In particular, while an SDF::Common::Mvc::ServicePack is injected at
    //          application startup and cannot thus be nulled, this object permits the dependent to have null
    //          dependencies and implement a special non-functional placement state so that it can be used within Qt
    //          Designer.
    template <class... Ss>
    class DepsWrapper {
       public:
        DepsWrapper();  // yep!
        DepsWrapper(Common::Mvc::ServicePack<Ss...> a_deps);

        // FUNCTION: areDepsAvailable
        // PURPOSE:  Returns whether the dependencies are available.
        // NOTES:    None.
        bool areDepsAvailable() const;

        // FUNCTION: pack
        // PURPOSE:  Accesses the dependency pack.
        // NOTES:    Will be nullptr if deps are not available.
        Common::Mvc::ServicePack<Ss...> *pack();
        const Common::Mvc::ServicePack<Ss...> *pack() const;

       private:
        // the unique_ptr can be null!
        std::unique_ptr<Common::Mvc::ServicePack<Ss...>> m_services;
    };

    template <class Pack>
    using WrappedPack = boost::mp11::mp_apply<DepsWrapper, Pack>;
}  // namespace SDF::Editor::UiLayer::Gui::Qt::View::CustomWidgets

#include "DepsWrapper.tpp"

#endif  // SDF_EDITOR_UILAYER_GUI_QT_VIEW_CUSTOMWIDGETS_DEPSWRAPPER_HPP