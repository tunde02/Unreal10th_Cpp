#include "DynamicCircularQueue.h"
#include <iostream>

DynamicCircularQueue::DynamicCircularQueue()
{
    Capacity = InitialCapacity;
    Data = new int[Capacity] {};
}

DynamicCircularQueue::DynamicCircularQueue(int InCapacity)
{
    Capacity = InCapacity;
    Data = new int[Capacity] {};
}

DynamicCircularQueue::~DynamicCircularQueue()
{
    delete[] Data;
    Data = nullptr;
}

void DynamicCircularQueue::Enqueue(int InValue)
{
    if (IsFull())
    {
        printf("[DynamicCircularQueue] : Reallocation! (%d -> %d)\n", Capacity, Capacity * 2);

        Reserve(Capacity * 2);
    }

    if (IsEmpty())
    {
        Front = 0;
    }

    Rear = (Rear + 1) % Capacity;
    Data[Rear] = InValue;
}

int DynamicCircularQueue::Dequeue()
{
    if (IsEmpty())
    {
        printf("[ERROR] 큐가 비어있습니다!\n");
        return Empty;
    }

    int Value = Data[Front];

    if (Front == Rear)
    {
        Front = Empty;
        Rear = Empty;
    }
    else
    {
        Front = (Front + 1) % Capacity;
    }

    return Value;
}

void DynamicCircularQueue::Print() const
{
    if (IsEmpty())
    {
        printf("[ERROR] 큐가 비어있습니다!\n");
        return;
    }

    int i = Front;
    int Size = GetSize();

    if (Size == 1)
    {
        printf("Queue (%d): [ %d ]\n", Size, Data[i]);
    }
    else
    {
        printf("Queue (%d): [ ", Size);
        do
        {
            printf("%d ", Data[i]);
            i = (i + 1) % Capacity;
        } while (i != Rear);
        printf("%d ]\n", Data[i]);
    }
}

int DynamicCircularQueue::Peek() const
{
    if (IsEmpty())
    {
        printf("[ERROR] 큐가 비어있습니다!\n");
        return Empty;
    }

    return Data[Front];
}

void DynamicCircularQueue::Reserve(int InCapacity)
{
    int PrevCapacity = Capacity;
    Capacity = InCapacity;

    int* TempData = Data;
    Data = new int[Capacity] {};

    if (!IsEmpty())
    {
        int i = Front;
        while (i != Rear)
        {
            Data[i] = TempData[i];
            i = (i + 1) % PrevCapacity;
        }
        Data[i] = TempData[i];

    }

    delete[] TempData;
    TempData = nullptr;
}
