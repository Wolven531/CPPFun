#pragma once

#include <string>

using namespace std;

class Prompter {
public:
	Prompter();
	~Prompter();
	string getNewLine();
	void displayGreeting(string);
	string promptForString(string, bool = true);
};
