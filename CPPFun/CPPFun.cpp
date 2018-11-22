// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>

#include "CPPFun.h"

// TODO: search for way to shorten this simple function definition
void Prompter::displayGreeting(string greeting)
{
	cout << greeting << getNewLine();
}

string Prompter::getNewLine()
{
	// NOTE: keep newLine variable in top scope for re-use
	string newLine;
	{
		// NOTE: we drop newLineCharStream to lower scope so it is cleared after usage
		ostringstream newLineCharStream;
		newLineCharStream << endl;
		newLine = newLineCharStream.str();
	}
	return newLine;
}

string Prompter::promptForString(string prompt, bool acceptsBlank)
{
	string userEntry;
	{
		cout << prompt << getNewLine();
		if (acceptsBlank) {
			// NOTE: can accept blank input
			getline(cin, userEntry);
		}
		else {
			// NOTE: will not return until a value is entered
			cin >> userEntry;
		}
	}
	return userEntry;
}

int main()
{
	Prompter prompter;
	// TODO: create and call a static method on Prompter
	// Prompter::displayGreeting("Hello!");
	// Prompter::getNewLine()
	prompter.displayGreeting("Hello!");
	auto userEntry(prompter.promptForString("Please enter a value and press [Enter]"));
	cout << "User entered: '" << userEntry << "'" << prompter.getNewLine();

	return 0;
}