#include "pch.h"
#include "Shell.h"

int main()
{
	Shell shell;
	if (!shell.Run())
		std::cerr << "Run function's error" << std::endl;
		
	return 0;
}
