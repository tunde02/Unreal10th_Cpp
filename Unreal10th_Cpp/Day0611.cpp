#include "Day0611.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <sstream>

void Day0611::Day0611_Main()
{
    //TestSTL_Algorithm();
    //TestSTL_Lambda();
    Day0611_Practice();
}

void Day0611::TestSTL_Algorithm()
{
    std::vector<int> Datas = { 10, 35, 55, 22, 47 };
    PrintVector(Datas);

    // 데이터 찾기
    std::vector<int>::iterator findIter = std::find(Datas.begin(), Datas.end(), 55);
    if (findIter != Datas.end())
    {
        printf("%d를 찾았다.\n", *findIter);
    }
    else
    {
        printf("찾는 수가 없다.\n");
    }

    findIter = std::find(Datas.begin(), Datas.end(), 100);
    if (findIter != Datas.end())
    {
        printf("%d를 찾았다.\n", *findIter);
    }
    else
    {
        printf("찾는 수가 없다.\n");
    }

    std::sort(Datas.begin(), Datas.end());

    // std::binary_search() : 정렬된 상태에서만 사용 가능. bool로 있다 없다만 반환
    if (std::binary_search(Datas.begin(), Datas.end(), 55))
    {
        printf("%d를 찾았다.\n", 55);
    }
    else
    {
        printf("찾는 수가 없다.\n");
    }
}

void Day0611::PrintVector(const std::vector<int>& InData)
{
    printf("Data : ");
    for (int e : InData)
    {
        printf("%d ", e);
    }
    printf("\n");
}

void Day0611::TestSTL_Lambda()
{
    std::vector<int> Datas = { 10, 35, 55, 22, 47 };
    PrintVector(Datas);

    // 람다 사용
    std::sort(Datas.begin(), Datas.end(), [](int left, int right) { return left > right; });
    PrintVector(Datas);

    // 멤버 함수 사용
    //std::sort(Datas.begin(), Datas.end(), &Day0611::Desc); // 단순히 멤버 함수의 포인터만 전달하면 무슨 객체의 함수의 포인터인지 몰라서 에러가 뜸

    // 바인더로 묶기
    std::sort(Datas.begin(), Datas.end(),
              std::bind(&Day0611::Desc, this, std::placeholders::_1, std::placeholders::_2));

    // this를 캡처해서 람다에서 멤버 함수 실행하기
    std::sort(Datas.begin(), Datas.end(),
              [this](int a, int b) { return this->Desc(a, b); });
    PrintVector(Datas);

    int Line = 50;
    auto iter = std::find_if(Datas.begin(), Datas.end(),
                             [Line](int n) {
                                 return n > Line;
                             });
    printf("%d보다 큰 첫 번째 숫자는 %d입니다.\n", Line, *iter);
}

bool Day0611::Desc(int left, int right)
{
    return left > right;
}

void Day0611::Day0611_Practice()
{
    // - 정수를 여러개 입력받고 최대, 최소 구하기
    //   vector, sort하고 맨압 맨뒤 반환
    // - 정수를 여러개 입력받고 중복없는 결과를 출력하기
    //   입력받은거 set에 넣고 set 출력하기?
    // - 문자열에서 중복되는 글자 제거하기
    //   입력받은거 set에 넣고 set 출력하기?
    // - 문장을 입력 받아 각 단어가 등장하는 회수 측정하기
    //   unordered_map Key: 단어, Value: 횟수

    printf("========== 정수를 여러 개 입력받고 최대, 최소 구하기 ==========\n");
    printf("정수를 입력하세요 (글자 입력 시 종료)");
    //std::vector<int> IntVector = { 10, -5, 333, 1314, -21387, 20, 30 };
    std::vector<int> IntVector;
    while (true)
    {
        printf(" : ");
        std::string Input{};
        std::getline(std::cin, Input);

        int Number = 0;
        try
        {
            Number = std::stoi(Input);
        }
        catch (const std::invalid_argument&)
        {
            break;
        }

        IntVector.push_back(Number);
    }
    std::sort(IntVector.begin(), IntVector.end());
    printf("IntVector의 최소값 : %d\n", IntVector[0]);
    printf("IntVector의 최대값 : %d\n", IntVector[IntVector.size() - 1]);


    printf("\n========== 정수를 여러 개 입력받고 중복없는 결과를 출력하기 ==========\n");
    printf("정수를 입력하세요 (글자 입력 시 종료)");
    std::set<int> IntVector2;
    while (true)
    {
        printf(" : ");
        std::string Input{};
        std::getline(std::cin, Input);

        int Number = 0;
        try
        {
            Number = std::stoi(Input);
        }
        catch (const std::invalid_argument&)
        {
            break;
        }

        IntVector2.insert(Number);
    }
    printf("중복 없는 결과 : ");
    for (auto& e : IntVector2)
    {
        printf("%d ", e);
    }
    printf("\n");


    printf("\n========== 문자열에서 중복되는 글자 제거하기 ==========\n");
    std::map<char, int> StringMap;
    printf("문자열을 입력하세요 : ");
    std::string Input3;
    std::getline(std::cin, Input3);
    int i = 0;
    while (Input3[i] != '\0')
    {
        if (StringMap.find(Input3[i]) == StringMap.end())
        {
            StringMap[Input3[i]] = i;
        }
        i++;
    }

    std::vector<std::pair<char, int>> TempVector(StringMap.begin(), StringMap.end());
    std::sort(TempVector.begin(), TempVector.end(),
              [](std::pair<char, int> a, std::pair<char, int> b) {
                  return a.second < b.second;
              });
    printf("중복되는 글자가 제거된 문자열 : ");
    for (auto& e : TempVector)
    {
        printf("%c", e.first);
    }
    printf("\n");

    printf("\n========== 문장을 입력 받아 각 단어가 등장하는 회수 측정하기 ==========\n");
    std::map<std::string, int> WordCounts;
    printf("문장을 입력하세요 : ");
    std::string Input4;
    std::getline(std::cin, Input4);

    std::stringstream stream(Input4);
    std::string TempString;
    while (stream >> TempString)
    {
        if (WordCounts.find(TempString) != WordCounts.end())
        {
            WordCounts[TempString]++;
        }
        else
        {
            WordCounts[TempString] = 1;
        }
    }

    printf("각 단어가 등장한 횟수 : \n");
    for (auto& e : WordCounts)
    {
        printf("%s : %d회\n", e.first.c_str(), e.second);
    }
}

bool Day0611::IsNumber(const std::string& InString)
{
    int i = 0;
    while (InString[i] != '\0')
    {
        if (!('0' <= InString[i] && InString[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}
