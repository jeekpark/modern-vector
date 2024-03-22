#pragma once

#include "Angle.hpp"

#include <cassert>

namespace mv
{
namespace priv
{
constexpr float pi = 3.141592654f;

constexpr float positiveRemainder(float a, float b)
{
    assert(b > 0.0f);
    const float val = a - static_cast<float>(static_cast<int>(a / b)) * b;
    if (val >= 0.f)
        return val;
    else
        return val + b;
}
} // namespace priv

constexpr Angle::Angle() = default;

constexpr float Angle::asDegrees() const
{
    return mDegrees;
}

constexpr float Angle::asRadians() const
{
    return mDegrees * (priv::pi / 180);
}

constexpr Angle Angle::wrapSigned() const
{
    return degrees(priv::positiveRemainder(mDegrees + 180, 360) - 180);
}

constexpr Angle Angle::wrapUnsigned() const
{
    return degrees(priv::positiveRemainder(mDegrees, 360));
}

constexpr Angle::Angle(float degrees)
: mDegrees(degrees)
{
}

constexpr Angle degrees(float angle)
{
    return Angle(angle);
}

constexpr Angle radians(float angle)
{
    return Angle(angle * (180 / priv::pi));
}

constexpr bool operator==(Angle left, Angle right)
{
    return left.asDegrees() == right.asDegrees();
}

constexpr bool operator!=(Angle left, Angle right)
{
    return left.asDegrees() != right.asDegrees();
}

constexpr bool operator<(Angle left, Angle right)
{
    return left.asDegrees() < right.asDegrees();
}

constexpr bool operator>(Angle left, Angle right)
{
    return left.asDegrees() > right.asDegrees();
}


////////////////////////////////////////////////////////////
constexpr bool operator<=(Angle left, Angle right)
{
    return left.asDegrees() <= right.asDegrees();
}


////////////////////////////////////////////////////////////
constexpr bool operator>=(Angle left, Angle right)
{
    return left.asDegrees() >= right.asDegrees();
}

constexpr Angle operator-(Angle right)
{
    return degrees(-right.asDegrees());
}

constexpr Angle operator+(Angle left, Angle right)
{
    return degrees(left.asDegrees() + right.asDegrees());
}

constexpr Angle& operator+=(Angle& left, Angle right)
{
    return left = left + right;
}

constexpr Angle operator-(Angle left, Angle right)
{
    return degrees(left.asDegrees() - right.asDegrees());
}

constexpr Angle& operator-=(Angle& left, Angle right)
{
    return left = left - right;
}

constexpr Angle operator*(Angle left, float right)
{
    return degrees(left.asDegrees() * right);
}

constexpr Angle operator*(float left, Angle right)
{
    return right * left;
}

constexpr Angle& operator*=(Angle& left, float right)
{
    return left = left * right;
}

constexpr Angle operator/(Angle left, float right)
{
    assert(right != 0);
    return degrees(left.asDegrees() / right);
}

constexpr Angle& operator/=(Angle& left, float right)
{
    assert(right != 0);
    return left = left / right;
}

constexpr float operator/(Angle left, Angle right)
{
    assert(right.asDegrees() != 0);
    return left.asDegrees() / right.asDegrees();
}

constexpr Angle operator%(Angle left, Angle right)
{
    assert(right.asDegrees() != 0);
    return degrees(priv::positiveRemainder(left.asDegrees(), right.asDegrees()));
}

constexpr Angle& operator%=(Angle& left, Angle right)
{
    assert(right.asDegrees() != 0);
    return left = left % right;
}

inline constexpr Angle Angle::Zero;

} // namespace mv
