#include <iostream>
#include "Day0522.h"

void Day0522_Run()
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
