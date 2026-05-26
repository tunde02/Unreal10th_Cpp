#include <iostream>
#include "Day0526.h"

void Day0526()
{
	/*

	// 포인터
	char* pTestString = nullptr; // 보통 char*은 문자열이라고 부른다
	int* pInt = nullptr;
	float* pFloat = nullptr;

	int Data = 10;
	int* IntegerAddress = &Data;
	int Temp1 = *IntegerAddress;       // Temp1 = Data = 10
	int Temp2 = (*IntegerAddress) * 2; // Temp2 = Data * 2 = 20

	IntegerAddress = IntegerAddress + 1; // Data의 주소가 0x10이었다면, 결과는 0x14. int의 크기가 4바이트이기 때문
	IntegerAddress++; // 0x18
	IntegerAddress--; // 0x14

	int Array[5] = { 1, 2, 3, 4, 5 };
	int* pArray = Array;
	//Array[1];
	//pArray + 1;

	printf("Array의 4번째 요소 : %u\n", *(pArray + 3)); // pArray를 이용해 Array의 4번째 요소 출력
	Day0526_PointerParameter(Array, 5);

	*/

	// 간단 실습
	int a = 10, b = 8;
	Day0526_Example_01(&a, &b);
	printf("%d %d\n", a, b);

	int Array[5] = { 1, 2, 3, 4, 5 };
	int Max = Day0526_Example_02(Array, 5);
	printf("Array의 최대값 : %d\n", Max);

	Day0526_Example_03(Array, 5);
	for (int Element : Array)
	{
		printf("%d ", Element);
	}
	printf("\n");
}

void Day0526_PointerParameter(int* Data, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", *(Data + i));
	}
	printf("\n");
}

void Day0526_Example_01(int* a, int* b)
{
	// 1. 두 변수의 값을 변경하는 함수 만들기
	int Temp = *a;
	*a = *b;
	*b = Temp;
}

int Day0526_Example_02(int* Array, int Size)
{
	// 2. 포인터를 이용해서 배열의 최대값 찾는 함수 만들기
	int Max = *Array;
	for (int i = 0; i < Size; i++)
	{
		if (Max < *(Array + i))
		{
			Max = *(Array + i);
		}
	}

	return Max;
}

void Day0526_Example_03(int* Array, int Size)
{
	// 3. 포인터를 이용해서 배열의 순서를 뒤집는 함수 만들기
	int Count = Size / 2;
	for (int i = 0; i < Count; i++)
	{
		int Temp = *(Array + i);
		*(Array + i) = *(Array + Size - 1 - i);
		*(Array + Size - 1 - i) = Temp;
	}
}
