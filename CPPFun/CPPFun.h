#pragma once

#include <string>

using namespace std;

class Prompter {
	public:
		string getNewLine();
		void displayGreeting(string greeting);
		string promptForString(string prompt, bool acceptsBlank = true);
};
