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

/**************************************************

// 비교 연산자
bool bTest = false;
bTest = 10 > 5;   // true
bTest = 10 < 5;   // false
bTest = 10 <= 5;  // false
bTest = 10 >= 5;  // true
bTest = 10 >= 10; // true
bTest = 10 > 10;  // false
bTest = 10 == 10; // true
bTest = 0.1f + 0.2f == 0.3f; // 이런식의 비교는 절대로 하면 안된다

// if, else if, else
int a = 10;
int b = 20;

if (a > b)
{
	printf("a(%d)가 b(%d)보다 큽니다.\n", a, b);
}
else if (a == b)
{
	printf("a(%d)와 b(%d)가 같습니다.\n", a, b);
}
else
{
	printf("a(%d)가 b(%d)보다 작습니다.\n", a, b);
}

// switch
a = 13;
switch (a)
{
case 1:
	printf("a는 1입니다.\n");
	break;
case 10:
	printf("a는 1입니다.\n");
	break;
default:
	printf("a는 %d입니다.\n", a);
	break;
}

//삼항 연산자
int x = (a > 10) ? 1 : 0;

// 논리 연산자
int Score = 78;
if (80 <= Score && Score < 90)
{
	printf("B학점입니다.");
}

**************************************************/

/**************************************************

// 조건문 간단 실습 (입력은 정수만)
	// 1. 숫자를 입력받아 양수인지 음수인지 0인지 판단하는 코드
printf("1. 숫자를 입력받아 양수인지 음수인지 0인지 판단하는 코드\n");

int Number = 0;
printf("숫자를 입력하세요 : ");
cin >> Number;

if (Number == 0)
{
	printf("[%d]는 [0]입니다.\n\n", Number);
}
else if (Number > 0)
{
	printf("[%d]는 [양수]입니다.\n\n", Number);
}
else
{
	printf("[%d]는 [음수]입니다.\n\n", Number);
}

// 2. 숫자를 입력받아 홀수인지 짝수인지 판단하는 코드
printf("2. 숫자를 입력받아 홀수인지 짝수인지 판단하는 코드\n");

int OddOrEvenNumber = 0;
printf("숫자를 입력하세요 : ");
cin >> OddOrEvenNumber;

if (OddOrEvenNumber % 2 == 0)
{
	printf("[%d]은(는) [짝수]입니다.\n\n", OddOrEvenNumber);
}
else
{
	printf("[%d]은(는) [홀수]입니다.\n\n", OddOrEvenNumber);
}

// 3. 두 수를 입력 받아 더 큰 수를 출력하는 코드. 같을 경우 같다고 출력
printf("3. 두 수를 입력 받아 더 큰 수를 출력하는 코드. 같을 경우 같다고 출력\n");

int Number1 = 0, Number2 = 0;
printf("두 수를 입력하세요 : ");
cin >> Number1 >> Number2;

if (Number1 == Number2)
{
	printf("두 수 [%d], [%d]은(는) 서로 같습니다.\n\n", Number1, Number2);
}
else if (Number1 > Number2)
{
	printf("두 수 [%d], [%d]중 더 큰 수는 [%d]입니다.\n\n", Number1, Number2, Number1);
}
else
{
	printf("두 수 [%d], [%d]중 더 큰 수는 [%d]입니다.\n\n", Number1, Number2, Number2);
}

// 논리 연산자 간단 실습
// 1. 나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력하기
printf("1. 나이와 키를 입력 받아, 6세 이상, 120cm 이상일 때 롤러코스터 탑승 가능, 그 외에는 불가능으로 출력하기\n");

int Age = 0, Height = 0;
printf("나이를 입력하세요 : ");
cin >> Age;
printf("키를 입력하세요 : ");
cin >> Height;

if (Age >= 6 && Height >= 120)
{
	printf("롤러코스터 탑승 [가능]\n\n");
}
else
{
	printf("롤러코스터 탑승 [불가능]\n\n");
}

// 2. 점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기
printf("2. 점수를 입력 받아 90점 이상은 A, 80점 이상은 B, 70점 이상은 C, 60점 이상은 D, 그 이하는 F라고 출력하기\n");

int Score = 0;
printf("점수를 입력하세요 : ");
cin >> Score;

if (Score >= 90)
{
	printf("[A]\n\n");
}
else if (Score >= 80)
{
	printf("[B]\n\n");
}
else if (Score >= 70)
{
	printf("[C]\n\n");
}
else if (Score >= 60)
{
	printf("[D]\n\n");
}
else
{
	printf("[F]\n\n");
}

// 3. 세 과목의 점수를 입력받아, 세 과목 평균 60점 이상이면 "합격", 아니면 "불합격"을 출력 (한 과목이라도 40점 미만이면 불합격)
printf("3. 세 과목의 점수를 입력받아, 세 과목 평균 60점 이상이면 \"합격\", 아니면 \"불합격\"을 출력 (단, 한 과목이라도 40점 미만이면 불합격)\n");

int Score1 = 0, Score2 = 0, Score3 = 0;
int Average = 0;
printf("세 과목의 점수를 입력하세요 : ");
cin >> Score1 >> Score2 >> Score3;

Average = (Score1 + Score2 + Score3) / 3;

if (Average < 60 || (Score1 < 40 || Score2 < 40 || Score3 < 40))
{
	printf("[불합격]\n\n");
}
else
{
	printf("[합격]\n\n");
}

**************************************************/
