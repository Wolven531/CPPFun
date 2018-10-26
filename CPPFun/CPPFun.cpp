// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	// NOTE: keep newLine variable in top scope for re-use
	string newLine;
	{
		// NOTE: we drop newLineCharStream to lower scope so it is cleared after usage
		ostringstream newLineCharStream;
		newLineCharStream << std::endl;
		newLine = newLineCharStream.str();
	}

	{
		string greeting = "Hello!";
		string prompt = "Please enter a value and press [Enter]";

		cout << greeting << newLine << prompt << newLine;
	}

	{
		string userEntry;
		getline(cin, userEntry);
		cout << "User entered: '" << userEntry << "'\n";
	}

	return 0;
}