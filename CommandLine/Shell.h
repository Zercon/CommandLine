#pragma once
#include "pch.h"

class Shell
{
public:
	Shell();
	~Shell();

	std::queue<char*> Parse(char* input);
	bool Run();

	char* input;
};