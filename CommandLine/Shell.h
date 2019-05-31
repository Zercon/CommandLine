#pragma once

class Shell
{
public:
	Shell();
	~Shell();

	std::queue<char*> Parse(char* input);
	bool Run();
	bool History();

	std::vector<std::string> history;
	char* input;
};