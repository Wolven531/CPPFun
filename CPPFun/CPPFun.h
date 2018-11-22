#pragma once

#include <string>

using namespace std;

class Prompter {
	public:
		string getNewLine();
		void displayGreeting(string);
		string promptForString(string, bool = true);
};
