#pragma once

class DynamicStack
{
public:
    DynamicStack();
    DynamicStack(int InCapacity);
    ~DynamicStack();

    void Reserve(int InCapacity);

    // 스택에 InData를 추가하는 함수
    void Push(int InData);

    // 스택의 Top 위치에 있는 데이터를 꺼내는 함수
    int Pop();

    // Peek 이라고도 부른다
    // Top 위치에 있는 값을 확인만 하는 함수
    int Top() const;

    // 스택이 비어있는지 확인하는 함수. Stack Underflow 방지
    bool IsEmpty() const;

    // 스택의 현재 크기를 반환하는 함수
    int GetSize() const;

private:
    static constexpr int InitialStackCapacity = 10;
    static constexpr int Empty = -1;

    int TopIndex = Empty;
    int Capacity = InitialStackCapacity;
    int* Data;
};

