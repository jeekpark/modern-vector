#pragma once

#include <cstdint>

namespace mv
{

template<typename T>
class Vector3
{
public:
    constexpr Vector3();
    constexpr Vector3(T x, T y);
    template<typename U>
    constexpr explicit Vector3(const Vector3<U>& vector);

    [[nodiscard]] constexpr T Length() const;
    [[nodiscard]] constexpr T LengthSquare() const;
    [[nodiscard]] constexpr Vector3 Normalized() const;
    [[nodiscard]] constexpr T Dot(const Vector3& rhs) const;
    [[nodiscard]] constexpr T Cross(const Vector3& rhs) const;
    [[nodiscard]] constexpr Vector3 ClockWiseMul(const Vector3& rhs) const;
    [[nodiscard]] constexpr Vector3 ClockWiseDiv(const Vector3& rhs) const;

    T x{};
    T y{};

};

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator-(const Vector3<T>& right);

template<typename T>
constexpr Vector3<T> operator+=(Vector3<T>& left, const Vector3<T>& right);

template<typename T>
constexpr Vector3<T> operator-=(Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator+(const Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator-(const Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator*(const Vector3<T>& left, T right);

template<typename T>
constexpr Vector3<T>& operator*=(Vector3<T>& left, T right);

template<typename T>
[[nodiscard]] constexpr Vector3<T> operator/(const Vector3<T>& left, T right);

template<typename T>
constexpr Vector3<T>& operator/=(Vector3<T>& left, T right);

template<typename T>
[[nodiscard]] constexpr bool operator==(const Vector3<T>& left, const Vector3<T>& right);

template<typename T>
[[nodiscard]] constexpr bool operator!=(const Vector3<T>& left, const Vector3<T>& right);

using V2i8 = Vector3<int8_t>;
using V2i16 = Vector3<int16_t>;
using V2i32 = Vector3<int32_t>;
using V2i64 = Vector3<int64_t>;

using V2u8 = Vector3<uint8_t>;
using V2u16 = Vector3<uint16_t>;
using V2u32 = Vector3<uint32_t>;
using V2u64 = Vector3<uint64_t>;

using V2c = Vector3<char>;
using V2s = Vector3<short>;
using V2i = Vector3<int>;
using V2l = Vector3<long>;
using V2ll = Vector3<long long>;

using V2uc = Vector3<unsigned char>;
using V2us = Vector3<unsigned short>;
using V2ui = Vector3<unsigned int>;
using V2u = Vector3<unsigned>;
using V2ul = Vector3<unsigned long>;
using V2ull = Vector3<unsigned long long>;

using V2f = Vector3<float>;
using V2d = Vector3<double>;

} // namespace mv

#include <Vector2.inl>
