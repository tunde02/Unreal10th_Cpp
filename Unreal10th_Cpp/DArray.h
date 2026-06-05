#pragma once

// 실습 - std::vector 비슷하게 만들기
// - int 저장
// - Reserve : Capacity 설정
// - PushBack : 뒤에 추가하기
// - PopBack : 뒤에 제거하기
// - Print : 내용 출력하기
// - Reallocate : PushBack으로 Capacity가 넘쳤을 때 처리하는 함수

class DArray
{
public:
    DArray();
    ~DArray();

    int& operator[](size_t Index) const { return Data[Index]; }

    void Reserve(int InCapacity);
    void PushBack(int InData);
    int PopBack();
    void Reallocate();
    void Print() const;
    void PrintCapacity() const;

private:
    size_t Capacity = 0;
    size_t Size = 0;
    int* Data = nullptr;
};
