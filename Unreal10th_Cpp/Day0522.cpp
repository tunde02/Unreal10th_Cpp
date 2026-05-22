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
