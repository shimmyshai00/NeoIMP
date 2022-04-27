#ifndef SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_QTVIEW_TPP
#define SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_QTVIEW_TPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    QtView.tpp
// PURPOSE: Implements the QtView template.

#include <boost/mp11/algorithm.hpp>
#include <boost/mp11/list.hpp>
#include <tuple>

#include "Translate.hpp"

namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter
{
    namespace Impl
    {
        // some template magic to call a controller with fewer arguments than the ones passed
        template <class... Args> auto args_to_tuple(Args... as_args)
        {
            return std::make_tuple(as_args...);
        }

        template <class Tuple, std::size_t... Ns>
        auto extract_from(Tuple a_tup, boost::mp11::mp_list<boost::mp11::mp_int<Ns>...> a_seq)
        {
            return std::make_tuple(std::get<Ns>(a_tup)...);
        }

        template <class Tuple, std::size_t N> auto extract_first_n_from(Tuple a_tup)
        {
            return extract_from(a_tup, boost::mp11::mp_iota_c<N>());
        }

        template <class Tuple> struct TranslateTuple
        {
        };

        template <class... Args> struct TranslateTuple<std::tuple<Args...>>
        {
            std::tuple<Translate<Args>...> operator()(std::tuple<Args...> a_tup)
            {
                return std::apply([](auto... bs_vals) { (..., Translate(bs_vals)); }, a_tup);
            }
        };

        template <class QWidgetT, class FuncPtr> struct Connect
        {
        };

        template <class QWidgetT, class R, class... Args> struct Connect<QWidgetT, R (*)(Args...)>
        {
            template <class... ControllerArgs> struct To
            {
                QMetaObject::Connection like(QWidgetT *a_qWidget,
                                             R (*a_signal)(Args...),
                                             Common::Mvc::IController<ControllerArgs...> *a_controller)
                {
                    return QWidgetT::connect(a_qWidget, a_signal, [&](Args... bs_args) {
                        constexpr std::size_t N = boost::mp11::mp_size<boost::mp11::mp_list<ControllerArgs...>>::value;

                        auto passedTup = Impl::args_to_tuple(bs_args...);
                        auto shrunkTup = Impl::extract_first_n_from<decltype(passedTup)::type, N>(passedTup);
                        auto translatedTup = TranslateTuple<decltype(shrunkTup)>(shrunkTup);

                        return std::apply(*a_signal, translatedTup);
                    });
                }
            };
        };
    } // namespace Impl

    template <class QWidgetT> QtView<QWidgetT>::QtView(QWidget *a_parent) : QWidgetT(a_parent)
    {
    }

    template <class QWidgetT>
    template <class FuncPtr, class... ControllerArgs>
    Common::Connection QtView<QWidgetT>::attachController(
        FuncPtr a_signal, std::unique_ptr<Common::Mvc::IController<ControllerArgs...>> a_controller)
    {
        // get the pointer before we anonymize it away
        Common::Mvc::IController<ControllerArgs...> *controllerPtr = a_controller.get();
        m_ownedControllers.push_back(std::move(a_controller));

        // use our template magic to rip and translate the parameters on a_signal.
        auto qtConn =
            Impl::Connect<QWidgetT, FuncPtr>::template To<ControllerArgs...>::like(this, a_signal, controllerPtr);
        m_qtConns.push_back(qtConn);

        return Common::Connection(this, controllerPtr);
    }
} // namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter

namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter
{
    // Private member.
    template <class QWidgetT> void QtView<QWidgetT>::disconnectConnectable(Common::IConnectable *pa_connectable)
    {
        auto connIt = m_qtConns.begin();
        for (auto it = m_ownedControllers.begin(); it != m_ownedControllers.end(); ++it, ++connIt)
        {
            if (it->get() == pa_connectable)
            {
                m_ownedControllers.erase(it);
                m_qtConns.erase(connIt);
                break;
            }
        }
    }
} // namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter

#endif // SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_QTVIEW_TPP