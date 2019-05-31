#pragma once

enum Commands
{
	unknown_command,
	help,
	myexit,
	clear,
	wait,
	vivod,
	currDir,
	createDir,
	listing

};

Commands resolveCommand(std::string input) 
{
	static const std::map<std::string, Commands> commandStrings
	{
		{ "help", help },
		{ "myexit", myexit},
		{ "clear", clear},
		{"wait", wait},
		{"vivod", vivod},
		{"currDir", currDir},
	{"createDir", createDir},
	{"listing", listing}
	};

	auto itr = commandStrings.find(input);
	if (itr != commandStrings.end()) 
	{
		return itr->second;
	}
	return unknown_command;
}