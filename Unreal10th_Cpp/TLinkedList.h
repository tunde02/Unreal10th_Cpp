#pragma once
#include <iostream>
#include <type_traits>
#include <cmath>
#include <limits>
#include <concepts> // C++ 20 이상부터 가능

template <typename T>
struct TListNode
{
    T Data = 0;
    TListNode<T>* Next = nullptr;

    TListNode(T InData) : Data(InData) {}
};

template <typename T>
class TLinkedList
{
public:
    TLinkedList() = default;
    ~TLinkedList();

    bool IsEqual(const T& Left, const T& Right) const;
    void Add(T InData);
    void InsertAt(T InData, int InPosition);
    void Remove(T InData);
    void RemoveAt(int InPosition);
    TListNode<T>* Search(T InData) const;
    void Clear();
    void PrintList() const;

private:
    TListNode<T>* Head = nullptr; // 시작 노드 (nullptr이면 리스트가 비어 있다는 의미)
    TListNode<T>* Tail = nullptr; // 마지막 노드
    int Size = 0; // Head부터 이어지는 전체 노드의 개수
};

template <typename T>
TLinkedList<T>::~TLinkedList()
{
    Clear();
}

template <typename T>
bool TLinkedList<T>::IsEqual(const T& Left, const T& Right) const
{
    //if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>)
    if constexpr (std::is_floating_point_v<T>)
    {
        return std::abs(Left - Right) <= std::numeric_limits<T>::epsilon() * std::max(std::abs(Left), std::abs(Right));
    }
    else
    {
        return Left == Right;
    }
}

/*
// C++20 이상부터 가능한 <concepts> 활용 특수화
template <std::floating_point T>
bool IsEqual(T Left, T Right)
{
    return std::abs(Left - Right) <= std::numeric_limits<T>::epsilon() * std::max(std::abs(Left), std::abs(Right));
}

template <std::integral T>
bool IsEqual(T Left, T Right)
{
    return Left == Right;
}
*/

template <typename T>
void TLinkedList<T>::Add(T InData)
{
    // InData가 들어간 노드를 만든다
    TListNode<T>* NewNode = new TListNode<T>(InData);

    if (Head == nullptr)
    {
        // 처음 넣을 때
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        // 맨 마지막으로 이동해서 맨 마지막 노드의 Next를 새 노드로 지정한다.
        Tail->Next = NewNode;
        Tail = NewNode;
    }

    Size++;
}

template <typename T>
void TLinkedList<T>::InsertAt(T InData, int InPosition)
{
    if (InPosition > Size)
    {
        InPosition = Size;
    }

    if (InPosition == Size)
    {
        Add(InData);    // 어차피 마지막에 추가할거면 Tail을 활용하는게 빠르다.
        return;
    }

    // InData가 들어간 노드를 만든다
    TListNode<T>* NewNode = new TListNode<T>(InData);
    if (InPosition == 0)
    {
        NewNode->Next = Head;
        Head = NewNode;
    }
    else
    {
        // 포지션까지 Head에서 시작해서 Next를 계속 타고 이동한다.
        TListNode<T>* PrevNode = Head;
        TListNode<T>* Current = Head;
        for (int i = 0; i < InPosition; i++)
        {
            PrevNode = Current;
            Current = Current->Next;
        }
        PrevNode->Next = NewNode;   // 포지션 위치에 있는 노드의 앞노드의 Next 주소를 새로 만든 노드로 설정
        NewNode->Next = Current;    // 새 노드의 다음 주소를 포지션 위치에 있는 노드의 주소로 설정
    }

    Size++;
}

template <typename T>
void TLinkedList<T>::Remove(T InData)
{
    if (Head == nullptr)
        return;

    // InData를 가진 노드가 있는지 Head부터 찾는다.
    TListNode<T>* NodeToDelete = nullptr;
    TListNode<T>* PrevNode = nullptr;

    if (IsEqual(Head->Data, InData))
    {
        NodeToDelete = Head;
        Head = Head->Next;
        if (Head == nullptr)
        {
            Tail = nullptr;
        }
    }
    else
    {
        PrevNode = Head;
        while (PrevNode->Next != nullptr && PrevNode->Next->Data != InData)
        {
            // 찾는 데이터를 가진 노드의 앞노드 찾기
            PrevNode = PrevNode->Next;
        }

        if (PrevNode->Next != nullptr)
        {
            // 찾은 노드의 앞에 있는 노드의 Next를 찾은 노드의 Next에 저장된 주소로 변경한다.
            NodeToDelete = PrevNode->Next;
            PrevNode->Next = NodeToDelete->Next;
            if (NodeToDelete == Tail)
            {
                Tail = PrevNode;
            }
        }
    }

    if (NodeToDelete != nullptr)
    {
        // 찾은 노드를 delete
        delete NodeToDelete;
        NodeToDelete = nullptr;
        Size--;
    }
    else
    {
        std::cout << "오류 : " << InData << " 값을 가진 노드가 없습니다." << std::endl;
    }
}

template <typename T>
void TLinkedList<T>::RemoveAt(int InPosition)
{
    if (InPosition >= Size)
    {
        printf("오류 : %d 위치는 리스트의 범위를 벗어납니다.(현재 크기:%d)\n", InPosition, Size);
        return;     //위치가 없는 경우는 그냥 종료
    }

    TListNode<T>* NodeToDelete = nullptr;
    if (InPosition == 0)
    {
        // 특수 처리(맨 앞이다)
        NodeToDelete = Head;
        Head = Head->Next;
        if (Head == nullptr)
        {
            Tail = nullptr;
        }
    }
    else
    {
        // 위치 찾기
        TListNode<T>* PrevNode = Head;
        int TargetIndex = InPosition - 1;       // 지울 노드의 앞쪽노드(PrevNode)까지 가기 위해서
        for (int i = 0; i < TargetIndex; i++)
        {
            PrevNode = PrevNode->Next;
        }
        NodeToDelete = PrevNode->Next;
        PrevNode->Next = NodeToDelete->Next;    // 찾은 노드 앞 노드의 Next를 찾은 노드의 Next로 변경
        if (NodeToDelete == Tail)
        {
            //PrevNode->Next = nullptr;
            Tail = PrevNode;
            Tail->Next = nullptr;
        }
    }
    // 찾은 노드 delete
    delete NodeToDelete;
    NodeToDelete = nullptr;
    Size--;
}

template <typename T>
TListNode<T>* TLinkedList<T>::Search(T InData) const
{
    // InData와 같은 값을 가지는 노드 찾기
    TListNode<T>* Current = Head;
    while (Current != nullptr)
    {
        if (IsEqual(Current->Data, InData))
        {
            break;
        }
        Current = Current->Next;
    }
    return Current;
}

template <typename T>
void TLinkedList<T>::Clear()
{
    while (Head)
    {
        RemoveAt(0);
    }
}

template <typename T>
void TLinkedList<T>::PrintList() const
{
    if (Head == nullptr && Size == 0)
    {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    printf("리스트(크기:%d) : ", Size);
    TListNode<T>* Current = Head;
    while (Current != nullptr)
    {
        // int, unsigned int, float, double, etc
        if constexpr (std::is_same_v<T, int>) {
            printf("%d -> ", Current->Data);
        }
        else if constexpr (std::is_same_v<T, unsigned int>) {
            printf("%u -> ", Current->Data);
        }
        else if constexpr (std::is_same_v<T, float>) {
            printf("%.1f -> ", Current->Data);
        }
        else if constexpr (std::is_same_v<T, double>) {
            printf("%lf -> ", Current->Data);
        }
        else {
            std::cout << Current->Data << " -> ";
        }

        Current = Current->Next;
    }
    printf("nullptr\n");
}
