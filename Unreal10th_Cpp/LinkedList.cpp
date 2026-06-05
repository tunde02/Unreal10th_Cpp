#include "LinkedList.h"
#include <iostream>

LinkedList::~LinkedList()
{
    Clear();
}

void LinkedList::Add(int InData)
{
    // InData가 들어간 노드를 만든다
    // 맨 마지막으로 이동해서 맨 마지막 노드의 Next를 새 노드로 지정한다
    // Head가 없을 경우 / Tail과 Size에 대한 처리 필요

    ListNode* NewNode = new ListNode{ InData };
    ListNode* p = Head;

    if (Size == 0)
    {
        Head = NewNode;
        Head->Next = Tail;
    }
    else
    {
        while (p->Next != Tail)
        {
            p = p->Next;
        }

        p->Next = NewNode;
        NewNode->Next = Tail;
    }

    Size++;
}

void LinkedList::InsertAt(int InData, int InPosition)
{
    // InData가 들어간 노드를 만든다
    // InPosition 위치까지 이동
    // InPosition 위치에 있는 노드의 Next 주소를 새로 만든 노드의 Next 주소로 설정
    // InPosition 위치에 있는 노드의 Next 주소를 새로 만든 노드의 주소로 설정
    // InPosition이 Size보다 크다면 그냥 Add()

    ListNode* NewNode = new ListNode{ InData };
    ListNode* p = Head;

    if (InPosition <= 0)
    {
        NewNode->Next = p;
        Head = NewNode;
        Size++;
    }
    else if (Size <= InPosition)
    {
        Add(InData);
    }
    else
    {
        int TargetIndex = InPosition - 1;
        for (int i = 0; i < TargetIndex; i++)
        {
            p = p->Next;
        }

        NewNode->Next = p->Next;
        p->Next = NewNode;
        Size++;
    }
}

void LinkedList::Remove(int InData)
{
    // InData를 가진 노드가 있는지 찾는다
    // 찾은 노드의 이전 노드의 Next 주소를 찾은 노드의 Next 주소로 설정
    // 찾은 노드를 delete
    // Head와 Tail일 경우 / InData를 가진 노드가 없을 경우 처리

    if (Size == 1 && Head->Data == InData)
    {
        delete Head;
        Head = nullptr;

        Size--;
    }
    else if (Size > 1)
    {
        ListNode* prev = Head;
        ListNode* p = Head->Next;

        if (prev->Data == InData)
        {
            Head = Head->Next;
            delete prev;
            Size--;
        }
        else
        {
            while (p != nullptr && p->Data != InData)
            {
                prev = p;
                p = p->Next;
            }

            if (p != nullptr)
            {
                prev->Next = p->Next;
                delete p;
                Size--;
            }
        }
    }
}

void LinkedList::RemoveAt(int InPosition)
{
    // 위치 찾아가기
    // 찾은 노드 이전 노드의 Next 주소를 찾은 노드의 Next 주소로 설정
    // 찾은 노드 delete
    // 맨 앞과 뒤일 때 처리. 위치가 없는 경우는 그냥 종료

    ListNode* p = Head;

    if (InPosition <= 0 || Size == 1)
    {
        Remove(Head->Data);
    }
    else if (Size <= InPosition)
    {
        //for (int i = 0; i < Size - 2; i++)
        //{
        //    p = p->Next;
        //}

        //delete p->Next;
        //p->Next = Tail;
        //Size--;
    }
    else
    {
        int TargetIndex = InPosition - 1;
        for (int i = 0; i < TargetIndex; i++)
        {
            p = p->Next;
        }

        ListNode* NextNode = p->Next->Next;
        delete p->Next;
        p->Next = NextNode;
        Size--;
    }
}

ListNode* LinkedList::Search(int InData) const
{
    ListNode* p = Head;

    while (p != nullptr && p->Data != InData)
    {
        p = p->Next;
    }

    return p;
}

void LinkedList::Clear()
{
    ListNode* p = Head;
    while (p != nullptr)
    {
        ListNode* prev = p;
        p = p->Next;
        delete prev;
    }

    Head = nullptr;
    Size = 0;
}

void LinkedList::PrintList() const
{
    if (Head == nullptr)
    {
        printf("리스트가 비어있습니다.\n");
        return;
    }

    printf("리스트 데이터 (Size = %d) : ", Size);

    ListNode* p = Head;
    while (p != Tail)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}
