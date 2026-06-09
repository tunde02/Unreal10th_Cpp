#include "DynamicStack.h"
#include <iostream>

DynamicStack::DynamicStack()
{
    Data = new int[InitialStackCapacity] {};
}

DynamicStack::DynamicStack(int InCapacity)
{
    Capacity = InCapacity;
    Data = new int[Capacity] {};
}

DynamicStack::~DynamicStack()
{
    delete[] Data;
    Data = nullptr;
}

void DynamicStack::Reserve(int InCapacity)
{
    Capacity = InCapacity;

    int* PrevData = Data;
    Data = new int[Capacity] {};

    int Size = GetSize();
    for (int i = 0; i < Size; i++)
    {
        Data[i] = PrevData[i];
    }

    delete[] PrevData;
    PrevData = nullptr;
}

void DynamicStack::Push(int InData)
{
    if (TopIndex + 1 >= Capacity)
    {
        printf("[DynamicStack] : Reallocation! (%d -> %d)\n", Capacity, Capacity * 2);
        Reserve(Capacity * 2);
    }

    Data[++TopIndex] = InData;
}

int DynamicStack::Pop()
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

int DynamicStack::Top() const
{
    if (IsEmpty())
    {
        printf("[ERROR] 스택이 비어 있습니다!\n");
        return Empty;
    }

    return Data[TopIndex];
}

bool DynamicStack::IsEmpty() const
{
    return TopIndex == Empty;
}

int DynamicStack::GetSize() const
{
    return TopIndex + 1;
}
