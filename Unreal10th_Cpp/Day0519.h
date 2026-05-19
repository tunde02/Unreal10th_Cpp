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

/**************************************************

// 부동소수점 간단 실습
// 1. 원의 반지름 입력 받고 넓이 구하기
printf("1. 원의 반지름 입력 받고 넓이 구하기\n");

float Radius = 0.0f;
const float PI = 3.141592f;

printf("원의 반지름을 입력하세요 : ");
cin >> Radius;

float CircleSize = Radius * Radius * PI;
printf("원의 넓이 : %.2f\n\n", CircleSize);

// 2. 3개의 값을 입력 받고 평균값 구하기
printf("2. 3개의 값을 입력 받고 평균값 구하기\n");

float A = 0.0f, B = 0.0f, C = 0.0f;
float Average = 0.0f;
printf("값을 3개 입력하세요 : ");
cin >> A >> B >> C;

Average = (A + B + C) / 3;

printf("세 값의 평균 : %.1f\n\n", Average);

// 3. 정가와 할인율을 입력받고 할인된 가격 구하기
printf("3. 정가와 할인율을 입력받고 할인된 가격 구하기\n");

int OriginalPrice;
float DiscountPercentage, DiscountedPrice;

printf("정가를 입력하세요 : ");
cin >> OriginalPrice;
printf("할인율을 입력하세요 : ");
cin >> DiscountPercentage;

DiscountedPrice = OriginalPrice * (1.0f - (DiscountPercentage * 0.01f));

printf("할인된 가격 : %d\n\n", (int)DiscountedPrice);

**************************************************/
