// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>

#include "CPPFun.h"
#include "Fibonacci.h"
#include "Prompter.h"

using namespace std;

int main()
{
	Fibonacci fibo;
	Prompter prompter;
	auto isRunning(true);

	prompter.displayGreeting("Hello!");

	while (isRunning) {
		auto nthDigitStr(prompter.promptForString("Please enter a value and press [Enter] (or 'exit' or 'q' to quit)", false));

		try {
			auto n(stoi(nthDigitStr));
			cout << "Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << prompter.getNewLine();
			auto result(fibo.GetNthDigit(n));
			cout << "\tResult = " << result << prompter.getNewLine();
		}
		catch (const invalid_argument& invalidArgEx) {
			// TODO: ajw, 12/04/2018 - make this case invariant
			if (nthDigitStr._Equal("exit") || nthDigitStr._Equal("q")) {
				isRunning = false;
			}
			else {
				//cerr << "Could not parse integer value from input: " << invalidArgEx.what() << prompter.getNewLine();
				cerr << "Could not parse integer value from input ('" << nthDigitStr << "')" << prompter.getNewLine();
			}
		}
	}

	return 0;
}