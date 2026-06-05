#pragma once

struct ListNode
{
    int Data = 0; // 데이터 부분
    ListNode* Next = nullptr; // 링크 부분

    ListNode(int InData) : Data(InData) {}
};

class LinkedList
{
public:
    LinkedList() = default;
    ~LinkedList();

    // 리스트의 마지막에 데이터를 추가하는 함수
    void Add(int InData);

    // 리스트의 중간에 데이터를 추가하는 함수
    void InsertAt(int InData, int InPosition);

    // 특정 데이터를 가지는 노드를 제거하는 함수
    void Remove(int InData);

    // 특정 위치의 노드를 제거하는 함수
    void RemoveAt(int InPosition);

    // 특정 데이터가 있는지 확인하는 함수
    ListNode* Search(int InData) const;

    // 모든 노드를 제거하는 함수
    void Clear();

    // 리스트의 현재 상황을 출력하는 함수
    void PrintList() const;

private:
    ListNode* Head = nullptr; // 시작 노드 (nullptr이면 리스트가 비어 있다는 의미)
    ListNode* Tail = nullptr; // 마지막 노드
    int Size = 0; // Head부터 이어지는 전체 노드의 개수
};

