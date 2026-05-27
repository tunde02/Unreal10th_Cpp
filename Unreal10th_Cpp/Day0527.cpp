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

    /*

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

    */

    // 문자열 복사 테스트
    const char* TestName = "문자열 복사";
    const char* StrCpyTestCasePass[] = { "Hello World!", "Jin Seong Ho", "안녕하세요.", "ㅇㅂㅈ우ㅛㅕ2474wenhf283gb1" };
    const char* StrCpyTestCaseResult[] = { "Hello World!", "Jin Seong Ho", "안녕하세요.", "ㅇㅂㅈ우ㅛㅕ2474wenhf283gb1" };
    int StrCpyPassCount = 0;
    int StrCpyFailCount = 0;
    int StrCpyTestCount = sizeof(StrCpyTestCasePass) / sizeof(StrCpyTestCasePass[0]);
    printf("[%s 테스트]\n", TestName);
    for (int i = 0; i < StrCpyTestCount; i++)
    {
        char Buffer[128] = { 0 };
        const char* Case = StrCpyTestCasePass[i];
        bool IsPass = strcmp(MyStrCpy(Buffer, Case), StrCpyTestCaseResult[i]) == 0;
        if (IsPass)
        {
            StrCpyPassCount++;
        }
        else
        {
            StrCpyFailCount++;
        }
        printf("%s : [%s] == [%s]\n", IsPass ? "Pass" : "Fail", StrCpyTestCasePass[i], StrCpyTestCaseResult[i]);
    }
    printf("[%s 테스트] PassCount : %d, FailCount : %d\n\n", TestName, StrCpyPassCount, StrCpyFailCount);
    if (StrCpyFailCount > 0)
    {
        printf("[ERROR] %s 통과 못한 테스트 %d개\n\n", TestName, StrCpyFailCount);
    }

    // 문자열 연결 테스트
    TestName = "문자열 연결";
    const char* StrCatTestCasePass1[] = { "Hello World!", "Jin Seong Ho", "안녕하세요.", "ㅇㅂㅈ우ㅛㅕ2474wenhf283gb1" };
    const char* StrCatTestCasePass2[] = { "~!!!!", " (진성호)", "반갑습니다.", " 2348237428934" };
    const char* StrCatTestCaseResult[] = { "Hello World!~!!!!", "Jin Seong Ho (진성호)", "안녕하세요.반갑습니다.", "ㅇㅂㅈ우ㅛㅕ2474wenhf283gb1 2348237428934" };
    int StrCatPassCount = 0;
    int StrCatFailCount = 0;
    int StrCatTestCount = sizeof(StrCatTestCasePass1) / sizeof(StrCatTestCasePass1[0]);
    printf("[%s 테스트]\n", TestName);
    for (int i = 0; i < StrCatTestCount; i++)
    {
        char Case1[128] = { 0 };
        strcpy(Case1, StrCatTestCasePass1[i]);
        const char* Case2 = StrCatTestCasePass2[i];
        const char* Result = StrCatTestCaseResult[i];
        bool IsPass = strcmp(MyStrCat(Case1, Case2), Result) == 0;
        if (IsPass)
        {
            StrCatPassCount++;
        }
        else
        {
            StrCatFailCount++;
        }
        printf("%s : [%s] + [%s] == [%s]\n", IsPass ? "Pass" : "Fail", StrCatTestCasePass1[i], StrCatTestCasePass2[i], Result);
    }
    printf("[%s 테스트] PassCount : %d, FailCount : %d\n\n", TestName, StrCatPassCount, StrCatFailCount);
    if (StrCatFailCount > 0)
    {
        printf("[ERROR] %s 통과 못한 테스트 %d개\n\n", TestName, StrCatFailCount);
    }

    // 문자열 비교 테스트
    TestName = "문자열 비교";
    const char* StrCmpTestCasePass1[] = { "abc", "ab", "abb", "abc", "abc" };
    const char* StrCmpTestCasePass2[] = { "abc", "abc", "abc", "abb", "ab" };
    int StrCmpTestCaseResult[] = { 0, -1, -1, 1, 1 };
    int StrCmpPassCount = 0;
    int StrCmpFailCount = 0;
    int StrCmpTestCount = sizeof(StrCmpTestCasePass1) / sizeof(StrCmpTestCasePass1[0]);
    printf("[%s 테스트]\n", TestName);
    for (int i = 0; i < StrCmpTestCount; i++)
    {
        const char* Case1 = StrCmpTestCasePass1[i];
        const char* Case2 = StrCmpTestCasePass2[i];
        int Result = StrCmpTestCaseResult[i];
        bool IsPass = MyStrCmp(Case1, Case2) == Result;
        if (IsPass)
        {
            StrCmpPassCount++;
        }
        else
        {
            StrCmpFailCount++;
        }
        printf("%s : [%s] vs [%s] : [%d]\n", IsPass ? "Pass" : "Fail", StrCmpTestCasePass1[i], StrCmpTestCasePass2[i], Result);
    }
    printf("[%s 테스트] PassCount : %d, FailCount : %d\n\n", TestName, StrCmpPassCount, StrCmpFailCount);
    if (StrCmpFailCount > 0)
    {
        printf("[ERROR] %s 통과 못한 테스트 %d개\n\n", TestName, StrCmpFailCount);
    }

    // 문자열 AtoI 테스트
    TestName = "문자열 AtoI";
    const char* AtoITestCasePass[] = { "123", "-342", "0", " 33", "+92", "  -11", "45ds", "as54", " +-233", "12 35", "" };
    int AtoITestCaseResult[] = { 123, -342, 0, 33, 92, -11, 0, 0, 0, 0, 0 };
    int AtoIPassCount = 0;
    int AtoIFailCount = 0;
    int AtoITestCount = sizeof(AtoITestCasePass) / sizeof(AtoITestCasePass[0]);
    printf("[%s 테스트]\n", TestName);
    for (int i = 0; i < AtoITestCount; i++)
    {
        const char* Case = AtoITestCasePass[i];
        int Result = AtoITestCaseResult[i];
        bool IsPass = MyAtoI(Case) == Result;
        if (IsPass)
        {
            AtoIPassCount++;
        }
        else
        {
            AtoIFailCount++;
        }
        printf("%s : [%s] -> [%d]\n", IsPass ? "Pass" : "Fail", AtoITestCasePass[i], Result);
    }
    printf("[%s 테스트] PassCount : %d, FailCount : %d\n\n", TestName, AtoIPassCount, AtoIFailCount);
    if (AtoIFailCount > 0)
    {
        printf("[ERROR] %s 통과 못한 테스트 %d개\n\n", TestName, AtoIFailCount);
    }

    // 문자열 AtoF 테스트
    TestName = "문자열 AtoF";
    const char* AtoFTestCasePass[] = { "123.45", "-38.556", "0.0", "  3.14", "+0.5", ".7", "12.", "-.54", "12.05.78", "45.dd", "aqw45.8", "12. 35", "" };
    float AtoFTestCaseResult[] = { 123.45f, -38.556f, 0.0f, 3.14f, 0.5f, 0.7f, 12.0f, -0.54f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
    int AtoFPassCount = 0;
    int AtoFFailCount = 0;
    int AtoFTestCount = sizeof(AtoFTestCasePass) / sizeof(AtoFTestCasePass[0]);
    printf("[%s 테스트]\n", TestName);
    for (int i = 0; i < AtoFTestCount; i++)
    {
        const char* Case = AtoFTestCasePass[i];
        float Result = AtoFTestCaseResult[i];
        bool IsPass = IsEqualFloat(MyAtoF(Case), Result);
        if (IsPass)
        {
            AtoFPassCount++;
        }
        else
        {
            AtoFFailCount++;
        }
        printf("%s : [%s] -> [%f]\n", IsPass ? "Pass" : "Fail", AtoFTestCasePass[i], Result);
    }
    printf("[%s 테스트] PassCount : %d, FailCount : %d\n\n", TestName, AtoFPassCount, AtoFFailCount);
    if (AtoFFailCount > 0)
    {
        printf("[ERROR] %s 통과 못한 테스트 %d개\n\n", TestName, AtoFFailCount);
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

    /*
    char* Result = Destination;
    while ((*Destination++ = *Source++) != '\0') {}
    return Result;
    */
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

    /*
    char* Result = Destination;
    while (*Destination)
    {
        Destination++;
    }

    while ((*Destination++ = *Source++) != '\0') {}

    return Result;
    */
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

    /*
    while (*String1 && (*String1 == *String2))
    {
        String1++;
        String2++;
    }
    return *(const unsigned char*)String1 - *(const unsigned char*)String2;
    */
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

    /*
    // 공백 제거
    while (*String == ' ' || *String == '\t' || *String == '\n' || *String == '\r')
    {
        String++;
    }

    // 부호 처리
    int Sign = 1;
    if (*String == '-')
    {
        Sign = -1;
        String++;
    }
    else if (*String == '+')
    {
        String++;
    }

    // 문자를 숫자로 바꾸기
    int Result = 0;
    while ('0' <= *String && *String <= '9')
    { 
        Result = Result * 10 + (*String - '0');
        String++;
    }
    
    // 숫자가 아닌 것이 나왔을 때 처리
    if (*String != '\0')
    {
        Result = 0;
    }

    return Result * Sign;
    */
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

    /*
    
    // 공백 제거
    while (*String == ' ' || *String == '\t' || *String == '\n' || *String == '\r')
    {
        String++;
    }

    // 부호 처리
    int Sign = 1;
    if (*String == '-')
    {
        Sign = -1;
        String++;
    }
    else if (*String == '+')
    {
        String++;
    }
    
    // 문자를 숫자로 바꾸기
    float Result = 0.0f;
    while ('0' <= *String && *String <= '9')
    {
        Result = Result * 10.0f + (*String - '0');
        String++;
    }

    // 소수점 처리
    if (*String == '.')
    {
        String++;

        // 문자를 숫자로 바꾸기
        float Fraction = 1.0f; // 소수점 아래로 얼마나 내려갈지 누적
        while ('0' <= *String && *String <= '9')
        {
            Result = Result * 10.0f + (*String - '0');
            String++;
            Fraction *= 0.1f;
        }
        Result *= Fraction;
    }

    // 숫자가 아닌 것이 나왔을 때 처리
    if (*String != '\0')
    {
        Result = 0;
    }

    return Result * Sign;
    
    */
}

bool IsEqualFloat(float Float1, float Float2)
{
    const float Threshold = 0.0001f;
    float Diff = Float1 - Float2;

    return (0 < Diff && Diff <= Threshold)
        || (-Threshold <= Diff && Diff <= 0);
}
