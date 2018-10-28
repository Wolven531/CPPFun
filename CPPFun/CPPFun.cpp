// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>

#include "CPPFun.h"

int main()
{
	auto newLine(getNewLine());
	displayGreeting("Hello!");
	auto userEntry(promptForString("Please enter a value and press [Enter]"));
	cout << "User entered: '" << userEntry << "'";

	return 0;
}

void displayGreeting(string greeting)
{
	cout << greeting << getNewLine();
}

string getNewLine()
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

string promptForString(string prompt)
{
	string userEntry;
	cout << prompt << getNewLine();
	{
		// NOTE: unsure of the difference here
		// TODO: Look up the difference
		//getline(cin, userEntry);
		cin >> userEntry;
	}
	return userEntry;
}
