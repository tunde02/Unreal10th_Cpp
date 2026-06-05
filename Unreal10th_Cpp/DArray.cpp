#include "DArray.h"
#include <iostream>

DArray::DArray()
{
    Capacity = 4;
    Size = 0;
    Data = new int[Capacity] {};
}

DArray::~DArray()
{
    delete[] Data;
    Data = nullptr;
}

void DArray::Reserve(int InCapacity)
{
    delete Data;
    Data = nullptr;

    Capacity = InCapacity;
    Data = new int[Capacity] {};
}

void DArray::PushBack(int InData)
{
    if (Size == Capacity)
    {
        Reallocate();
    }

    Data[Size++] = InData;
}

int DArray::PopBack()
{
    if (Size == 0)
    {
        printf("[ERROR] 배열이 비어 있습니다!!\n");
        return 0;
    }

    int PopValue = Data[--Size];
    Data[Size] = 0;

    return PopValue;
}

void DArray::Reallocate()
{
    printf("Reallocate!\n");
    int* Temp = Data;
    Capacity *= 2;
    Data = new int[Capacity] {};

    for (int i = 0; i < Size; i++)
    {
        Data[i] = Temp[i];
    }

    delete[] Temp;
    Temp = nullptr;
}

void DArray::Print() const
{
    printf("DArray (Size: %d) : ", static_cast<int>(Size));
    for (int i = 0; i < Size; i++)
    {
        printf("%d ", Data[i]);
    }
    printf("\n");
}

void DArray::PrintCapacity() const
{
    printf("DArray (Capacity: %d) : ", static_cast<int>(Capacity));
    for (int i = 0; i < Capacity; i++)
    {
        printf("%d ", Data[i]);
    }
    printf("\n");
}
