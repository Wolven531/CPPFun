#include "pch.h"
#include "Fibonacci.h"

int Fibonacci::GetNthDigit(int n)
{
	auto result(1);

	if (n < 3) {
		return result;
	}

	auto num1(1);
	auto num2(1);

	for (auto i(3); i <= n; i++) {
		result = num1 + num2;
		num1 = num2;
		num2 = result;
	}

	return result;
}
