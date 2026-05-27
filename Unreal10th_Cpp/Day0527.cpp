#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Day0527.h"

void Day0527()
{
    /*

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

    */

    // 실습 (파라미터, 리턴 똑같은 형태)
    // 1. MyStrCpy()
    // 2. MyStrCat()
    // 3. MyStrCmp()
    // 4. MyAtoI()
    //   - 성공 : "123", "-342", "0", " 33", "+92", "  -11"
    //   - 실패 : 무조건 0 반환 - "45ds", "as54", " +-233", "", "12 35"
    // 5. MyAtoF()
    //   - 성공 : "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54"
    //   - 실패 : 무조건 0 반환 - "12.05.78", "45.ㅇㅇ", "aqw45.8", "12. 35"

    char Buffer[32] = { 0 };
    MyStrCpy(Buffer, "Hello World!");
    printf("문자열 복사 - Buffer의 내용 : [%s]\n", Buffer);


    MyStrCat(Buffer, "qwerasdf");
    printf("문자열 연결 - Buffer의 내용 : [%s]\n", Buffer);

    printf("문자열 비교 - [%s]와 [%s] : %d\n", "abc", "abc", MyStrCmp("abc", "abc"));
    printf("문자열 비교 - [%s]와 [%s] : %d\n", "ab", "abc", MyStrCmp("ab", "abc"));
    printf("문자열 비교 - [%s]와 [%s] : %d\n", "abb", "abc", MyStrCmp("abb", "abc"));
    printf("문자열 비교 - [%s]와 [%s] : %d\n", "abc", "abb", MyStrCmp("abc", "abb"));
    printf("문자열 비교 - [%s]와 [%s] : %d\n", "abc", "ab", MyStrCmp("abc", "ab"));

    const char* AtoITestCases[6] = { "12345", "-342", "0", " 33", "+92", "  -11" };
    const char* AtoIFailCases[5] = { "45ds", "as54", " +-233", "", "12 35" };
    for (int i = 0; i < 6; i++)
    {
        int IntegerNumber = MyAtoI(AtoITestCases[i]);
        printf("문자열 [%s] -> 인티저 [%d]\n", AtoITestCases[i], IntegerNumber);
    }
    for (int i = 0; i < 5; i++)
    {
        int IntegerNumber = MyAtoI(AtoIFailCases[i]);
        printf("문자열 [%s] -> 인티저 [%d]\n", AtoIFailCases[i], IntegerNumber);
    }

    const char* AtoFTestCases[] = { "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54" };
    const char* AtoFFailCases[] = { "12.05.78", "45.ㅇㅇ", "aqw45.8", "12. 35" };
    for (const char * Case : AtoFTestCases)
    {
        float FloatNumber = MyAtoF(Case);
        printf("문자열 [%s] -> 실수 [%f]\n", Case, FloatNumber);
    }
    for (const char* Case : AtoFFailCases)
    {
        float FloatNumber = MyAtoF(Case);
        printf("문자열 [%s] -> 실수 [%f]\n", Case, FloatNumber);
    }
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

char* MyStrCpy(char* Destination, const char* Source)
{
    int i = 0;
    while (Source[i] != '\0')
    {
        Destination[i] = Source[i];
        i++;
    }

    Destination[i] = '\0';

    return Destination;
}

char* MyStrCat(char* Destination, const char* Source)
{
    int DestinationLength = MyStrLen(Destination);
    int i = 0;

    while (Source[i] != '\0')
    {
        Destination[DestinationLength + i] = Source[i];
        i++;
    }

    return Destination;
}

int MyStrCmp(const char* String1, const char* String2)
{
    int Result = 0;
    int i = 0;
    while (String1[i] != '\0' || String2[i] != '\0')
    {
        if (String1[i] > String2[i])
        {
            Result =  1;
            break;
        }
        else if (String1[i] < String2[i])
        {
            Result =  -1;
            break;
        }

        i++;
    }

    if (String1[i] == '\0' && String2[i] != '\0')
    {
        Result = -1;
    }
    else if (String1[i] != '\0' && String2[i] == '\0')
    {
        Result = 1;
    }

    return Result;
}

int MyAtoI(const char* String)
{
    int Number = 0;
    int Sign = 1;
    bool IsSigned = false;
    bool IsNumber = false;
    int i = 0;
    
    while (String[i] != '\0')
    {
        if ('0' <= String[i] && String[i] <= '9')
        {
            int Digit = (int)(String[i] - '0');
            Number = (Number * 10) + Digit;
            IsNumber = true;
        }
        else if (String[i] == '+' && !IsSigned)
        {
            Sign = 1;
            IsSigned = true;
        }
        else if (String[i] == '-' && !IsSigned)
        {
            Sign = -1;
            IsSigned = true;
        }
        else if (String[i] == ' ' && !IsNumber)
        {
            
        }
        else
        {
            return 0;
        }

        i++;
    }

    Number *= Sign;

    return Number;
}

float MyAtoF(const char* String)
{
    float Number = 0.0f;
    int Sign = 1;
    bool IsSigned = false;
    bool IsNumber = false;
    bool IsDotted = false;
    int NegativeExponent = 0;
    int i = 0;

    while (String[i] != '\0')
    {
        if ('0' <= String[i] && String[i] <= '9')
        {
            float Digit = (float)(String[i] - '0');
            Number = (Number * 10.0f) + Digit;
            IsNumber = true;

            if (IsDotted)
            {
                NegativeExponent++;
            }
        }
        else if (String[i] == '+' && !IsSigned)
        {
            Sign = 1;
            IsSigned = true;
        }
        else if (String[i] == '-' && !IsSigned)
        {
            Sign = -1;
            IsSigned = true;
        }
        else if (String[i] == ' ' && !IsNumber)
        {

        }
        else if (String[i] == '.' && !IsDotted)
        {
            IsDotted = true;
        }
        else
        {
            return 0;
        }

        i++;
    }

    while (NegativeExponent > 0)
    {
        Number *= 0.1f;
        NegativeExponent--;
    }

    Number *= Sign;

    return Number;
}