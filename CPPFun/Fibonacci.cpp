#include "pch.h"
#include "Fibonacci.h"

int Fibonacci::GetNthDigit(int n)
{
	int result = 1;

	if (n < 3) {
		return result;
	}

	int num1 = 1;
	int num2 = 1;

	for (int i(3); i <= n; i++) {
		result = num1 + num2;
		num1 = num2;
		num2 = result;
	}

	return result;
}

int Fibonacci::GetNthDigitDynamic(int n)
{
	if (n < 3) {
		return 1;
	}

	//auto results(new int[n]);
	int *results = new int[n];
	results[0] = 1;
	results[1] = 1;

	for (int(i) = 2; i < n; i++) {
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
