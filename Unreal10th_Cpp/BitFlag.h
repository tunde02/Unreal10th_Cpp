#pragma once
#include <type_traits>

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator|(T Left, T Right)
{
    return static_cast<T>(
        static_cast<std::underlying_type_t<T>>(Left)
        | static_cast<std::underlying_type_t<T>>(Right));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator&(T Left, T Right)
{
    return static_cast<T>(
        static_cast<std::underlying_type_t<T>>(Left)
        & static_cast<std::underlying_type_t<T>>(Right));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator^(T Left, T Right)
{
    return static_cast<T>(
        static_cast<std::underlying_type_t<T>>(Left)
        ^ static_cast<std::underlying_type_t<T>>(Right));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T> operator~(T InValue)
{
    return static_cast<T>(~static_cast<std::underlying_type_t<T>>(InValue));
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T&> operator|=(T& Left, T Right)
{
    Left = Left | Right;
    return Left;
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T&> operator&=(T& Left, T Right)
{
    Left = Left & Right;
    return Left;
}

template <typename T>
typename std::enable_if_t<std::is_enum_v<T>, T&> operator^=(T& Left, T Right)
{
    Left = Left ^ Right;
    return Left;
}

enum class TestEnumClass : uint8_t
{
    Up = 1 << 0,
    Down = 1 << 1,
    Left = 1 << 2,
    Right = 1 << 3
};
