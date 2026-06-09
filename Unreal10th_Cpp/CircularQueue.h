#pragma once

class CircularQueue
{
public:
    void Enqueue(int InValue);
    int Dequeue();
    void Print() const;
    int Peek() const;

    static constexpr int MaxSize = 10;
    static constexpr int Empty = -1;

private:
    int Data[MaxSize];
    int Front = Empty;
    int Rear = Empty;

public:
    inline bool IsFull() const { return (Rear + 1) % MaxSize == Front; }
    inline bool IsEmpty() const { return Front == Empty; }
    inline int GetSize() const { return (Rear - Front + MaxSize) % MaxSize + 1; }
};
