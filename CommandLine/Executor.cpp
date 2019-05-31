#include "pch.h"
#include "Executor.h"

using namespace std;

void Executor::Help()
{ //<< "" << endl
	cout << "{" << endl
		<< "help : print custom documentation" << endl
		<< "myexit : exit the programm" << endl
		<< "clear : clears the console" << endl
		<< "wait : waits until you press any button" << endl
		<< "vivod : displays all the following words" << endl
		<< "currDir : displays current directory" << endl
		<< "}" << endl;

}

void Executor::Exit()
{
	exit(0);
}

void Executor::Clear()
{	// ������ ��������� API ������
	#define PERR(bSuccess, api){if(!(Success)) printf("%s:Error %d from %s on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

	BOOL Success; //���� ����� �������� ��������� ������� �� ����������� �������
	COORD topLeft = { 0, 0 }; // ��� �������� ������� �� ������
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // ����� ����� �������
	CONSOLE_SCREEN_BUFFER_INFO screen;	//��� ��������� ���������� � ������
	DWORD written; //���������� ������ � ������� ������

	Success=GetConsoleScreenBufferInfo(console, &screen); // ��������� ���� � ������
	PERR(Success, "GetConsoleScreenBufferInfo"); // ������� ��?
	Success=FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	PERR(bSuccess, "FillConsoleOutputCharacterA");
	Success=FillConsoleOutputAttribute( //�������� ������� ������
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	PERR(Success, "FillConsoleOutputCharacter"); //�����?
	Success=SetConsoleCursorPosition(console, topLeft); //������� ������� �� ������
	PERR(Success, "SetConsoleCursorPosition"); //�����?
}

void Executor::Vivod(char* forPrint)
{
	cout << forPrint << " ";
}


void Executor::Wait()
{
	std::cout << "Press any key to continue" << std::endl;
	getch();
}

TCHAR* Executor::CalculateDir()
{
	TCHAR* NPath = new TCHAR[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, NPath);
	return NPath;
}
