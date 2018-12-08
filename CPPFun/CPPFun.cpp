// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include "CPPFun.h"
#include "Fibonacci.h"
#include "Prompter.h"

using namespace std;

void timedIterativePass(Fibonacci fibo, int n)
{
	cout << "[Iterative] Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << Prompter::getNewLine();

	auto start = chrono::high_resolution_clock::now();
	auto result(fibo.GetNthDigit(n));
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout << "\t[Iterative] Result = " << result << " [time=" << elapsed.count() << " secs]" << Prompter::getNewLine();
}

void timedRecursivePass(Fibonacci fibo, int n)
{
	cout << "[Recursive] Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << Prompter::getNewLine();

	auto start = chrono::high_resolution_clock::now();
	auto result(fibo.GetNthDigitRecursive(n));
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout << "\t[Recursive] Result = " << result << " [time=" << elapsed.count() << " secs]" << Prompter::getNewLine();
}

void timedDynamicPass(Fibonacci fibo, int n)
{
	cout << "[Dynamic] Calculating the nth digit of Fibonacci sequence, where n = " << n << "..." << Prompter::getNewLine();

	auto start = chrono::high_resolution_clock::now();
	auto result(fibo.GetNthDigitDynamic(n));
	auto end = chrono::high_resolution_clock::now();

	chrono::duration<double> elapsed = end - start;
	cout << "\t[Dynamic] Result = " << result << " [time=" << elapsed.count() << " secs]" << Prompter::getNewLine();
}

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

			timedIterativePass(fibo, n);
			timedRecursivePass(fibo, n);
			timedDynamicPass(fibo, n);
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