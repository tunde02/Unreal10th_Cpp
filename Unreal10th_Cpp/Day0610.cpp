#include "Day0610.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <set>
#include <map>

void Day0610::Day0610_Main()
{
    //TestTemplateClass();
    //TestTree();
    //TestSetSTL();
    TestMapSTL();
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
