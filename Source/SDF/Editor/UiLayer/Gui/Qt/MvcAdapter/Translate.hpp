#ifndef SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_TRANSLATE_HPP
#define SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_TRANSLATE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Translate.hpp
// PURPOSE: Defines a translation layer for Qt types into C++ standard types.

#include <QString>
#include <string>

namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter
{
    template <class QtT> struct Translate
    {
    };

    // Pass thru all C++ native types
    namespace Impl
    {
        template <class Primitive> struct PassThru
        {
            typedef Primitive trans_t;

            Primitive operator()(const Primitive &a_rhs)
            {
                return a_rhs;
            }
        };
    } // namespace Impl

    template <> struct Translate<bool> : Impl::PassThru<bool>
    {
    };
    template <> struct Translate<char> : Impl::PassThru<char>
    {
    };
    template <> struct Translate<short> : Impl::PassThru<short>
    {
    };
    template <> struct Translate<int> : Impl::PassThru<int>
    {
    };
    template <> struct Translate<long> : Impl::PassThru<long>
    {
    };
    template <> struct Translate<unsigned char> : Impl::PassThru<unsigned char>
    {
    };
    template <> struct Translate<unsigned short> : Impl::PassThru<unsigned short>
    {
    };
    template <> struct Translate<unsigned long> : Impl::PassThru<unsigned long>
    {
    };
    template <> struct Translate<float> : Impl::PassThru<float>
    {
    };
    template <> struct Translate<double> : Impl::PassThru<double>
    {
    };

    // Translate the Qt-specific types.
    template <> struct Translate<QString>
    {
        typedef std::string trans_t;

        // note: *must* return UTF-8 formatted strings; this is what the MVC controller layer is implied to accept as
        // neutral format
        trans_t operator()(const QString &rhs)
        {
            return rhs.toStdString();
        }
    };
} // namespace SDF::Editor::UiLayer::Gui::Qt::MvcAdapter

#endif // SDF_EDITOR_UILAYER_GUI_QT_MVCADAPTER_TRANSLATE_HPP