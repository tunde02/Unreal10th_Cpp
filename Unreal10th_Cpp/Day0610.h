#pragma once
#include "Coordinate.h"
#include <type_traits>
#include <stdexcept>
#include <set>

class Day0610
{
public:
    void Day0610_Main();
    void Day0610_Practice();

private:
    void TestTemplateClass();
    void TestTree();
    void TestSetSTL();
    void PrintSet(const std::set<int>& InTarget);
    void TestMapSTL();

    void TestTemplateLinkedList();
    void TestTemplateFixedStack();
};


// 간단 실습
// 템플릿을 이용한 계산기 클래스 만들기
//  - Add, Sub, Multiply, Divide,
//  - int * int, float * int, int * float, float * float 가능해야함
class Calculator
{
public:
    // C++은 자동으로 더 큰 타입으로 변환하여 반환해준다

    template <typename T1, typename T2>
    auto Add(T1 Left, T2 Right) const
    {
        return Left + Right;
    }

    template <typename T1, typename T2>
    auto Sub(T1 Left, T2 Right) const
    {
        return Left - Right;
    }

    template <typename T1, typename T2>
    auto Multiply(T1 Left, T2 Right) const
    {
        return Left * Right;
    }

    template <typename T1, typename T2>
    auto Divide(T1 Left, T2 Right) const
    {
        if (Right == 0)
        {
            throw std::size_t("Calculator.Divide() - 0으로 나눌 수 없습니다!\n");
        }

        return Left / Right;
    }
};

struct SetTestData
{
    int a = 0;
    float b = 0;

    SetTestData() = default;
    SetTestData(int InA, float InB) : a(InA), b(InB) {};

    bool operator<(const SetTestData& InOther) const
    {
        return a < InOther.a;
    }
};

struct SetTestDataFail
{
    int a = 0;
    float b = 0;

    SetTestDataFail() = default;
    SetTestDataFail(int InA, float InB) : a(InA), b(InB) {};
};

struct SetTestDataFunctor
{
    int a = 0;
    float b = 0;

    SetTestDataFunctor() = default;
    SetTestDataFunctor(int InA, float InB) : a(InA), b(InB) {};
};

struct CompareTest
{
    bool operator()(const SetTestDataFunctor& InLeft, const SetTestDataFunctor& InRight) const
    {
        return InLeft.a < InRight.a;
    }
};

enum class CharacterType
{
    Warrior,
    Mage,
    Thief
};

struct CharacterData
{
    int Level;
    int HP;
    int Exp;
};
