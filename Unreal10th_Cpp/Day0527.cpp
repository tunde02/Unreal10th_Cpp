#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Day0527.h"

void Day0527()
{
    // 문자열
    const char* TestString = "Hello String!"; // const char[14]
    const char* TestKorean = "안녕 문자열!"; // 인코딩이 자동으로 처리되는 덕에 한글도 보임

    // 문자열 - 길이
    const char* TestLengthString = "Hello";
    int Size = MyStrLen(TestLengthString);
    printf("[%s]의 길이 : [%d]\n", TestLengthString, Size);

    // 문자열 - 복사
    char Buffer[32] = { 0 };
    strcpy(Buffer, TestString);
    printf("Buffer의 내용 : [%s]\n", Buffer); // Hello String!

    // 문자열 - 연결
    strcat(Buffer, TestLengthString);
    printf("Buffer의 내용 : [%s]\n", Buffer); // Hello String!Hello

    // 문자열 - 비교
    int Result = strcmp("abc", "abc");  // 0
    Result = strcmp("ab", "abc");       // -1
    Result = strcmp("abb", "abc");      // -1
    Result = strcmp("abc", "abb");      // 1
    Result = strcmp("abc", "ab");       // 1

    // 문자열 - 숫자 변환
    const char* IntegerString = "123";
    int IntegerNumber = atoi(IntegerString);
    const char* FloatString = "12.3";
    float FloatNumber = atof(FloatString);
    printf("문자열 [%s] -> 인티저 [%d]\n", IntegerString, IntegerNumber);
    printf("문자열 [%s] -> 실수 [%f]\n", FloatString, FloatNumber);
}

int MyStrLen(const char* String)
{
    int Length = 0;
    while (String[Length] != '\0')
    {
        Length++;
    }

    return Length;
}
