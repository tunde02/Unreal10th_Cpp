#pragma once

int Add(int Num1, int Num2);

int Sub(int Num1, int Num2);

int Multiply(int Num1, int Num2);

int Divide(int Num1, int Num2);

void Test();

// Template
template <typename T>
T Add(T Num1, T Num2)
{
	T Result = Num1 + Num2;
	return Result;
}