#include "pch.h"
#include "Executor.h"

using namespace std;

void Executor::Help()
{ //<< "" << endl
	cout << "help : print custom documentation"<<endl
		<< "myexit : exit the programm" << endl
		<< "clear : clears the console" << endl
		<< "wait : waits until you press any button" << endl;
}

void Executor::Exit()
{
	exit(0);
}

void Executor::Clear()
{	// Макрос обработки API ошибок
	#define PERR(bSuccess, api){if(!(Success)) printf("%s:Error %d from %s on line %d\n", __FILE__, GetLastError(), api, __LINE__);}

	BOOL Success; //сюда будем получать результат успешно ли выполнилась функция
	COORD topLeft = { 0, 0 }; // для наводкки курсора на начало
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // хендл нашей консоль
	CONSOLE_SCREEN_BUFFER_INFO screen;	//для получения информации о буфере
	DWORD written; //написанные данные в текущем буфере

	Success=GetConsoleScreenBufferInfo(console, &screen); // получение инфы о буфере
	PERR(Success, "GetConsoleScreenBufferInfo"); // успешно ли?
	Success=FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	PERR(bSuccess, "FillConsoleOutputCharacterA");
	Success=FillConsoleOutputAttribute( //заливаем консоль чёрным
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	PERR(Success, "FillConsoleOutputCharacter"); //успех?
	Success=SetConsoleCursorPosition(console, topLeft); //наводка курсора на начало
	PERR(Success, "SetConsoleCursorPosition"); //успех?
}

void Executor::Vivod()
{

}

void Executor::Wait()
{
	std::cout << "Press any key to continue" << std::endl;
	getch();
}
