#include "pch.h"
#include "Shell.h"

using namespace std;

int main()
{
	
	Shell shell;
	if (!shell.Run())
		std::cerr << "Run function's error" << std::endl;
		
	/*
		//string command;
	char *ptr;
	char **context;

	while (true)
	{
		char commandChar[1024]; // Will store the command entered by user in character array	
		char *argVector[10];    // Will store the arguments after they are tokenized	
		int argCount;       // Will store the number of arguments

		cout << "Shell$ ";
		cin.getline(commandChar, 50);
		ptr = strtok_s(commandChar, " ", context);
		argVector[argCount] = ptr;
		argCount++;

		while (ptr != NULL)

		{

			ptr = strtok(commandChar, " ");

			cout << ptr << " " << argCount << "\n";

			argVector[argCount] = ptr;

			argCount++;

			//execvp(argvec[0], argvec);

			//fatal("exec failed");

		}
		*/

	//char string1[] = "";
		/*char buffer[]="debug string feels so damn go                od";
		char seps[] = " ";
		char *token = NULL;
		char *next_token = NULL;

		cout << "Tokens:" << endl;

			// Establish string and get the first token:
			token = strtok_s(buffer, seps, &next_token);

			// While there are tokens in "string1" or "string2"
			while (token != NULL)
			{
				// Get next token:
				if (token != NULL)
				{
					cout <<" " << token << endl;
					token = strtok_s(NULL, seps, &next_token);
				}
			}
		
			system("pause");*/

	


	return 0;
}
