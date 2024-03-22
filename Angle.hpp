#pragma once

namespace mv
{

class Angle
{
public:
    constexpr Angle();
    [[nodiscard]] constexpr float asDegrees() const;
    [[nodiscard]] constexpr float asRadians() const;
    [[nodiscard]] constexpr Angle wrapSigned() const;
    [[nodiscard]] constexpr Angle wrapUnsigned() const;
    static const Angle Zero;
private:
    friend constexpr Angle degrees(float angle);
    friend constexpr Angle radians(float angle);
    constexpr explicit Angle(float degrees);
private:
    float mDegrees{};
};

[[nodiscard]] constexpr Angle degrees(float angle);
[[nodiscard]] constexpr Angle radians(float angle);
[[nodiscard]] constexpr bool operator==(Angle left,  Angle right);
[[nodiscard]] constexpr bool operator!=(Angle left, Angle right);
[[nodiscard]] constexpr bool operator<(Angle left, Angle right);
[[nodiscard]] constexpr bool operator>(Angle left, Angle right);
[[nodiscard]] constexpr bool operator<=(Angle left, Angle right);
[[nodiscard]] constexpr bool operator>=(Angle left, Angle right);
[[nodiscard]] constexpr Angle operator-(Angle right);
[[nodiscard]] constexpr Angle operator+(Angle left, Angle right);
              constexpr Angle& operator+=(Angle&left, Angle right);
[[nodiscard]] constexpr Angle operator-(Angle left, Angle right);
              constexpr Angle& operator-=(Angle& left, Angle right);
[[nodiscard]] constexpr Angle operator*(Angle left, float right);
[[nodiscard]] constexpr Angle operator*(float left, Angle right);
              constexpr Angle& operator*=(Angle& left, float right);
[[nodiscard]] constexpr Angle operator/(Angle left, float right);
              constexpr Angle& operator/=(Angle& left, float right);
[[nodiscard]] constexpr float operator/(Angle left, Angle right);
[[nodiscard]] constexpr Angle operator%(Angle left, Angle right);
              constexpr Angle& operator%=(Angle& left, Angle right);
} // namespace mv

#include "Angle.inl"
