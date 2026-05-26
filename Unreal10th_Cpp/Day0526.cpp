#include <iostream>
#include "Day0526.h"

void Day0526()
{
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
}

void Day0526_PointerParameter(int* Data, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%d ", *(Data + i));
	}
	printf("\n");
}
