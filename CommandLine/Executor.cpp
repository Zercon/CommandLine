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
		<< "createDir : creates new directory in current directory" << endl
		<< "listing : displays brief information about files in current dirrectory" << endl
		<< "}" << endl;

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

void Executor::CreateDir()
{
	if (CreateDirectory(CalculateDir(), NULL))
		cout << "directory create" << endl;
	else
		cout << "error create directory" << endl;
}

void Executor::Listing()
{
	WIN32_FIND_DATA ffd;
	LARGE_INTEGER filesize;
	TCHAR szDir[MAX_PATH];
	size_t length_of_arg;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	DWORD dwError = 0;
	Executor executor;


	// Check that the input path plus 3 is not longer than MAX_PATH.
	// Three characters are for the "\*" plus NULL appended below.

	StringCchLength(executor.CalculateDir(), MAX_PATH, &length_of_arg);

	if (length_of_arg > (MAX_PATH - 3))
	{
		_tprintf(TEXT("\nDirectory path is too long.\n"));
		return;
	}

	_tprintf(TEXT("\nTarget directory is %s\n\n"), executor.CalculateDir());

	// Prepare string for use with FindFile functions.  First, copy the
	// string to a buffer, then append '\*' to the directory name.

	StringCchCopy(szDir, MAX_PATH, executor.CalculateDir());
	StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	// Find the first file in the directory.

	hFind = FindFirstFile(szDir, &ffd);

	// List all the files in the directory with some info about them.

	do
	{
		if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			_tprintf(TEXT("  %s   <DIR>\n"), ffd.cFileName);
		}
		else
		{
			filesize.LowPart = ffd.nFileSizeLow;
			filesize.HighPart = ffd.nFileSizeHigh;
			_tprintf(TEXT("  %s   %ld bytes\n"), ffd.cFileName, filesize.QuadPart);
		}
	} while (FindNextFile(hFind, &ffd) != 0);


	FindClose(hFind);
}