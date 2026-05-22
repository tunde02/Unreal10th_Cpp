#include <iostream>
#include "Day0522.h"
using std::cin;

void Day0522_Array()
{
	// 배열
	int Numbers[3] = { 0 };

	Numbers[0] = 10; // 배열의 각 요소에 접근하는 방식
	Numbers[1] = 20;
	Numbers[2] = 30;

	Numbers[1] = Numbers[0]; // Numbers의 첫 번째 요소를 두 번째 요소에 대입하기

	//Number[3] = 100; // 범위를 벗어난 접근은 불가능

	int Array1[5] = { 1, 2, 3, 4, 5 };
	int Array2[5] = { 1, 2 };

	int ArraySize = sizeof(Array1);
	printf("ArraySize : %d Byte\n", ArraySize);

	int ArrayCount = ArraySize / sizeof(int);
	printf("ArrayCount : %d\n", ArrayCount);

	// 2차원 배열
	int Array3[4][3] = { 0 }; // "int 3개짜리 배열이 4개 있다"는 뜻
	int Array4[4][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} }; // Array[12]와 메모리상의 구조는 똑같다
}

void Day0522_Array_Example01()
{
	// 1. 배열 만들고 초기화하고 전부 출력해보기 (1차원, 2차원 모두)
	int Array1[5] = { 100, 30, 3587, 123875, 777 };
	const int Array1Count = sizeof(Array1) / sizeof(int);

	int Array2[3][4] = {
		{1, 2, 3, 4},
		{1000, 2000, 5000, 10000},
		{918, 112948, 105, 489351}
	};
	const int Array2RowCount = sizeof(Array2) / sizeof(Array2[0]);
	const int Array2ColumnCount = sizeof(Array2) / (Array2RowCount * sizeof(int));

	bool bInitializeRandomInt = true;
	if (bInitializeRandomInt)
	{
		for (int i = 0; i < Array1Count; i++)
		{
			Array1[i] = rand();
		}
		for (int i = 0; i < Array2RowCount; i++)
		{
			for (int j = 0; j < Array2ColumnCount; j++)
			{
				Array2[i][j] = rand();
			}
		}
	}

	printf("1-1. 배열 만들고 초기화하고 전부 출력해보기 - 1차원\n");
	for (int i = 0; i < Array1Count; i++)
	{
		printf("Array1[%d] = %d\n", i, Array1[i]);
	}
	printf("\n");

	printf("1-2. 배열 만들고 초기화하고 전부 출력해보기 - 2차원\n");
	for (int i = 0; i < Array2RowCount; i++)
	{
		for (int j = 0; j < Array2ColumnCount; j++)
		{
			printf("Array2[%d][%d] = %6d   ", i, j, Array2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void Day0522_Array_Example02()
{
	// 2. 배열 내부의 값을 모두 더하고 평균 구해보기
	int Array1[5] = { 100, 30, 3587, 123875, 777 };
	const int Array1Count = sizeof(Array1) / sizeof(int);

	int Array2[3][4] = {
		{1, 2, 3, 4},
		{1000, 2000, 5000, 10000},
		{918, 112948, 105, 489351}
	};
	const int Array2RowCount = sizeof(Array2) / sizeof(Array2[0]);
	const int Array2ColumnCount = sizeof(Array2) / (Array2RowCount * sizeof(int));

	bool bInitializeRandomInt = true;
	if (bInitializeRandomInt)
	{
		for (int i = 0; i < Array1Count; i++)
		{
			Array1[i] = rand();
		}
		for (int i = 0; i < Array2RowCount; i++)
		{
			for (int j = 0; j < Array2ColumnCount; j++)
			{
				Array2[i][j] = rand();
			}
		}
	}

	printf("2. 배열 내부의 값을 모두 더하고 평균 구해보기\n");

	int Sum1 = 0, Sum2 = 0;
	float Average1 = 0, Average2 = 0;

	for (int i = 0; i < Array1Count; i++)
	{
		Sum1 += Array1[i];
	}
	Average1 = (float)Sum1 / Array1Count;

	for (int i = 0; i < Array2RowCount; i++)
	{
		for (int j = 0; j < Array2ColumnCount; j++)
		{
			Sum2 += Array2[i][j];
		}
	}
	Average2 = (float)Sum2 / (Array2RowCount * Array2ColumnCount);

	printf("Array1의 모든 원소의 합 : %d\n", Sum1);
	printf("Array1의 원소들의 평균 : %.1f\n", Average1);
	printf("\n");

	printf("Array2의 모든 원소의 합 : %d\n", Sum2);
	printf("Array2의 원소들의 평균 : %.1f\n", Average2);
	printf("\n");
}

void Day0522_Array_Example03()
{
	// 3. 배열의 값 중 최대값과 최소값 구해보기
	int Array1[5] = { 100, 30, 3587, 123875, 777 };
	const int Array1Count = sizeof(Array1) / sizeof(int);

	int Array2[3][4] = {
		{1, 2, 3, 4},
		{1000, 2000, 5000, 10000},
		{918, 112948, 105, 489351}
	};
	const int Array2RowCount = sizeof(Array2) / sizeof(Array2[0]);
	const int Array2ColumnCount = sizeof(Array2) / (Array2RowCount * sizeof(int));

	bool bInitializeRandomInt = true;
	if (bInitializeRandomInt)
	{
		for (int i = 0; i < Array1Count; i++)
		{
			Array1[i] = rand();
		}
		for (int i = 0; i < Array2RowCount; i++)
		{
			for (int j = 0; j < Array2ColumnCount; j++)
			{
				Array2[i][j] = rand();
			}
		}
	}

	printf("3. 배열의 값 중 최대값과 최소값 구해보기\n");

	int Max1 = INT32_MIN, Max2 = INT32_MIN;
	int Min1 = INT32_MAX, Min2 = INT32_MAX;
	int Max1Index = 0, Min1Index = 0;
	int Max2RowIndex = 0, Max2ColumnIndex = 0, Min2RowIndex = 0, Min2ColumnIndex = 0;

	for (int i = 0; i < Array1Count; i++)
	{
		if (Max1 < Array1[i])
		{
			Max1 = Array1[i];
			Max1Index = i;
		}

		if (Min1 > Array1[i])
		{
			Min1 = Array1[i];
			Min1Index = i;
		}
	}

	for (int i = 0; i < Array2RowCount; i++)
	{
		for (int j = 0; j < Array2ColumnCount; j++)
		{
			if (Max2 < Array2[i][j])
			{
				Max2 = Array2[i][j];
				Max2RowIndex = i;
				Max2ColumnIndex = j;
			}

			if (Min2 > Array2[i][j])
			{
				Min2 = Array2[i][j];
				Min2RowIndex = i;
				Min2ColumnIndex = j;
			}
		}
	}

	printf("Array1의 최대값 : Array1[%d] = %d\n", Max1Index, Max1);
	printf("Array1의 최소값 : Array1[%d] = %d\n", Min1Index, Min1);
	printf("\n");

	printf("Array2의 최대값 : Array2[%d][%d] = %d\n", Max2RowIndex, Max2ColumnIndex, Max2);
	printf("Array2의 최소값 : Array2[%d][%d] = %d\n", Min2RowIndex, Min2ColumnIndex, Min2);
	printf("\n");
}

void Day0522_Casting()
{
	// C 스타일 캐스팅
	int Integer = 10;
	float RealNumber = (float)Integer; // Integer에 있는 값을 float타입으로 임시 변경한 후 RealNumber에 저장

	bool Boolean = (bool)Integer;
	Boolean = (bool)0;

	// C++ 스타일 캐스팅
	// static_cast
	RealNumber = static_cast<float>(Integer);
}

void Day0522_Reference()
{
	// 참조
	int Number = 10;
	int Number2 = 20;
	int& NumRef = Number;
	// int& Ref; // 선언할 때 지정해줘야 함

	Number = 100; // 참조하고 있는 변수인 Number의 값이 100이 된다
	NumRef = Number2; // 재지정이 아니라, 참조한 변수에 Number2 값을 넘겨주라는 의미임

	int Data1 = 0, Data2 = 0, Data3 = 0;
	Test_Reference(Data1, Data2, Data3);
	printf("%d %d %d\n", Data1, Data2, Data3); // 10 20 30
}

void Test_Reference(int& OutData1, int& OutData2, int& OutData3)
{
	OutData1 = 10;
	OutData2 = 20;
	OutData3 = 30;
}

void Day0522_ArrayParameter()
{
	//const int Length = 5;
	//int Array[Length] = { 10, 50, 30, 20, 40 };

	// 포인터(*)와 배열은 근본적으로 같다
	//Test_ArrayParameter(Array, Length);

	// 간단 실습
	const int Length = 6;
	int Array[Length] = { 1, 10, 20, 100, 1000, 77777 };

	Day0522_ArrayParameter_Example01(Array, Length);
	Day0522_ArrayParameter_Example02(Array, Length);

	const int DataSize = 100;
	int Data[DataSize] = { 0 };
	for (int i = 0; i < DataSize; i++)
	{
		Data[i] = i;
	}
	Day0522_ArrayParameter_Example03(Data, DataSize);
}

void Test_ArrayParameter(int* Array, int Length)
{
	printf("[ ");
	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}

void FisherYatesShuffle(int* Array, int Length)
{
	// 1. 배열의 마지막 요소부터 반대방향으로 순회한다
	// 2. 0~인덱스 까지의 요소들 중 임의로 선택
	// 3. 인덱스가 가리키는 요소와 임의로 선택한 요소를 교환
	// 4. 인덱스 1 감소
	// 5. 2~4 반복. 인덱스가 0이 되면 종료

	for (int i = Length - 1; i > -1; i--)
	{
		int RandomIndex = rand() % (i + 1);

		int Temp = Array[RandomIndex];
		Array[RandomIndex] = Array[i];
		Array[i] = Temp;
	}
}

void Day0522_ArrayParameter_Example01(int* Array, int Length)
{
	// 1. 배열의 값들을 전부 출력해주는 함수 만들기

	printf("Array : [ ");
	for (int i = 0; i < Length; i++)
	{
		printf("%d ", Array[i]);
	}
	printf("]\n");
}

void Day0522_ArrayParameter_Example02(int* Array, int Length)
{
	// 2. 배열을 파라미터로 받는 함수를 만들어 구현하기
	//   - 배열 내부값을 모두 더하고 평균 구해보기
	//   - 배열의 값 중 최대값과 최소값 구해보기

	int Sum = 0;
	float Average = 0;
	int Min = INT32_MAX, Max = INT32_MIN;

	SumAndAverageOfArray(Array, Length, Sum, Average);
	MinAndMaxOfArray(Array, Length, Min, Max);

	printf("배열 원소들의 합 : %d\n", Sum);
	printf("배열 원소들의 평균 : %.1f\n", Average);
	printf("배열 원소들의 최소값 : %d\n", Min);
	printf("배열 원소들의 최대값 : %d\n", Max);
}

void SumAndAverageOfArray(int* Array, int Length, int& OutSum, float& OutAverage)
{
	for (int i = 0; i < Length; i++)
	{
		OutSum += Array[i];
	}

	OutAverage = OutSum / (float)Length;
}

void MinAndMaxOfArray(int* Array, int Length, int& OutMin, int& OutMax)
{
	for (int i = 0; i < Length; i++)
	{
		OutMax = OutMax < Array[i] ? Array[i] : OutMax;
		OutMin = OutMin > Array[i] ? Array[i] : OutMin;
	}
}

void Day0522_ArrayParameter_Example03(int* Array, int Length)
{
	// 3. 피셔-예이츠 알고리즘 완성하기

	FisherYatesShuffle(Array, Length);
	printf("\n<Shuffled Array>\n");
	Day0522_ArrayParameter_Example01(Array, Length);
}

void Day0522_Practice01()
{
	// 1. 6면체 주사위를 100만번 던져서 각 눈의 수가 몇번 나왔는지 카운팅하기(배열 활용하기)

	const int DiceSize = 6;
	int DiceCounts[DiceSize] = { 0 };

	for (int i = 0; i < 1000000; i++)
	{
		int Dice = (rand() % DiceSize) + 1;
		DiceCounts[Dice - 1] += 1;
	}

	printf("[나온 각 눈의 횟수]\n");
	for (int i = 0; i < DiceSize; i++)
	{
		printf("눈 %d : [%d]회\n", i + 1, DiceCounts[i]);
	}

	printf("\n");
}

void Day0522_Practice02()
{
	// 2. 배열에 저장된 값을 거꾸로 뒤집는 함수 만들기(파라메터 : int* Array, int Size)

	const int Length = 10;
	int Array[Length] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	printf("원본 배열 : ");
	Test_ArrayParameter(Array, Length);

	FlipArray(Array, Length);

	printf("뒤집은 배열 : ");
	Test_ArrayParameter(Array, Length);

	printf("\n");
}

void FlipArray(int* Array, int Length)
{
	int HalfLength = Length / 2;
	for (int i = 0; i < HalfLength; i++)
	{
		int Temp = Array[i];
		Array[i] = Array[Length - i - 1];
		Array[Length - i - 1] = Temp;
	}
}

void Day0522_Practice03()
{
	// 3. 로또 번호 생성기(셔플알고리즘 활용하기)
	// - 전체 숫자 범위 : 1번부터 45번까지
	// - 맞춰야 하는 숫자 개수 : 6개

	const int Length = 45;
	const int CountToWin = 6;
	int LotteryNumbers[Length] = { 0 };

	for (int i = 0; i < Length; i++)
	{
		LotteryNumbers[i] = i + 1;
	}

	FisherYatesShuffle(LotteryNumbers, Length);

	printf("로또 번호 : [ ");
	for (int i = 0; i < CountToWin; i++)
	{
		printf("%d ", LotteryNumbers[i]);
	}
	printf("]\n");

	printf("\n");
}

void Day0522_Practice04()
{
	/*
	4. 미로 탈출 게임 만들기
		- 2차원 배열을 활용하여 텍스트 기반 미로 탈출 게임을 구현.
		- 미로의 구성
		- 10행 20열의 2차원 배열
		- 저장 방식
		- 길(0) : '. '으로 표시
		- 벽(1) : '# '으로 표시
		- 시작점(2) : 'S '로 표시
		- 출구(3) : 'E '로 표시
		- 이동 입력 처리
		- w(W) : 위, s(S) : 아래, a(A) : 왼쪽, d(D) : 오른쪽
		- 대소문자 구분 없이 처리
		- 플레이어가 출구에 도착하면 종료
		- 플레이어는 ‘P ‘로 표시
		- 게임 화면은 다음과 같은 양식을 따른다.
		- w(↑) s(↓) a(←) d(→)는 이동 가능한 방향만 출력한다.
		- 출력 예시
			== = 텍스트 미로 탈출 게임 == =
			[미로 화면 출력]
			이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽) :
			w(↑) s(↓) a(←) d(→)
			방향 입력 :
	*/

	// 미로 크기
	const int MazeRows = 10;
	const int MazeCols = 10;

	// 미로 배열
	int Maze[MazeRows][MazeCols] = {
		{1,1,1,1,1,1,1,1,1,1},
		{1,2,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,0,1,0,1},
		{1,0,1,3,1,1,0,1,0,1},
		{1,0,1,0,0,0,0,1,0,1},
		{1,0,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};

	const int StartX = 1;
	const int StartY = 1;
	const int EndX = 5;
	const int EndY = 3;
	int PlayerX = StartX;
	int PlayerY = StartY;
	TileType PlayerGround = Start; // 현재 플레이어가 밝고 있는 타일의 종류

	// 플레이어 초기 위치 설정
	PlayerGround = IntToTileType(Maze[PlayerX][PlayerY]);
	Maze[PlayerX][PlayerY] = TileTypeToint(Player);

	printf("== = 텍스트 미로 탈출 게임 == =\n");

	while (!IsPlayerWin(PlayerX, PlayerY, EndX, EndY))
	{
		ShowMaze((int*)Maze, MazeRows, MazeCols);

		printf("이동할 수 있는 방향을 선택하세요(w: 위, s : 아래, a : 왼쪽, d : 오른쪽)\n");
		ShowMovableDirections((int*)Maze, MazeRows, MazeCols, PlayerX, PlayerY);
		printf("\n : ");

		DirectionType PlayerInputDirection = InputDirection();
		if (PlayerInputDirection == DirectionCount)
		{
			continue;
		}

		int NextX = PlayerX;
		int NextY = PlayerY;
		switch (PlayerInputDirection)
		{
		case Up:
			NextX += -1;
			NextY += 0;
			break;
		case Down:
			NextX += 1;
			NextY += 0;
			break;
		case Left:
			NextX += 0;
			NextY += -1;
			break;
		case Right:
			NextX += 0;
			NextY += 1;
			break;
		default:
			break;
		}

		if (CanMoveTo((int*)Maze, MazeRows, MazeCols, PlayerX, PlayerY, PlayerInputDirection))
		{
			Maze[PlayerX][PlayerY] = TileTypeToint(PlayerGround);
			PlayerGround = IntToTileType(Maze[NextX][NextY]);
			Maze[NextX][NextY] = TileTypeToint(Player);
			PlayerX = NextX;
			PlayerY = NextY;
		}
	}

	ShowMaze((int*)Maze, MazeRows, MazeCols);
}

void ShowMaze(int* Array, int RowLength, int ColumnLength)
{
	for (int i = 0; i < RowLength; i++)
	{
		for (int j = 0; j < ColumnLength; j++)
		{
			int Tile = *(Array + (i * ColumnLength) + j);
			switch (Tile)
			{
			case Road:
				printf(". ");
				break;
			case Wall:
				printf("# ");
				break;
			case Start:
				printf("S ");
				break;
			case End:
				printf("E ");
				break;
			case Player:
				printf("P ");
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

TileType IntToTileType(int TileInt)
{
	switch (TileInt)
	{
	case 0:
		return Road;
	case 1:
		return Wall;
	case 2:
		return Start;
	case 3:
		return End;
	case 4:
		return Player;
	default:
		return Road;
	}
}

int TileTypeToint(TileType Tile)
{
	switch (Tile)
	{
	case Road:
		return 0;
	case Wall:
		return 1;
	case Start:
		return 2;
	case End:
		return 3;
	case Player:
		return 4;
	default:
		return 0;
	}
}

DirectionType IntToDirection(int DirectionInt)
{
	switch (DirectionInt)
	{
	case 0:
		return Up;
	case 1:
		return Down;
	case 2:
		return Left;
	case 3:
		return Right;
	default:
		return DirectionCount;
	}
}

int DirectionTypeToInt(DirectionType Direction)
{
	switch (Direction)
	{
	case Up:
		return 0;
	case Down:
		return 1;
	case Left:
		return 2;
	case Right:
		return 3;
	case DirectionCount:
		return 4;
	default:
		return 0;
	}
}

bool IsPlayerWin(int PlayerX, int PlayerY, int EndX, int EndY)
{
	return (PlayerX == EndX) && (PlayerY == EndY);
}

bool CanMoveTo(int* Array, int RowLength, int ColumnLength, int PlayerX, int PlayerY, DirectionType Direction)
{
	const int Dx[4] = { -1, 1, 0, 0 };
	const int Dy[4] = { 0, 0, -1, 1 };
	int DirectionIndex = DirectionTypeToInt(Direction);
	int NextX = PlayerX + Dx[DirectionIndex];
	int NextY = PlayerY + Dy[DirectionIndex];

	return (-1 < NextX && NextX < RowLength) && (-1 < NextY && NextY < ColumnLength)
		&& IntToTileType(*(Array + (NextX * ColumnLength) + NextY)) != Wall;
}

void ShowMovableDirections(int* Array, int RowLength, int ColumnLength, int PlayerX, int PlayerY)
{
	printf("이동 가능한 방향 : ");
	if (CanMoveTo(Array, RowLength, ColumnLength, PlayerX, PlayerY, Up))
	{
		printf("w(↑) ");
	}
	if (CanMoveTo(Array, RowLength, ColumnLength, PlayerX, PlayerY, Down))
	{
		printf("s(↓) ");
	}
	if (CanMoveTo(Array, RowLength, ColumnLength, PlayerX, PlayerY, Left))
	{
		printf("a(←) ");
	}
	if (CanMoveTo(Array, RowLength, ColumnLength, PlayerX, PlayerY, Right))
	{
		printf("d(→) ");
	}
}

DirectionType InputDirection()
{
	char PlayerInput = 0;

	cin >> PlayerInput;
	cin.clear();
	cin.ignore(10000, '\n');

	DirectionType Direction = DirectionCount;
	switch (PlayerInput)
	{
	case 'w':
	case 'W':
		Direction = Up;
		break;
	case 's':
	case 'S':
		Direction = Down;
		break;
	case 'a':
	case 'A':
		Direction = Left;
		break;
	case 'd':
	case 'D':
		Direction = Right;
		break;
	default:
		break;
	}

	return Direction;
}
