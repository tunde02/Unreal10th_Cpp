#pragma once
#include <iostream>
#include <type_traits>

template <typename T>
struct Coordinate
{
    T X;
    T Y;

    Coordinate()
        : X{}, Y{}
    {
    }
    Coordinate(T InX, T InY)
        : X(InX), Y(InY)
    {
    }

    void Print() const
    {
        // std::is_same_v<T, int> : T 타입이 int면 true, 아니면 false
        // if consetexpr : 컴파일 타임에 조건이 true면 코드를 생성하고, 아니면 생성하지 않는다
        // std::is_same_v : 두 타입이 같은지 비교하는 템플릿
        if constexpr (std::is_same_v<T, int>)
        {
            printf("(%d, %d)\n", X, Y);
        }
        else if constexpr (std::is_same_v<T, float>)
        {
            printf("(%f, %f)\n", X, Y);
        }
    }
};

template <typename T>
Coordinate<T> operator+(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
    return Coordinate<T>(Left.X + Right.X, Left.Y + Right.Y);

}

template <typename T>
Coordinate<T> operator-(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
    return Coordinate<T>(Left.X - Right.X, Left.Y - Right.Y);
}

template <typename T>
bool operator==(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
    bool Result = false;

    if constexpr (std::is_same_v<T, float>)
    {
        float diffX = Left.X - Right.X;
        float diffY = Left.Y - Right.Y;

        if (diffX < 0) diffX *= -1;
        if (diffY < 0) diffY *= -1;

        Result = diffX < 0.001f && diffY < 0.001f;
    }
    else
    {
        Result = (Left.X == Right.X) && (Left.Y == Right.Y);
    }

    return Result;
}

template <typename T>
bool operator!=(const Coordinate<T>& Left, const Coordinate<T>& Right)
{
    return !(Left == Right);
}
