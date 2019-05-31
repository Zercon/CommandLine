#pragma once
#include <Windows.h>

class Shell
{
public:
	Shell();
	~Shell();

	std::queue<char*> Parse(char* input);
	bool Run();

	

	

	char* input;
};