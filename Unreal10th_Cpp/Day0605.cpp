#include "Day0605.h"
#include "DArray.h"
#include <list>
#include <vector>

void Day0605::Interface()
{
    IFlyable* List[2];
    Test0605_1 Test1;
    Test0605_2 Test2;

    List[0] = &Test1;
    List[1] = &Test2;
}

void Day0605::EnumClass()
{
    enum Color1 { Red, Green, Blue };
    //enum TrafficLight1 { Red, Yellow, Green }; // 재정의 오류
    enum Fruit1 { Apple, Orange, Banana };

    Color1 MyColor1 = Red;
    Fruit1 MyFruit1 = Apple;
    if (MyColor1 == MyFruit1) {
        // 일반 enum은 색상과 과일이 같다가 성립해버림
        printf("둘은 같습니다.\n");
    }

    enum class Color2 { Red, Green, Blue };
    enum class Fruit2 { Apple, Orange, Banana };

    Color2 MyColor2 = Color2::Red;
    Fruit2 MyFruit2 = Fruit2::Apple;
    //if (MyColor2 == MyFruit2) {
    //    enum class는 이런 비교 자체가 문법적으로 불가능해짐.별도의 타입이기 때문에
    //}

    Direction Dir = Direction::Up | Direction::Down;
    Dir |= Direction::Left;
    Dir &= Direction::Up;

    int a = 0;
}

void Day0605::TestList()
{
    LinkedList* MyList = nullptr;
    MyList = new LinkedList();

    printf("--- 초기 리스트 생성 ---\n");
    MyList->Add(10);
    MyList->Add(20);
    MyList->Add(30);
    MyList->PrintList();

    printf("\n--- 1. InsertAt 테스트 ---\n");
    printf("1-1. 위치가 Size보다 클 때 (마지막에 40 추가):\n");
    MyList->InsertAt(40, 100);
    MyList->PrintList();
    printf("\n1-2. 정상적인 추가 (위치 0에 5 추가):\n");
    MyList->InsertAt(5, 0);
    MyList->PrintList();
#if 0
    printf("\n1-3. 정상적인 추가 (위치 2에 13 추가):\n");
    MyList->InsertAt(13, 2);
    MyList->PrintList();
#endif

    printf("\n--- 2. Remove 테스트 ---\n");
    printf("2-1. 삭제할 노드가 있는 경우 (20 삭제):\n");
    MyList->Remove(20);
    MyList->PrintList();
    printf("\n2-2. 삭제할 노드가 없는 경우 (99 삭제 시도):\n");
    MyList->Remove(99);
    MyList->PrintList();
#if 0
    MyList->Remove(10);
    MyList->PrintList();
    MyList->Remove(40);
    MyList->PrintList();
    MyList->Remove(5);
    MyList->PrintList();
    MyList->Remove(30);
    MyList->PrintList();
    MyList->Remove(13);
    MyList->PrintList();
#endif

    printf("\n--- 3. RemoveAt 테스트 ---\n");
    printf("3-1. 위치가 Size와 같거나 클 때:\n");
    MyList->RemoveAt(4);
    MyList->PrintList();
    MyList->RemoveAt(99);
    MyList->PrintList();
    printf("3-2. 정상적인 삭제 (위치 1의 10 삭제):\n");
    MyList->RemoveAt(1);
    MyList->PrintList();
#if 0
    MyList->RemoveAt(1);
    MyList->PrintList();
    MyList->RemoveAt(1);
    MyList->PrintList();
#endif

    printf("\n--- 4. Search 테스트 ---\n");
    printf("4-1. 찾는 노드가 있는 경우 (30 탐색):\n");
    int ValueToFind = 30;
    ListNode* FoundNode = MyList->Search(ValueToFind);
    if (FoundNode != nullptr)
    {
        printf("결과: %d 값을 가진 노드를 찾았습니다. (주소: %p, 데이터: %d)\n", ValueToFind, (void*)FoundNode, FoundNode->Data);
    }
    else
    {
        printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
    }
    printf("\n4-2. 찾는 노드가 없는 경우 (123 탐색):\n");
    ValueToFind = 123;
    FoundNode = MyList->Search(ValueToFind);
    if (FoundNode != nullptr)
    {
        printf("결과: %d 값을 가진 노드를 찾았습니다.\n", ValueToFind);
    }
    else
    {
        printf("결과: %d 값을 가진 노드를 찾지 못했습니다.\n", ValueToFind);
    }

    printf("\n--- 프로그램 종료 (소멸자 호출) ---\n");
    MyList->Clear();
    MyList->PrintList();

    delete MyList;
    MyList = nullptr;
}

void Day0605::Test_STL_List()
{
    std::list<int> IntList;
    std::list<float> FloatList;

    IntList.push_back(10);
    IntList.push_back(20);
    IntList.push_front(30);

    std::list<int>::iterator Iter = IntList.begin();
    auto Iter2 = IntList.begin();
    int Data = *Iter;

    // IntList.insert(++IntList.begin(), 100);
    // IntList.remove(100);
    // IntList.erase(); // ~= RemoveAt()

    // 일반적인 STL 데이터 컨테이너 순회법
    // begin()은 시작 위치
    // end()는 끝위치가 아니라, 끝 다음 위치(nullptr)이다.
    for (auto iter = IntList.begin(); iter != IntList.end(); iter++)
    {
        printf("%d ", *iter);
    }
    printf("\n");

}

void Day0605::Test_STL_Vector()
{
    //std::vector<int> Array;

    //Array.push_back(10); // 뒤에 추가만 하는 건 꽤 빠르다
    //Array.push_back(20);
    //Array.push_back(30);

    //printf("%d\n", Array[1]); // 랜덤 액세스가 가능하다
    //Array.pop_back();

    DArray MyArray;

    printf("=== [0. DArray 선언] ===\n");
    MyArray.Print();
    MyArray.PrintCapacity();

    printf("\n=== [1. PushBack 10, 20, 30] ===\n");
    MyArray.PushBack(10);
    MyArray.PushBack(20);
    MyArray.PushBack(30);
    MyArray.Print();
    MyArray.PrintCapacity();

    printf("\n=== [2. PopBack] ===\n");
    MyArray.PopBack();
    MyArray.Print();
    MyArray.PrintCapacity();

    printf("\n=== [3. PopBack] ===\n");
    MyArray.PopBack();
    MyArray.Print();
    MyArray.PrintCapacity();

    printf("\n=== [4. Reallocate() - PushBack 20, 30, 40, 50, 60, 70, 80, 90, 100] ===\n");
    MyArray.PushBack(20);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(30);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(40);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(50);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(60);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(70);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(80);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(90);
    MyArray.Print();
    MyArray.PrintCapacity();
    MyArray.PushBack(100);
    MyArray.Print();
    MyArray.PrintCapacity();

    DArray MyArray2;

    printf("\n=== [5. Reserve() - Reserve(8), PushBack 10, 20, 30, 40, 50] ===\n");
    MyArray2.Reserve(8);

    MyArray2.PushBack(10);
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PushBack(20);
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PushBack(30);
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PushBack(40);
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PushBack(50);
    MyArray2.Print();
    MyArray2.PrintCapacity();

    printf("\n=== [6. 모든 원소 제거 - PopBack() x 6] ===\n");
    MyArray2.PopBack();
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PopBack();
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PopBack();
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PopBack();
    MyArray2.Print();
    MyArray2.PrintCapacity();
    MyArray2.PopBack();
    MyArray2.Print();
    MyArray2.PrintCapacity();

    // 빈 배열 원소 제거
    MyArray2.PopBack();
    MyArray2.Print();
    MyArray2.PrintCapacity();
}
