#pragma once

#include "Angle.hpp"

namespace mv
{

template<typename T>
class Vector2
{
public:
    constexpr Vector2();
    constexpr Vector2(T x, T y);

    template<typename U>
    constexpr explicit Vector2(const Vector2<U>& vector);

    [[nodiscard]] constexpr T length() const;
    [[nodiscard]] constexpr T lengthSq() const;
    [[nodiscard]] constexpr Vector2 normalized() const;
    [[nodiscard]] constexpr T dot(const Vector2& rhs) const;
    [[nodiscard]] constexpr T cross(const Vector2& rhs) const;
    [[nodiscard]] constexpr Vector2 cwiseMul(const Vector2<T>& rhs) const;
    [[nodiscard]] constexpr Vector2 cwiseDiv(const Vector2<T>& rhs) const;

    T x{};
    T y{};

    static const Vector2 UnitX;
    static const Vector2 UnitY;


};

using V2i8 = Vector2<int8_t>;
using V2i16 = Vector2<int16_t>;
using V2i32 = Vector2<int32_t>;
using V2i64 = Vector2<uint32_t>;

using V2u8 = Vector2<uint8_t>;
using V2u16 = Vector2<uint16_t>;
using V2u32 = Vector2<uint32_t>;
using V2u64 = Vector2<uint64_t>;

using V2f32 = Vector2<float>;
using V2f64 = Vector2<double>;



} // namespace mv

#include "Vector2.inl"
