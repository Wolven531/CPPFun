// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

string getNewLine()
{
	// NOTE: keep newLine variable in top scope for re-use
	string newLine;
	{
		// NOTE: we drop newLineCharStream to lower scope so it is cleared after usage
		ostringstream newLineCharStream;
		newLineCharStream << std::endl;
		newLine = newLineCharStream.str();
	}
	return newLine;
}

string promptForString(string prompt)
{
	string userEntry;
	cout << prompt << getNewLine();
	{
		getline(cin, userEntry);
	}
	return userEntry;
}

void displayGreeting(string greeting)
{
	cout << greeting << getNewLine();
}

int main()
{
	string newLine = getNewLine();
	displayGreeting("Hello!");
	string userEntry = promptForString("Please enter a value and press [Enter]");
	cout << "User entered: '" << userEntry << "'";

	return 0;
}
