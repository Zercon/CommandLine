#pragma once

#include "pch.h"
#include <string>
#include <map>

enum Commands
{
	unknown_command,
	help,
	myexit,
	clear,

};

Commands resolveCommand(std::string input) 
{
	static const std::map<std::string, Commands> commandStrings{
		{ "help", help },
		{ "myexit", myexit},
	{"clear", clear},
	};

	auto itr = commandStrings.find(input);
	if (itr != commandStrings.end()) {
		return itr->second;
	}
	return unknown_command;
}