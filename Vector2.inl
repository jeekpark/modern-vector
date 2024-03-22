#pragma once

#include "Vector2.hpp"

#include <assert.h>

namespace mv
{

template<typename T>
constexpr Vector2<T>::Vector2() = default;

template<typename T>
constexpr Vector2<T>::Vector2(T x, T y)
: x(x)
, y(y)
{
}

template<typename T>
template<typename U>
constexpr Vector2<T>::Vector2(const Vector2<U>& vector)
: x(static_cast<T>(vector.x))
, y(static_cast<T>(vector.y))
{
}

template<typename T>
constexpr T Vector2<T>::lengthSq() const
{
    return dot(*this);
}

template<typename T>
constexpr T Vector2<T>::dot(const Vector2<T>& rhs) const
{
    return x * rhs.x + y * rhs.y;
}

template<typename T>
constexpr T Vector2<T>::cross(const Vector2<T>& rhs) const
{
    return x * rhs.y - y * rhs.x;
}



}