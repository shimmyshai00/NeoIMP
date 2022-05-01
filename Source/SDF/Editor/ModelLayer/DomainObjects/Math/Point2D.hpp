#ifndef SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_POINT2D_HPP
#define SDF_EDITOR_MODELLAYER_DOMAINOBJECTS_MATH_POINT2D_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Point2D.hpp
// PURPOSE: Definition of a type holding a pair of 2D coordinates, representing a point or location in 2D space.

#include "Vec2D.hpp"

namespace SDF::Editor::ModelLayer::DomainObjects::Math {
    template <class T>
    class Point2D {
       public:
        Point2D() : m_x(0), m_y(0) {}

        Point2D(T a_x, T a_y) : m_x(a_x), m_y(a_y) {}

        template <class U>
        Point2D(Point2D<U> a_otherPoint) : m_x(a_otherPoint.x()), m_y(a_otherPoint.y()) {}

        ~Point2D() {}

        // Element access.
        T &x() { return m_x; }

        T &y() { return m_y; }

        const T &x() const { return m_x; }

        const T &y() const { return m_y; }

        // Affine operators.
        Point2D<T> &operator+=(const Vec2D<T> &a_rhs) {
            m_x += a_rhs.x();
            m_y += a_rhs.y();
            return *this;
        }

        Point2D<T> &operator-=(const Vec2D<T> &a_rhs) {
            m_x -= a_rhs.x();
            m_y -= a_rhs.y();
            return *this;
        }

       private:
        T m_x;
        T m_y;
    };

    // Non-member operators.
    template <class T>
    static inline bool operator==(const Point2D<T> &a_lhs, const Point2D<T> &a_rhs) {
        return (a_lhs.x() == a_rhs.x()) && (a_lhs.y() == a_rhs.y());
    }

    template <class T>
    static inline bool operator!=(const Point2D<T> &a_lhs, const Point2D<T> &a_rhs) {
        return !(a_lhs == a_rhs);
    }

    template <class T>
    static inline Point2D<T> operator+(const Point2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
        return Point2D<T>(a_lhs) += a_rhs;
    }

    template <class T>
    static inline Point2D<T> operator-(const Point2D<T> &a_lhs, const Vec2D<T> &a_rhs) {
        return Point2D<T>(a_lhs) -= a_rhs;
    }

    template <class T>
    static inline Vec2D<T> operator-(const Point2D<T> &a_lhs, const Point2D<T> &a_rhs) {
        return Vec2D<T>(a_lhs.x() - a_rhs.x(), a_lhs.y() - a_rhs.y());
    }
}  // namespace SDF::Editor::ModelLayer::DomainObjects::Math

#endif
