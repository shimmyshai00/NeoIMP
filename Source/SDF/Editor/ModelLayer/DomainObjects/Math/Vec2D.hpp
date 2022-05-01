#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_VEC2D_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_VEC2D_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Vec2D.hpp
// PURPOSE: Definition of a type representing a 2D vector. Note that, in line with mathematical principles, vectors are
//          not the same as coordinates, and do not support the same operations.

namespace SDF::Editor::ModelLayer::DomainObjects::Math {
    template <class T>
    class Vec2D {
       public:
        Vec2D(T a_x, T a_y) : m_x(a_x), m_y(a_y) {}

        ~Vec2D() {}

        // Element access.
        T &x() { return m_x; }

        T &y() { return m_y; }

        const T &x() const { return m_x; }

        const T &y() const { return m_y; }

        // Vector operations.
        Vec2D<T> &operator+=(const Vec2D<T> &a_rhs) {
            m_x += a_rhs.m_x;
            m_y += a_rhs.m_y;

            return *this;
        }

        Vec2D<T> &operator-=(const Vec2D<T> &a_rhs) {
            m_x -= a_rhs.m_x;
            m_y -= a_rhs.m_y;

            return *this;
        }

        Vec2D<T> &operator*=(T a_s) {
            m_x *= a_s;
            m_y *= a_s;

            return *this;
        }

       private:
        T m_x;
        T m_y;
    };

    // Non-member operators.
    template <class T>
    static inline bool operator==(const Vec2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
        return (a_lhs.x() == a_rhs.x()) && (a_lhs.y() == a_rhs.y());
    }

    template <class T>
    static inline bool operator!=(const Vec2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
        return !(a_lhs == a_rhs);
    }

    template <class T>
    static inline Vec2D<T> operator+(const Vec2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
        return Vec2D<T>(a_lhs) += a_rhs;
    }

    template <class T>
    static inline Vec2D<T> operator-(const Vec2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
        return Vec2D<T>(a_lhs) -= a_rhs;
    }

    template <class T>
    static inline Vec2D<T> operator-(const Vec2D<T> &a_rhs) {
        return Vec2D<T>(-a_rhs.x(), -a_rhs.y());
    }

    template <class T>
    static inline Vec2D<T> operator*(double a_s, const Vec2D<T> &a_rhs) {
        return Vec2D<T>(a_rhs) *= a_s;
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Math

#endif
