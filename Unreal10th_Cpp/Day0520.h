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

/**************************************************

// 랜덤 간단 실습
// 1. 가위 바위 보 게임 만들기
//   - 3선승제
//   - enum 활용
printf("\n1. 가위 바위 보 게임 만들기\n");

srand(time(0));

enum Shape
{
	Rock = 1,
	Scissors,
	Paper
};
int WinCount = 0;

while (WinCount < 3)
{
	int UserShape = 0;
	printf("가위, 바위, 보 중 하나를 선택하세요\n");
	printf("1. 바위   2. 가위   3. 보\n");
	printf(": ");
	cin >> UserShape;

	int ComputerShape = (rand() % 3) + 1;

	switch (UserShape)
	{
	case Rock:
		if (ComputerShape == Scissors)
		{
			printf("승리!! (유저 : 바위, 컴퓨터 : 가위)\n");
			WinCount += 1;
		}
		else if (ComputerShape == Rock)
		{
			printf("무승부 (유저 : 바위, 컴퓨터 : 바위)\n");
		}
		else
		{
			printf("패배... (유저 : 바위, 컴퓨터 : 보)\n");
		}
		break;
	case Scissors:
		if (ComputerShape == Paper)
		{
			printf("승리!! (유저 : 가위, 컴퓨터 : 보)\n");
			WinCount += 1;
		}
		else if (ComputerShape == Scissors)
		{
			printf("무승부 (유저 : 가위, 컴퓨터 : 가위)\n");
		}
		else
		{
			printf("패배... (유저 : 가위, 컴퓨터 : 바위)\n");
		}
		break;
	case Paper:
		if (ComputerShape == Rock)
		{
			printf("승리!! (유저 : 보, 컴퓨터 : 바위)\n");
			WinCount += 1;
		}
		else if (ComputerShape == Paper)
		{
			printf("무승부 (유저 : 보, 컴퓨터 : 보)\n");
		}
		else
		{
			printf("패배... (유저 : 보, 컴퓨터 : 가위)\n");
		}
		break;
	default:
		break;
	}
}

printf("%d번 승리하셨습니다!!\n", WinCount);

// 2. 하이 로우
//   - 컴퓨터가 1~100 사이의 임의의 숫자를 선택하고, 사용자가 맞출 때까지 입력을 받아 "더 높게", "더 낮게" 등의 힌트를 준다
//   - 5번 안에 맞추면 승리
printf("\n2. 하이 로우\n");

int Count = 0;
int RandomNumber = (rand() % 100) + 1;
int UserNumber = -1;

while (UserNumber != RandomNumber && Count < 6)
{
	Count++;
	printf("숫자를 입력하세요(1 ~ 100) : ");
	cin >> UserNumber;

	if (UserNumber > RandomNumber)
	{
		printf("컴퓨터의 숫자는 %d보다 작습니다.\n", UserNumber);
	}
	else if (UserNumber < RandomNumber)
	{
		printf("컴퓨터의 숫자는 %d보다 큽니다.\n", UserNumber);
	}
}

if (Count <= 5)
{
	printf("승리!!\n");
}
else
{
	printf("패배.. (컴퓨터의 숫자 : %d)\n", RandomNumber);
}

**************************************************/

/**************************************************


// 랜덤 실습
srand(time(0));

//1. 비트플래그를 이용한 캐릭터 상태 변환 구현하기
//    - 캐릭터의 상태는 대기, 점프, 공격, 무적 4가지가 존재
//    - 다음 작업을 수행하고 현재 상태 출력하기
//    - 플레이어의 상태를 대기로 설정
//    - 점프 상태 추가
//    - 공격 상태 추가
//    - 대기 상태 해제
//    - 무적 상태 추가
//    - 무적 상태 토글(XOR 사용)
//    - 현재 상태를 출력할 때는 다음과 같은 양식을 따를 것
//    - 대기 : [O] , 점프 : [O] , 공격 : [X] , 무적 : [O]
enum PlayerState
{
	Idle = 1 << 0,
	Jump = 1 << 1,
	Attack = 1 << 2,
	God = 1 << 3
};
int CurrentPlayerState = 0;
char IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
char JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
char AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
char GodOX = CurrentPlayerState & God ? 'O' : 'X';

printf("[초기 상태]\n");
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);

printf("[플레이어의 상태를 대기로 설정]\n");
CurrentPlayerState |= Idle;
IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
GodOX = CurrentPlayerState & God ? 'O' : 'X';
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);

printf("[점프 상태 추가]\n");
CurrentPlayerState |= Jump;
IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
GodOX = CurrentPlayerState & God ? 'O' : 'X';
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);

printf("[공격 상태 추가]\n");
CurrentPlayerState |= Attack;
IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
GodOX = CurrentPlayerState & God ? 'O' : 'X';
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);

printf("[대기 상태 해제]\n");
CurrentPlayerState &= ~Idle;
IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
GodOX = CurrentPlayerState & God ? 'O' : 'X';
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);

printf("[무적 상태 추가]\n");
CurrentPlayerState |= God;
IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
GodOX = CurrentPlayerState & God ? 'O' : 'X';
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);

printf("[무적 상태 토글(XOR 사용)]\n");
CurrentPlayerState ^= God;
IdleOX = CurrentPlayerState & Idle ? 'O' : 'X';
JumpOX = CurrentPlayerState & Jump ? 'O' : 'X';
AttackOX = CurrentPlayerState & Attack ? 'O' : 'X';
GodOX = CurrentPlayerState & God ? 'O' : 'X';
printf("대기 : [%c] , 점프 : [%c] , 공격 : [%c] , 무적 : [%c]\n\n", IdleOX, JumpOX, AttackOX, GodOX);


//2. 주사위 게임
//    1. 초기 세팅
//    - 플레이어와 컴퓨터 모두 일정 금액(예: 10000원)으로 시작한다.
//    2. 1차 주사위 굴리기
//    - 게임 시작 시, 플레이어와 컴퓨터가 각각 주사위(1~6)를 한 번 굴린다.
//    - 각자 주사위 결과를 공개한다.
//    3. 배팅
//    - 이전 판에서 진 쪽이 배팅 금액을 제시한다.
//    - 제시한 배팅 금액은 두 사람 모두의 현재 소지 금액 이하이어야 한다.
//    - 배팅 금액은 두 사람 모두에게서 차감된다.
//    4. 2차 주사위 굴리기
//    - 다시 플레이어와 컴퓨터가 각각 주사위를 한 번씩 굴린다.
//    - (1차 + 2차) 주사위의 합을 계산한다.
//    5. 승패 판정 및 금액 증감
//    - 합이 더 큰 쪽이 배팅 금액의 총합(즉, 2×배팅금액)을 모두 가져간다.
//    - 동점일 경우 배팅 금액은 그대로 반환한다.
//    6. 다음 판 진행
//    - 소지금이 0 이하인 쪽이 나오면 게임 종료.
const int InitialCash = 10000;
const int ComputerBetAmount = 1000;
const int DiceSize = 6;
int PlayerCash = InitialCash, ComputerCash = InitialCash;
int PlayerDice1 = 0, ComputerDice1 = 0;
int PlayerDice2 = 0, ComputerDice2 = 0;
int PlayerDiceSum = 0, ComputerDiceSum = 0;
int MaxBetAmount = 0;
int BetAmount = 0;
bool PlayerLost = false;

while (PlayerCash > 0 && ComputerCash > 0)
{
	printf("\n=====[게임 시작]=====\n");
	PlayerDice1 = 0;
	PlayerDice2 = 0;
	PlayerDiceSum = 0;
	ComputerDice1 = 0;
	ComputerDice2 = 0;
	ComputerDiceSum = 0;

	// 1차 주사위 굴리기
	PlayerDice1 = (rand() % DiceSize) + 1;
	ComputerDice1 = (rand() % DiceSize) + 1;
	printf("\n[1차 주사위 굴리기]\n");
	printf("플레이어 : %d  |  컴퓨터 : %d\n", PlayerDice1, ComputerDice1);

	// 배팅
	MaxBetAmount = PlayerCash < ComputerCash ? PlayerCash : ComputerCash;
	BetAmount = 0;
	if (PlayerLost)
	{
		do
		{
			printf("[소지 금액 : %d$]  [컴퓨터 소지 금액 : %d$]\n", PlayerCash, ComputerCash);
			printf("배팅 금액을 입력하세요 : ");
			cin >> BetAmount;
			cin.clear();				// 에러 상태 해제
			cin.ignore(10000, '\n');	// 이전 입력 버퍼 제거. \n 나올 때까지 최대 10000글자 제거

			if (BetAmount <= 0 || BetAmount > MaxBetAmount)
			{
				printf("적절한 배팅 금액을 다시 입력해주세요.\n");
			}
		} while (BetAmount <= 0 || BetAmount > MaxBetAmount);
	}
	else
	{
		BetAmount = (rand() % MaxBetAmount) + 1;
	}
	printf("\n[배팅 금액 : %d$]\n", BetAmount);

	PlayerCash -= BetAmount;
	ComputerCash -= BetAmount;
	printf("[배팅 금액이 소지금에서 차감됐습니다]\n");
	printf("[소지 금액 : %d$]  [컴퓨터 소지 금액 : %d$]\n", PlayerCash, ComputerCash);

	// 2차 주사위 굴리기
	PlayerDice2 = (rand() % DiceSize) + 1;
	ComputerDice2 = (rand() % DiceSize) + 1;
	printf("\n[2차 주사위 굴리기]\n");
	printf("플레이어 : %d  |  컴퓨터 : %d\n", PlayerDice2, ComputerDice2);

	// 승패 판정 및 금액 증감
	printf("\n[승패 판정] - ");

	PlayerDiceSum = PlayerDice1 + PlayerDice2;
	ComputerDiceSum = ComputerDice1 + ComputerDice2;

	if (PlayerDiceSum > ComputerDiceSum)
	{
		printf("[플레이어가 승리했습니다!!]\n");
		PlayerCash += BetAmount * 2;
		PlayerLost = false;
	}
	else if (PlayerDiceSum < ComputerDiceSum)
	{
		printf("[플레이어가 패배했습니다..]\n");
		ComputerCash += BetAmount * 2;
		PlayerLost = true;
	}
	else
	{
		printf("[무승부]\n");
		PlayerCash += BetAmount;
		ComputerCash += BetAmount;
		PlayerLost = false;
	}

	printf("[플레이어 주사위의 합 : %d]  [컴퓨터 주사위의 합 : %d]\n", PlayerDiceSum, ComputerDiceSum);
	printf("[소지 금액 : %d$]  [컴퓨터 소지 금액 : %d$]\n", PlayerCash, ComputerCash);
}

printf("\n[주사위 게임이 종료되었습니다]\n");


//3. 홀짝 게임
//    1. 초기 금액 및 배팅
//        - 플레이어는 기본금 100원으로 베팅을 시작한다.
//    2. 홀짝 선택
//        - 플레이어가 1(홀) 또는 2(짝)을 선택한다.
//    3. 결과 결정
//        - 컴퓨터가 랜덤으로 1(홀) 또는 2(짝)을 선택한다.
//        - 플레이어의 선택과 결과가 일치하면 승리(이기면 배팅금의 2배 획득), 다르면 패배(배팅금 전액 잃음).
//    4. 연속 배팅 선택
//        - 승리 시 플레이어는 두 가지 중 하나를 선택:
//            - (A) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)
//            - (B) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작
//    5. 게임 종료 조건
//        - 플레이어가 소지금이 100원 미만일 경우 게임 종료.
const int InitialCash = 100;
const int MinimumBetAmount = 100;
int PlayerCash = InitialCash;
int BetAmount = MinimumBetAmount;
int PlayerDecision, ComputerDecision = 0;

while (PlayerCash >= InitialCash)
{
	printf("\n=====[게임 시작]  [소지 금액 : %d￦  |  현재 배팅 금액 : %d￦] =====\n", PlayerCash, BetAmount);

	// 홀짝 선택
	PlayerDecision = 0;
	while (!(PlayerDecision == 1 || PlayerDecision == 2))
	{
		printf("(1) 홀   (2)짝\n");
		printf("홀짝을 선택하세요 : ");
		cin >> PlayerDecision;
		cin.clear();
		cin.ignore(10000, '\n');

		if (!(PlayerDecision == 1 || PlayerDecision == 2))
		{
			printf("ERROR: 올바른 숫자를 입력해주세요.\n");
		}
	}

	// 결과 결정
	printf("\n[승패 판정] - ");
	ComputerDecision = (rand() % 2) + 1;
	if (PlayerDecision == ComputerDecision)
	{
		printf("플레이어가 승리했습니다!!\n");
		PlayerCash += BetAmount;

		// 연속 배팅 선택
		PlayerDecision = 0;
		while (!(PlayerDecision == 1 || PlayerDecision == 2))
		{
			printf("\n[연속 배팅 선택]  [소지 금액 : %d￦  |  현재 배팅 금액 : %d￦]\n", PlayerCash, BetAmount);
			printf("(1) 이긴 금액을 모두 다시 한 번에 배팅 (연승 도전)\n");
			printf("(2) 이긴 금액을 얻고, 다시 100원부터 새로 배팅 시작\n");
			printf("배팅 방법을 선택하세요 : ");
			cin >> PlayerDecision;
			cin.clear();
			cin.ignore(10000, '\n');

			if (!(PlayerDecision == 1 || PlayerDecision == 2))
			{
				printf("ERROR: 올바른 숫자를 입력해주세요.\n");
			}
		}

		if (PlayerDecision == 1)
		{
			BetAmount *= 2;
		}
		else
		{
			BetAmount = MinimumBetAmount;
		}
	}
	else
	{
		PlayerCash -= BetAmount;
		BetAmount = MinimumBetAmount;
		printf("플레이어가 패배했습니다..\n");
		printf("[소지 금액 : %d￦]\n", PlayerCash);
	}
}

printf("\n[홀짝 게임이 종료되었습니다]\n");

**************************************************/