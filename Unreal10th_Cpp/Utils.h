#pragma once
#include <iostream>

namespace Utils
{
	const int CIN_IGNORE_LENGTH = 10000;
	const char CIN_IGNORE_DELIMITER = '\n';

	template <typename T>
	T SafeInput(T DefaultValue)
	{
		T Input = DefaultValue;
		std::cin >> Input;
		std::cin.clear();
		std::cin.ignore(CIN_IGNORE_DELIMITER, CIN_IGNORE_DELIMITER);

		return Input;
	}

	void PrintDivider(wchar_t Divider, int Count);
	bool IsFloatEqual(float Num1, float Num2);
}
