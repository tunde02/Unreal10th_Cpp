#pragma once

class DynamicCircularQueue
{
public:
    DynamicCircularQueue();
    DynamicCircularQueue(int InCapacity);
    ~DynamicCircularQueue();

    void Enqueue(int InValue);
    int Dequeue();
    void Print() const;
    int Peek() const;
    void Reserve(int InCapacity);

    static constexpr int InitialCapacity = 10;
    static constexpr int Empty = -1;

private:
    int* Data;
    int Front = Empty;
    int Rear = Empty;
    int Capacity = 0;

public:
    inline bool IsFull() const { return (Rear + 1) % Capacity == Front; }
    inline bool IsEmpty() const { return Front == Empty; }
    inline int GetSize() const { return (Rear - Front + Capacity) % Capacity + 1; }
};
