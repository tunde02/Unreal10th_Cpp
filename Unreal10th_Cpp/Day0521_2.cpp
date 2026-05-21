#include <iostream>
#include "Day0521_2.h"

int Add(int Num1, int Num2)
{
	return Num1 + Num2;
}

int Sub(int Num1, int Num2)
{
	return Num1 - Num2;
}

int Multiply(int Num1, int Num2)
{
	return Num1 * Num2;
}

int Divide(int Num1, int Num2)
{
	if (Num2 != 0)
	{
		return Num1 / Num2;
	}

	printf("ERROR: 0으로는 나눌 수 없습니다.\n");
	return 0;
}

void Test()
{
	return;
}
