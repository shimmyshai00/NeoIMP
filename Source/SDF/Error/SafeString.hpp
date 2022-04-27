#ifndef SDF_ERROR_SAFESTRING_HPP
#define SDF_ERROR_SAFESTRING_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    SafeString.hpp
// PURPOSE: Defines the SafeString class.

#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstring>

namespace SDF::Error {
    class SafeString {
       public:
        SafeString() noexcept { stringBuf[0] = '\0'; }

        SafeString(const char *initString) noexcept {
            strncpy(stringBuf, initString, c_maxStrLen);
            stringBuf[c_maxStrLen] = '\0';
        }

        const char *get() const noexcept { return stringBuf; }

        // like sprintf
        void sPrintf(const char *fString, ...) noexcept {
            va_list vl;

            va_start(vl, fString);
            vsPrintf(fString, vl);
            va_end(vl);
        }

        // like vsprintf
        void vsPrintf(const char *fString, va_list vl) noexcept { vsnprintf(stringBuf, c_maxStrLen, fString, vl); }

       private:
        static const std::size_t c_maxStrLen = 1023;
        char stringBuf[c_maxStrLen + 1];
    };

    // Convenience methods.
    static SafeString safePrintf(const char *fString, ...) noexcept {
        SafeString rv;
        va_list vl;

        va_start(vl, fString);
        rv.vsPrintf(fString, vl);
        va_end(vl);

        return rv;
    }
}  // namespace SDF::Error

#endif  // SDF_ERROR_SAFESTRING_HPP