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

int Fibonacci::GetNthDigitDynamic(int n)
{
	auto results(new int[n]);
	results[0] = 1;
	results[1] = 1;

	if (n <= 2) {
		return results[n - 1];
	}

	for (auto(i) = 2; i < sizeof(results); i++) {
		results[i] = results[i - 2] + results[i - 1];
	}

	return results[n - 1];
}

int Fibonacci::GetNthDigitRecursive(int n)
{
	if (n < 3) {
		return 1;
	}

	return GetNthDigitRecursive(n - 1) + GetNthDigitRecursive(n - 2);
}
