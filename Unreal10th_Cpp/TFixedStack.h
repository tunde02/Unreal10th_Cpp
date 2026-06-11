#pragma once
#include <iostream>
#include <type_traits>

template <typename T, int Capacity = 10>
class TFixedStack
{
public:
    void Push(T InValue);
    T Pop();
    T Top() const;

    inline bool IsFull() const { return TopIndex == (Capacity - 1); }
    inline bool IsEmpty() const { return TopIndex == Empty; }
    inline int GetSize() const { return TopIndex + 1; }

private:
    static constexpr int Empty = -1;

    T Data[Capacity];
    int TopIndex = Empty;
};

template <typename T, int Capaticy>
void TFixedStack<T, Capaticy>::Push(T InValue)
{
    if (IsFull())
    {
        printf("오류: 스택이 꽉 찼습니다! (Stack Overflow)\n");
        return;
    }

    TopIndex++;
    Data[TopIndex] = InValue;
}

template <typename T, int Capaticy>
T TFixedStack<T, Capaticy>::Pop()
{
    if (IsEmpty())
    {
        printf("오류: 스택이 비어있습니다! (Stack Underflow)\n");
        return {};
    }

    T Result = Data[TopIndex];
    TopIndex--;
    return Result;
}

template <typename T, int Capaticy>
T TFixedStack<T, Capaticy>::Top() const
{
    if (IsEmpty())
    {
        printf("오류: 스택이 비어있습니다! 값을 반환할 수 없습니다.\n");
        return {};
    }

    return Data[TopIndex];
}
