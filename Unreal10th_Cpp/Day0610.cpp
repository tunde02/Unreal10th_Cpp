#include "Day0610.h"
#include "BinarySearchTree.h"
#include "TLinkedList.h"
#include "TFixedStack.h"
#include <iostream>
#include <set>
#include <map>

void Day0610::Day0610_Main()
{
    //TestTemplateClass();
    //TestTree();
    //TestSetSTL();
    //TestMapSTL();

    Day0610_Practice();
}

void Day0610::Day0610_Practice()
{
    //TestTemplateLinkedList();
    TestTemplateFixedStack();
}

void Day0610::TestTemplateClass()
{
    Coordinate<int> PositionInt(1, 3);
    Coordinate<float> PositionFloat(0.05f, 5.7f);

    printf("PositionInt : %d, %d\n", PositionInt.X, PositionInt.Y);
    printf("PositionFloat : %f, %f\n", PositionFloat.X, PositionFloat.Y);

    Calculator Calc;

    auto a = Calc.Add(1, 3.5f);
    printf("%f\n", a);
}

void Day0610::TestTree()
{
    BinarySearchTree bst;

    // 데이터 삽입
    printf("=== BST 삽입 ===\n");
    int values[] = { 50, 30, 70, 20, 40, 60, 80 };
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        bst.Insert(values[i]);
        printf("%d 삽입\n", values[i]);
    }

    // 순회 출력
    printf("\n=== 순회 결과 ===\n");
    bst.PrintInOrder();
    bst.PrintPreOrder();
    bst.PrintPostOrder();

    // 검색
    printf("\n=== 검색 ===\n");
    int searchKeys[] = { 40, 25, 80, 100 };
    int searchSize = sizeof(searchKeys) / sizeof(searchKeys[0]);

    for (int i = 0; i < searchSize; i++) {
        TreeNode* found = bst.Search(searchKeys[i]);
        if (found != nullptr) {
            printf("%d: 찾음 (노드 주소: %p)\n", searchKeys[i], found);
        }
        else {
            printf("%d: 없음\n", searchKeys[i]);
        }
    }

    // 삭제
    printf("\n=== 삭제 ===\n");
    int deleteKeys[] = { 20, 30, 50 };
    int deleteSize = sizeof(deleteKeys) / sizeof(deleteKeys[0]);

    for (int i = 0; i < deleteSize; i++) {
        printf("%d 삭제\n", deleteKeys[i]);
        bst.Delete(deleteKeys[i]);
        bst.PrintInOrder();
    }
}

void Day0610::TestSetSTL()
{
    std::set<int> MySet;
    MySet.insert(10);
    MySet.insert(50);
    MySet.insert(30);
    MySet.insert(10);
    PrintSet(MySet);

    //MySet.size();// 크기

    std::set<int>::iterator iter = MySet.find(50);  // 값이 아니라 이터레이터를 리턴
    int findValue = (*iter);

    MySet.erase(30);    // 특정 값을 가진 것을 삭제
    PrintSet(MySet);

    MySet.clear();      // 모두 삭제
    PrintSet(MySet);

    //MySet.empty();    // 비어있는지 아닌지 확인(bool)


    std::set<SetTestData> Data;
    Data.insert(SetTestData(10, 20.0f));
    Data.insert(SetTestData(15, 25.0f));
    Data.insert(SetTestData(25, 20.5f));

    std::set<SetTestDataFail> Data2;
    //Data2.insert(SetTestDataFail(10, 20.0f)); // 사용하려고 하면 <연산자가 오버라이드 되지 않아 비교할 수가 없어서 컴파일 에러를 띄움
    //Data2.insert(SetTestDataFail(15, 25.0f));
    //Data2.insert(SetTestDataFail(25, 20.5f));

    std::set<SetTestDataFunctor, CompareTest> Data3;
    Data3.insert(SetTestDataFunctor(10, 20.0f));
    Data3.insert(SetTestDataFunctor(25, 20.5f));
    Data3.insert(SetTestDataFunctor(15, 25.0f));
}

void Day0610::PrintSet(const std::set<int>& InTarget)
{
    printf("Set 출력 : ");
    for (int Element : InTarget)
    {
        printf("%d ", Element);
    }
    printf("\n");
}

void Day0610::TestMapSTL()
{
    std::map<CharacterType, CharacterData> Characters;
    Characters[CharacterType::Warrior] = { 12,150,0 };

    CharacterData& WarriorData = Characters[CharacterType::Warrior];
    WarriorData.HP = 200;

    // Key가 없는 원소에 접근하면 기본값으로 새로 만들어버림
    CharacterData& Mage = Characters[CharacterType::Mage];
    Mage.Level = 20;

    CharacterData& Bug = Characters[(CharacterType)35];
    int i = 0;

    //std::map<CharacterType, CharacterData>::iterator iter = Characters.find(CharacterType::Thief);
    auto iter = Characters.find(CharacterType::Thief);
    if (iter != Characters.end())
    {
        printf("있다.\n");
    }
    else
    {
        printf("없다.\n");
    }

    Characters.insert(std::pair< CharacterType, CharacterData>(CharacterType::Mage, { 12,150,0 }));

    //for (const auto& pair : Characters)
    //{
    //    pair.first;//키
    //    pair.second;//value
    //}
}

void Day0610::TestTemplateLinkedList()
{
    TLinkedList<float>* MyList = nullptr;
    MyList = new TLinkedList<float>();

    printf("--- 초기 리스트 생성 ---\n");
    MyList->Add(10.1f);
    MyList->Add(20.1f);
    MyList->Add(30.1f);
    MyList->PrintList();

    printf("\n--- 1. InsertAt 테스트 ---\n");
    printf("1-1. 위치가 Size보다 클 때 (마지막에 추가):\n");
    MyList->InsertAt(40.1f, 100);
    MyList->PrintList();
    printf("\n1-2. 정상적인 추가 (위치 0에 5.1 추가, 위치 2에 15.1 추가):\n");
    MyList->InsertAt(5.1f, 0);
    MyList->PrintList();
    MyList->InsertAt(15.1f, 2);
    MyList->PrintList();

    printf("\n--- 2. Remove 테스트 ---\n");
    printf("2-1. 삭제할 노드가 있는 경우 (20.1 삭제):\n");
    MyList->Remove(20.1f);
    MyList->PrintList();
    printf("\n2-2. 삭제할 노드가 없는 경우 (99.1 삭제 시도):\n");
    MyList->Remove(99.1f);
    MyList->PrintList();

    printf("\n--- 3. RemoveAt 테스트 ---\n");
    printf("3-1. 위치가 Size와 같거나 클 때:\n");
    MyList->RemoveAt(5); // 현재 크기는 5이므로, 인덱스 5는 범위를 벗어남
    MyList->RemoveAt(99);
    MyList->PrintList();
    printf("\n3-2. 정상적인 삭제 (위치 1의 10.1 삭제):\n");
    MyList->RemoveAt(1);
    MyList->PrintList();

    printf("\n--- 4. Search 테스트 ---\n");
    printf("4-1. 찾는 노드가 있는 경우 (30.1 탐색):\n");
    float ValueToFind = 30.1f;
    TListNode<float>* FoundNode = MyList->Search(ValueToFind);
    if (FoundNode != nullptr)
    {
        printf("결과: %.1f 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %.1f)\n", ValueToFind, (void*)FoundNode, FoundNode->Data);
    }
    else
    {
        printf("결과: %.1f 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
    }
    printf("\n4-2. 찾는 노드가 없는 경우 (123.1 탐색):\n");
    ValueToFind = 123.1f;
    FoundNode = MyList->Search(ValueToFind);
    if (FoundNode != nullptr)
    {
        printf("결과: %.1f 값을 가진 노드를 찾았습니다.\n", ValueToFind);
    }
    else
    {
        printf("결과: %.1f 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
    }

    printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
    MyList->Clear();
    MyList->PrintList();
    delete MyList;
    MyList = nullptr;
}

void Day0610::TestTemplateFixedStack()
{
    printf("--- TemplateFixedStack<float> 테스트 시작 ---\n\n");

    TFixedStack<float> stack;

    // 1. 초기 상태 테스트
    printf("1. 초기 상태 테스트\n");
    printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
    printf("현재 크기: %d\n", stack.GetSize());
    printf("\n");

    // 2. Push 테스트
    printf("2. Push 테스트\n");
    printf("Push: 10.1\n");
    stack.Push(10.1f);
    printf("Top: %.1f, Size: %d\n", stack.Top(), stack.GetSize());

    printf("Push: 20.1\n");
    stack.Push(20.1f);
    printf("Top: %.1f, Size: %d\n", stack.Top(), stack.GetSize());

    printf("Push: 30.1\n");
    stack.Push(30.1f);
    printf("Top: %.1f, Size: %d\n", stack.Top(), stack.GetSize());
    printf("\n");

    // 3. Pop 테스트
    printf("3. Pop 테스트\n");
    printf("Pop 실행\n");
    stack.Pop();
    printf("Top: %.1f, Size: %d\n", stack.Top(), stack.GetSize());
    printf("\n");

    // 4. 경계 테스트: 스택 오버플로우 (Stack Overflow)
    printf("4. 경계 테스트: 오버플로우\n");
    printf("스택을 가득 채웁니다...\n");
    // 현재 2개의 원소(10, 20)가 있으므로, 8개를 더 추가하면 가득 참 (용량: 10)
    for (int i = 3; i <= 10; ++i) {
        float value = i * 10.0f + 0.1f;
        printf("Push: %.1f\n", value);
        stack.Push(value);
    }
    printf("스택이 꽉 찼나요? %s\n", stack.IsFull() ? "예" : "아니요");
    printf("Top: %.1f, Size: %d\n", stack.Top(), stack.GetSize());

    printf("\n오버플로우 시도: Push 110\n");
    stack.Push(110.1f); // "오류: 스택이 꽉 찼습니다!" 메시지 출력 예상
    printf("Top: %.1f, Size: %d\n", stack.Top(), stack.GetSize()); // 변화 없음
    printf("\n");

    // 5. 경계 테스트: 스택 언더플로우 (Stack Underflow)
    printf("5. 경계 테스트: 언더플로우\n");
    printf("모든 원소를 Pop 합니다...\n");
    while (!stack.IsEmpty()) {
        printf("Popping: %.1f\n", stack.Top());
        stack.Pop();
    }
    printf("스택이 비었나요? %s\n", stack.IsEmpty() ? "예" : "아니요");
    printf("Size: %d\n", stack.GetSize());

    printf("\n언더플로우 시도 (Pop)\n");
    stack.Pop(); // "오류: 스택이 비어있습니다!" 메시지 출력 예상

    printf("\n언더플로우 시도 (Top)\n");
    float topValue = stack.Top(); // "오류: ..." 메시지 출력 예상
    printf("Top 호출 결과: %.1f\n", topValue); // Empty(-1) 값 출력 예상
    printf("\n");

    printf("--- FixedStack 테스트 종료 ---\n");
}
