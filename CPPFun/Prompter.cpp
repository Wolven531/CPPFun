#include "pch.h"
#include "Prompter.h"

#include <iostream>
#include <sstream>

Prompter::Prompter()
{
}

// TODO: search for way to shorten this simple function definition
void Prompter::displayGreeting(string greeting)
{
	cout << greeting << this->getNewLine();
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
		cout << prompt << this->getNewLine();
		cout << "$> ";

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

Prompter::~Prompter()
{
}
