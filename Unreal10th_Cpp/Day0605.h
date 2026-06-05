#pragma once
#include "Day0602.h"
#include <type_traits>

class Day0605
{
public:
    void Interface();
    void EnumClass();
};

class Test0605_1 : public IFlyable
{
public:
    virtual void Fly() override {}
};

class Test0605_2 : public IFlyable
{
public:
    virtual void Fly() override {}
};

enum class Direction : uint8_t { Up = 1 << 0, Down = 1 << 1, Left = 1 << 2, Right = 1 << 3 };

using DirectionType = std::underlying_type_t<Direction>;

inline Direction operator|(Direction Left, Direction Right) {
    return static_cast<Direction>(static_cast<DirectionType>(Left) | static_cast<DirectionType>(Right));
}

inline Direction operator&(Direction Left, Direction Right) {
    return static_cast<Direction>(static_cast<DirectionType>(Left) & static_cast<DirectionType>(Right));
}

inline Direction operator~(Direction InDirection) {
    return static_cast<Direction>(~static_cast<DirectionType>(InDirection));
}

inline Direction& operator|=(Direction& Left, Direction Right) {
    Left = Left | Right;
    return Left;
}

inline Direction& operator&=(Direction& Left, Direction Right) {
    Left = Left & Right;
    return Left;
}

