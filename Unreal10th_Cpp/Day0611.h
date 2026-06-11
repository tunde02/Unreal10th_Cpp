#pragma once
#include <vector>
#include <string>

class Day0611
{
public:
    void Day0611_Main();

    void TestSTL_Algorithm();
    void PrintVector(const std::vector<int>& InData);
    void TestSTL_Lambda();
    bool Desc(int left, int right);

    /*
        STL을 활용하여 다음과 같은 작업 진행하기
        - 정수를 여러개 입력받고 최대, 최소 구하기
        - 정수를 여러개 입력받고 중복없는 결과를 출력하기
        - 문자열에서 중복되는 글자 제거하기
        - 문장을 입력 받아 각 단어가 등장하는 회수 측정하기
    */
    void Day0611_Practice();
    bool IsNumber(const std::string& InString);
};
