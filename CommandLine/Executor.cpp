#include "pch.h"
#include "Executor.h"
#include <cstdlib>

using namespace std;

void Executor::Help()
{ //<< "" << endl
	cout << "help : print custom documentation"<<endl
		<< "myexit : exit the programm" << endl;
}

void Executor::Exit()
{
	exit(0);
}
/*
void Executor::Clear()
{
#define PERR(bSuccess, api){if(!(bSuccess)) printf("%s:Error %d from %s \ 
	on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);

}*/