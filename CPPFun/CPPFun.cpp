// CPPFun.cpp : This file contains the 'main' function. Program execution begins and ends there

#include "pch.h"

#include <iostream>
#include <sstream>

#include "CPPFun.h"
#include "Prompter.h"

int main()
{
	Prompter prompter;
	// TODO: create and call a static method on Prompter
	// Prompter::displayGreeting("Hello!");
	// Prompter::getNewLine()
	prompter.displayGreeting("Hello!");
	auto userEntry(prompter.promptForString("Please enter a value and press [Enter]", false));
	cout << "User entered: '" << userEntry << "'" << prompter.getNewLine();

	return 0;
}