#pragma once

/**************************************************

// float
float RealNumber = 0.0f; // 0.0f는 float
//RealNumber = 0.1;        // 0.1은 double인데, 암시적 변환이 일어나 float으로 저장됨
RealNumber = (float)0.1; // 명시적 변환

printf("이것은 실수입니다 : %f\n", RealNumber);

RealNumber = 0.1f + 0.5f;
printf("이것은 실수입니다 : %.2f\n", RealNumber); // 소수점 아래 둘째자리까지 출력
RealNumber -= 0.2f;
printf("이것은 실수입니다 : %8.2f\n", RealNumber); // 소수점 포함 전체 여덟자리, 소수점 아래 둘째자리까지 출력
printf("float 타입의 사이즈 : [%d] byte\n\n", (int)sizeof(float));

// bool
bool bTest = false;
bTest = true;

printf("bool 타입의 사이즈 : [%d] byte\n\n", (int)sizeof(bool));


// char
char TestCharacter = 'a';
TestCharacter = 'b';

printf("char TestCharacter = %c\n", TestCharacter);
printf("char 타입의 사이즈 : [%d] byte\n\n", (int)sizeof(char));

// string
std::string TestString = "Hello World!\n";

// 부호 없는 int (32bit, 0 ~ 42억)
unsigned int TestUnsingedInt = 0;

// 64bit int
long long TestInt64 = 0;
unsigned long long TestUnsignedInt64 = 0;

// 유니코드 char. 신경 안써도 됨
wchar_t UnicodeChar = L'가';

int Size = 500;
printf("한 변이 %d인 정사각형의 넓이는 %d입니다.\n", Size, Size * Size);
Size = 50000;
printf("한 변이 %d인 정사각형의 넓이는 %d입니다.\n", Size, Size * Size); // 오버플로우 발생

**************************************************/

