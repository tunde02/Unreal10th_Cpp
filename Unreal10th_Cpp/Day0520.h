#pragma once

/**************************************************

// 비트 연산자
int DataA = 6;
int DataB = 7;

printf("DataA & DataB = %d\n", DataA & DataB);
printf("DataA | DataB = %d\n", DataA | DataB);

unsigned int DataC = 6;
printf("~DataC = %u\n", ~DataC);

printf("DataA bit toggle : %d\n", DataA ^ 1);
printf("DataA bit toggle : %d\n", (DataA ^ 1) ^ 1);

// enum
enum WeekDays
{
	Mon,
	Tue,
	Wed,
	Thu,
	Fri,
	Sat,
	Sun
};

int EnumTest1 = Mon;

enum BitFlagTest
{
	Up = 1 << 0,
	Down = 1 << 1,
	Left = 1 << 2,
	Right = 1 << 3
};

int Direction = Up | Right; // 오른쪽 위
Direction = Up | Down | Left | Right; // 모든 방향

switch (Direction)
{
case Up:
	break;
case Down:
	break;
case Left:
	break;
case Right:
	break;
default:
	break;
}

**************************************************/

/**************************************************

// 비트 연산자, enum 간단 실습
// 1. 비트 연산을 활용해서 홀짝을 판별하기. (입력 데이터는 무조건 양수)
printf("1. 비트 연산을 활용해서 홀짝을 판별하기. (입력 데이터는 무조건 양수)\n");

int Number = 0;
const int CHECK = 1;
printf("양수를 입력하세요 : ");
cin >> Number;

if ((Number & CHECK) == 0)
{
	printf("[%d]은(는) [짝수]입니다.\n\n", Number);
}
else
{
	printf("[%d]은(는) [홀수]입니다.\n\n", Number);
}

// 2. 캐릭터가 사용 가능한 무기 enum 만들기. 데이터 설정해서 특정 무기를 사용할 수 있는지 없는지 확인하는 코드 만들기
printf("2. 캐릭터가 사용 가능한 무기 enum 만들기. 데이터 설정해서 특정 무기를 사용할 수 있는지 없는지 확인하는 코드 만들기\n\n");

enum Weapon
{
	Sword	= 1 << 0,
	Gun		= 1 << 1,
	Axe		= 1 << 2,
	Bow		= 1 << 3,
	Staff	= 1 << 4
};

int UsableWeapons = Sword | Bow | Staff;
int UserInput = 0;
printf("[ 현재 사용 가능한 무기 목록 ]\n");
if ((UsableWeapons & Sword) != 0)
{
	printf("검 ");
}
if ((UsableWeapons & Gun) != 0)
{
	printf("총 ");
}
if ((UsableWeapons & Axe) != 0)
{
	printf("도끼 ");
}
if ((UsableWeapons & Bow) != 0)
{
	printf("활 ");
}
if ((UsableWeapons & Staff) != 0)
{
	printf("스태프 ");
}
printf("\n\n");


printf("확인할 무기 번호를 입력하세요\n");
printf("1. 칼\n");
printf("2. 총\n");
printf("3. 도끼\n");
printf("4. 활\n");
printf("5. 스태프\n");
printf(": ");
cin >> UserInput;

int WeaponCheck = 1 << (UserInput - 1);

if ((UsableWeapons & WeaponCheck) == 0)
{
	printf("해당 무기는 사용할 수 없습니다.\n\n");
}
else
{
	printf("해당 무기는 사용할 수 있습니다!\n\n");
}

// 3. 캐릭터가 사용 가능한 무기를 추가 삭제하기
printf("3. 캐릭터가 사용 가능한 무기를 추가 삭제하기\n");
printf("추가할 무기를 입력하세요\n");
printf("1. 칼\n");
printf("2. 총\n");
printf("3. 도끼\n");
printf("4. 활\n");
printf("5. 스태프\n");
printf(": ");
cin >> UserInput;

UsableWeapons |= 1 << (UserInput - 1);
printf("[ 현재 사용 가능한 무기 목록 ]\n");
if ((UsableWeapons & Sword) != 0)
{
	printf("검 ");
}
if ((UsableWeapons & Gun) != 0)
{
	printf("총 ");
}
if ((UsableWeapons & Axe) != 0)
{
	printf("도끼 ");
}
if ((UsableWeapons & Bow) != 0)
{
	printf("활 ");
}
if ((UsableWeapons & Staff) != 0)
{
	printf("스태프 ");
}
printf("\n\n");

printf("삭제할 무기를 입력하세요\n");
printf("1. 칼\n");
printf("2. 총\n");
printf("3. 도끼\n");
printf("4. 활\n");
printf("5. 스태프\n");
printf(": ");
cin >> UserInput;

UsableWeapons &= ~(1 << (UserInput - 1));
printf("[ 현재 사용 가능한 무기 목록 ]\n");
if ((UsableWeapons & Sword) != 0)
{
	printf("검 ");
}
if ((UsableWeapons & Gun) != 0)
{
	printf("총 ");
}
if ((UsableWeapons & Axe) != 0)
{
	printf("도끼 ");
}
if ((UsableWeapons & Bow) != 0)
{
	printf("활 ");
}
if ((UsableWeapons & Staff) != 0)
{
	printf("스태프 ");
}
printf("\n\n");

**************************************************/

/**************************************************

// 반복문
for (int i = 0; i < 5; i++)
{
	printf("Hello World! - %d\n", i);
}

int i = 0;
while (i < 5)
{
	printf("Hello World! - %d\n", i);
	i++;
}

int j = 0;
do
{
	printf("Hello World - %d\n", j);
} while (j < 5);

**************************************************/

/**************************************************

// 반복문 간단 실습
// 1. 0을 입력 받을 때까지 입력 받은 숫자의 합을 출력
//	 - while, do-while 둘 다 해보기
printf("1. 0을 입력 받을 때까지 입력 받은 숫자의 합을 출력\n");

int UserInput = -1;
int Sum = 0;
while (UserInput != 0)
{
	printf("숫자를 입력하세요 : ");
	cin >> UserInput;

	Sum += UserInput;
	printf("입력한 모든 숫자들의 합 : [%d]\n", Sum);
}

//do
//{
//	printf("숫자를 입력하세요 : ");
//	cin >> UserInput;

//	Sum += UserInput;
//	printf("입력한 모든 숫자들의 합 : [%d]\n", Sum);
//} while (UserInput != 0);

// 2. 입력받은 수의 구구단 출력하기
printf("\n2. 입력받은 수의 구구단 출력하기\n");

int Number = 0;
printf("구구단을 출력할 숫자를 입력하세요 : ");
cin >> Number;

for (int i = 1; i < 10; i++)
{
	printf("%d x %d = [%d]\n", Number, i, Number * i);
}

// 3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기
printf("\n3. 1부터 입력받은 수까지 있는 수들 중 홀수만 출력하기\n");

int LastNumber = 0;
int TempNumber = 1;
printf("숫자를 입력하세요 : ");
cin >> LastNumber;

printf("입력받은 수까지 있는 수들 중 홀수 목록 ↓\n");
while (TempNumber <= LastNumber)
{
	printf("[%d]\n", TempNumber);
	TempNumber += 2;
}

// 4. 1~100 중 7의 배수만 출력하기
printf("\n4. 1~100 중 7의 배수만 출력하기\n");

int MultipleOf7 = 7;
while (MultipleOf7 <= 100)
{
	printf("[%d]\n", MultipleOf7);
	MultipleOf7 += 7;
}

// 5. 팩토리얼 계산하기
printf("\n5. 팩토리얼 계산하기\n");

int FactorialNumber = 0;
unsigned long long Result = 1;
printf("숫자를 입력하세요 : ");
cin >> FactorialNumber;

for (int i = FactorialNumber; i > 0; i--)
{
	Result *= i;
}

printf("[%d]! = [%llu]\n", FactorialNumber, Result);

// 6. *로 피라미드 모양의 삼각형 찍기
//   - 입력값 : 피라미드 층수
//  *   -> n-1
// ***
//***** -> 2n-1
printf("\n6. *로 피라미드 모양의 삼각형 찍기\n");

int PyramidFloor = 0;
printf("피라미드의 층을 입력하세요 : ");
cin >> PyramidFloor;

for (int CurrentFloor = 1; CurrentFloor <= PyramidFloor; CurrentFloor++)
{
	int n1 = PyramidFloor - CurrentFloor;
	for (int j = 0; j < n1; j++)
	{
		printf(" ");
	}

	int n2 = 2 * CurrentFloor - 1;
	for (int j = 0; j < n2; j++)
	{
		printf("*");
	}

	//for (int j = 0; j < n1; j++)
	//{
	//	printf(" ");
	//}

	printf("\n");
}

**************************************************/

/**************************************************

// 랜덤
srand(time(0));
int RandomNumber = 0;

for (int i = 0; i < 10; i++)
{
	RandomNumber = rand() % 6 + 1;
	printf("Random : %d\n", RandomNumber);
}

**************************************************/
