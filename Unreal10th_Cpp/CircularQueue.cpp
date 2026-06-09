#include "CircularQueue.h"
#include <iostream>

void CircularQueue::Enqueue(int InValue)
{
    if (IsFull())
    {
        printf("[ERROR] 큐가 가득 차 있습니다!\n");
        return;
    }

    if (IsEmpty())
    {
        Front = 0;
    }

    Rear = (Rear + 1) % MaxSize;
    Data[Rear] = InValue;
}

int CircularQueue::Dequeue()
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
        Front = (Front + 1) % MaxSize;
    }

    return Value;
}

void CircularQueue::Print() const
{
    if (IsEmpty())
    {
        printf("[ERROR] 큐가 비어있습니다!\n");
        return;
    }

    printf("[Queue] : ");
    int i = Front;
    printf("%d ", Data[i]);
    while (i != Rear)
    {
        i = (i + 1) % MaxSize;
        printf("%d ", Data[i]);
    }
    printf("\n");
}

int CircularQueue::Peek() const
{
    if (IsEmpty())
    {
        printf("[ERROR] 큐가 비어있습니다!\n");
        return Empty;
    }

    return Data[Front];
}
