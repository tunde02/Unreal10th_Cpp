#include "Day0609.h"
#include "FixedStack.h"
#include "DynamicStack.h"
#include "CircularQueue.h"
#include "DynamicCircularQueue.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>

void Day0609::Day0609_Main()
{
    //Day0609_Stack();
    //Day0609_Queue();
    //TestStack();
    TestDynamicQueue();
}

void Day0609::Day0609_Stack()
{
    // 간단 실습
    // 1. FixedStack 구현하기
    // 2. 문자열을 입력받아서 거꾸로 출력하기 (FixedStack, std::stack 둘 다 해보기)

    FixedStack TestStack;
    TestStack.Push(10);
    TestStack.Push(20);
    TestStack.Push(30);
    TestStack.Push(40);
    TestStack.Push(50);

    printf("Pop : %d\n", TestStack.Pop());
    printf("Pop : %d\n", TestStack.Pop());
    printf("Pop : %d\n", TestStack.Pop());
    printf("Pop : %d\n", TestStack.Pop());
    printf("Pop : %d\n", TestStack.Pop());
    printf("Pop : %d\n", TestStack.Pop());

    printf("\n------------------------------\n\n");

    FixedStack StringStack;
    printf("문자열을 입력하세요 (10글자 제한) : ");
    std::string Input;
    std::getline(std::cin, Input);

    size_t StringSize = Input.size();
    for (size_t i = 0; i < StringSize; i++)
    {
        StringStack.Push(Input[i]);
    }

    printf("거꾸로된 문자열 : ");
    for (size_t i = 0; i < StringSize; i++)
    {
        printf("%c", StringStack.Pop());
    }
    printf("\n");

    std::stack<char> StringStack2;
    printf("문자열을 입력하세요 : ");
    std::getline(std::cin, Input);

    size_t StringSize2 = Input.size();
    for (size_t i = 0; i < StringSize2; i++)
    {

        StringStack2.push(Input[i]);
    }

    printf("거꾸로된 문자열 : ");
    for (size_t i = 0; i < StringSize2; i++)
    {
        char Value = StringStack2.top();
        StringStack2.pop();
        printf("%c", Value);
    }
    printf("\n");

    printf("\n------------------------------\n\n");

    DynamicStack dynamicStack;

    dynamicStack.Push(10);
    dynamicStack.Push(20);
    dynamicStack.Push(30);
    dynamicStack.Push(40);
    dynamicStack.Push(50);
    dynamicStack.Push(60);
    dynamicStack.Push(70);
    dynamicStack.Push(80);
    dynamicStack.Push(90);
    dynamicStack.Push(100);
    dynamicStack.Push(110);

    int a = 0;
}

void Day0609::Day0609_Queue()
{
    //TestQueue();
    //TestQueueSTL();
    TestDynamicQueue();
}

void Day0609::TestStack()
{
    printf("--- DynamicStack 테스트 시작 ---\n\n");

    DynamicStack stack;

    // 1. 초기 상태 테스트
    printf("1. 초기 상태 테스트\n");
    printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
    printf("현재 크기: %d\n", stack.GetSize());
    printf("\n");

    // 2. Push 테스트
    printf("2. Push 테스트\n");
    printf("Push: 10\n");
    stack.Push(10);
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());

    printf("Push: 20\n");
    stack.Push(20);
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());

    printf("Push: 30\n");
    stack.Push(30);
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());
    printf("\n");

    // 3. Pop 테스트
    printf("3. Pop 테스트\n");
    printf("Pop 실행\n");
    stack.Pop();
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());
    printf("\n");

    // 4. 경계 테스트: 스택 오버플로우 (Stack Overflow)
    printf("4. 경계 테스트: 오버플로우\n");
    printf("스택을 가득 채웁니다...\n");
    // 현재 2개의 원소(10, 20)가 있으므로, 8개를 더 추가하면 가득 참 (용량: 10)
    for (int i = 3; i <= 10; ++i) {
        int value = i * 10;
        printf("Push: %d\n", value);
        stack.Push(value);
    }
    //printf("스택이 꽉 찼나요? %s\n", stack.IsFull() ? "예" : "아니요");
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize());

    printf("\n오버플로우 시도: Push 110\n");
    stack.Push(110); // "오류: 스택이 꽉 찼습니다!" 메시지 출력 예상
    printf("Top: %d, Size: %d\n", stack.Top(), stack.GetSize()); // 변화 없음
    printf("\n");

    // 5. 경계 테스트: 스택 언더플로우 (Stack Underflow)
    printf("5. 경계 테스트: 언더플로우\n");
    printf("모든 원소를 Pop 합니다...\n");
    while (!stack.IsEmpty()) {
        printf("Popping: %d\n", stack.Top());
        stack.Pop();
    }
    printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
    printf("Size: %d\n", stack.GetSize());

    printf("\n언더플로우 시도 (Pop)\n");
    stack.Pop(); // "오류: 스택이 비어있습니다!" 메시지 출력 예상

    printf("\n언더플로우 시도 (Top)\n");
    int topValue = stack.Top(); // "오류: ..." 메시지 출력 예상
    printf("Top 호출 결과: %d\n", topValue); // Empty(-1) 값 출력 예상
    printf("\n");

    printf("--- FixedStack 테스트 종료 ---\n");
}

void Day0609::TestQueue()
{
    // 크기가 10으로 고정된 큐 객체를 생성합니다.
    CircularQueue Queue;
    printf("크기가 %u인 큐가 생성되었습니다.\n", CircularQueue::MaxSize);

    int Choice, Value;

    while (true)
    {
        printf("\n--- 메뉴 ---\n");
        printf("1. 인큐 (Enqueue)\n");
        printf("2. 디큐 (Dequeue)\n");
        printf("3. 피크 (Peek)\n");
        printf("4. 출력 (Print)\n");
        printf("5. 종료\n");
        printf("선택: ");

        std::cin >> Choice;

        switch (Choice)
        {
            case 1:
                printf("큐에 추가할 정수를 입력하세요: ");
                std::cin >> Value;
                Queue.Enqueue(Value);
                break;
            case 2:
                Queue.Dequeue();
                break;
            case 3:
            {
                int FrontValue = Queue.Peek();
                if (FrontValue != CircularQueue::Empty)
                {
                    printf("큐의 맨 앞 데이터: %d\n", FrontValue);
                }
            }
            break;
            case 4:
                Queue.Print();
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                return;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
                break;
        }
    }
}

void Day0609::TestQueueSTL()
{
    std::queue<float> TestQueue;
    TestQueue.push(1.1f);
    TestQueue.push(2.1f);
    TestQueue.push(3.1f);

    printf("STL Queue : [");
    while (!TestQueue.empty())
    {
        printf("%.1f ", TestQueue.front());
        TestQueue.pop();
    }
    printf("]\n");
}

void Day0609::TestDynamicQueue()
{
    int Capacity = 4;
    DynamicCircularQueue Queue(Capacity);
    printf("크기가 %u인 큐가 생성되었습니다.\n", Capacity);

    int Choice, Value;

    while (true)
    {
        printf("\n--- 메뉴 ---\n");
        printf("1. 인큐 (Enqueue)\n");
        printf("2. 디큐 (Dequeue)\n");
        printf("3. 피크 (Peek)\n");
        printf("4. 출력 (Print)\n");
        printf("5. 종료\n");
        printf("선택: ");

        std::cin >> Choice;

        switch (Choice)
        {
            case 1:
                printf("큐에 추가할 정수를 입력하세요: ");
                std::cin >> Value;
                Queue.Enqueue(Value);
                break;
            case 2:
                Queue.Dequeue();
                break;
            case 3:
            {
                int FrontValue = Queue.Peek();
                if (FrontValue != DynamicCircularQueue::Empty)
                {
                    printf("큐의 맨 앞 데이터: %d\n", FrontValue);
                }
            }
            break;
            case 4:
                Queue.Print();
                break;
            case 5:
                printf("프로그램을 종료합니다.\n");
                return;
            default:
                printf("잘못된 선택입니다. 다시 시도하세요.\n");
                break;
        }
    }
}
