#pragma once

#include <string>

using namespace std;

class Prompter {
public:
	static string getNewLine();
	Prompter();
	~Prompter();
	void displayGreeting(string);
	string promptForString(string, bool = true);
};
