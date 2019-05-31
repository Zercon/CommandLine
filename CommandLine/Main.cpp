#include "pch.h"
#include "Shell.h"

using namespace std;

int main()
{

	Shell shell;
	if (!shell.Run())
		cerr << "Run function's error" << endl;
		

	return 0;
}
