#include "pch.h"
#include "Shell.h"
#include "Commands.h"
#include "Executor.h"



using namespace std;

bool debug = false;

Shell::Shell()
{
	this->input = new char[4096];

}

Shell::~Shell()
{
	delete this->input;
}

queue<char*> Shell::Parse(char* input)
{
	char seps[] = " "; //чем разделяем
	char *token = NULL;
	char *next_token = NULL;
	queue<char*> tokens;

	// Establish string and get the first token:
	token = strtok_s(input, seps, &next_token);
	if (debug)
	{
		cout << "Tokens: " << token;
		//system("pause");
	}
	// While there are tokens in string
	while (token != NULL)
	{
		// Get next token:
		if (token != NULL)
		{
			tokens.push(token);
			token = strtok_s(NULL, seps, &next_token);
			if (debug && (token != NULL))
			{
				cout << " " << token;
				//system("pause");
			}
		}
	}
	if (debug) cout << endl;
	return tokens;
}

bool Shell::Run()
{
	cout << "Welcome to custom windows shell\n" << endl;
	Executor executor;
	executor.Help();

	char cod_simvola;

	while (true)
	{
		TCHAR* str = executor.CalculateDir();
		_tprintf(TEXT("%s>"), str);
		
		char* nextInput;
		string temp;
		getline(cin, temp);

		strcpy(this->input, temp.c_str());

		queue<char*> inputs = Parse(this->input);

		while (!inputs.empty())
		{
			nextInput = inputs.front();
			inputs.pop();

			switch (resolveCommand(nextInput))
			{
			case help:
			{
				executor.Help();
				break;
			}
			case currDir:
			{
				executor.CalculateDir();
				break;
			}
			case myexit:
			{
				executor.Exit();
				break;
			}
			case clear:
			{
				executor.Clear();
				executor.Help();
				break;
			}
			case wait:
			{
				executor.Wait();
				break;
			}
			case vivod:
			{
				while (!inputs.empty())
				{
					nextInput = inputs.front();
					inputs.pop();
					executor.Vivod(nextInput);
				}
				cout << endl;
				break;
			}
			case createDir:
			{
				executor.CreateDir();
				break;
			}
			case listing:
			{
				executor.Listing();
				break;
			}
			default:
			{
				cout << "unknown command" << endl;
			}
			}
		}
	}

	return true;
}
