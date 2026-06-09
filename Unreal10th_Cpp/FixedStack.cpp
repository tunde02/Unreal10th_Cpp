#include "FixedStack.h"
#include <iostream>

void FixedStack::Push(int InData)
{
    if (IsFull())
    {
        printf("[ERROR] 스택이 가득 차있습니다!\n");
    }
    else
    {
        Data[++TopIndex] = InData;
    }
}

int FixedStack::Pop()
{
    int OutData = 0;

    if (IsEmpty())
    {
        printf("[ERROR] 스택이 비어 있습니다!\n");
    }
    else
    {
        OutData = Data[TopIndex--];
    }

    return OutData;
}

int FixedStack::Top() const
{
    return Data[TopIndex];
}

bool FixedStack::IsFull() const
{
    return TopIndex + 1 == StackCapacity;
}

bool FixedStack::IsEmpty() const
{
    return TopIndex == Empty;
}

int FixedStack::GetSize() const
{
    return TopIndex + 1;
}
