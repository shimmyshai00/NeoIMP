#ifndef SDF_ERROR_EXCEPTION_HPP
#define SDF_ERROR_EXCEPTION_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Exception.hpp
// PURPOSE: Defines the Exception class.
#include <cstdarg>
#include <exception>

#include "SafeString.hpp"

namespace SDF::Error
{
    class Exception : public std::exception
    {
      public:
        const char *what() const noexcept final
        {
            return m_whatStr.get();
        }

      protected:
        template <class... Args> void whatPrintf(const char *f, Args... args)
        {
            m_whatStr.sPrintf(f, args...);
        }

      private:
        SafeString m_whatStr;
    };

    // Used to report a condition whose occurrence is considered as likely to represent a bug in the program.
    template <class LayerExcT> class LikelyBug : public LayerExcT
    {
    };

    // Used to report general errors that are *NOT* considered to represent program bugs (e.g. file not found).
    template <class LayerExcT> class General : public LayerExcT
    {
    };
} // namespace SDF::Error

#endif // SDF_ERROR_EXCEPTION_HPP