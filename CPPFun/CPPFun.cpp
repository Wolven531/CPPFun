// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

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

			// NOTE: Iterative pass
			cout << "[Iterative] Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << prompter.getNewLine();

			auto startIterative = chrono::high_resolution_clock::now();
			auto resultIterative(fibo.GetNthDigit(n));
			auto endIterative = chrono::high_resolution_clock::now();

			chrono::duration<double> elapsedIterative = endIterative - startIterative;
			cout << "\t[Iterative] Result = " << resultIterative << " [time=" << elapsedIterative.count() << " secs]" << prompter.getNewLine();

			// NOTE: Recursive pass
			cout << "[Recursive] Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << prompter.getNewLine();

			auto startRecursive = chrono::high_resolution_clock::now();
			auto resultRecursive(fibo.GetNthDigitRecursive(n));
			auto endRecursive = chrono::high_resolution_clock::now();

			chrono::duration<double> elapsedRecursive = endRecursive - startRecursive;
			cout << "\t[Recursive] Result = " << resultRecursive << " [time=" << elapsedRecursive.count() << " secs]" << prompter.getNewLine();
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