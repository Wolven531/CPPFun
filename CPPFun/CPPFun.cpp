// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>

#include "CPPFun.h"
#include "Fibonacci.h"
#include "Prompter.h"

int main()
{
	Fibonacci fibo;
	Prompter prompter;

	prompter.displayGreeting("Hello!");
	auto nthDigitStr(prompter.promptForString("Please enter a value and press [Enter]", false));
	int n;

	try {
		n = stoi(nthDigitStr);
		cout << "Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << prompter.getNewLine();

		auto result(fibo.GetNthDigit(n));

		cout << "Result = " << result << prompter.getNewLine();
	}
	catch (const invalid_argument& invalidArgEx) {
		//cerr << "Could not parse integer value from input: " << invalidArgEx.what() << prompter.getNewLine();
		cerr << "Could not parse integer value from input ('" << nthDigitStr << "'), ending..." << prompter.getNewLine();
	}

	return 0;
}