#include "pch.h"
#include "Shell.h"
#include "Commands.h"
#include "Executor.h"
#include <string.h>
#include <cstdio>

using namespace std;

bool debug = true;

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
	//tokens.push(token);
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
			token = strtok_s(NULL, seps, &next_token); //от строки отрезается только 1 элемент, как исправить?
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
	cout << "Welcome to custom windows shell\n" <<
			"                                 *made by Jerry Khoreshko*\n" << endl;
	Executor executor;
	executor.Help();

	while (true)
	{
		cout << ">"; 
		char* nextInput;
		//cin >> this->input; //считывает только до пробела
		
		//gets(input);
			//std::vector<double> vec;
		//queue<char*> inputs;

		string temp;
		getline(cin, temp);
		strcpy(this->input, temp.c_str());

		//cout << input; system("pause");

		//input = (char*)str;

		//double x;
	//while (((istream.peek()) != '\n') && (istream >> x))
		//{
		//	inputs.push(x);
		//}
		//cin.getline(commandChar, 50);
		queue<char*> inputs = Parse(this->input);

		while (!inputs.empty())
		{
			nextInput = inputs.back();
			inputs.pop();

			switch (resolveCommand(nextInput))
			{
			case help:
			{
				executor.Help();
				break;
			}
			case myexit:
			{
				executor.Exit();
				break;
			}
			case clear:
			{
				//executor.Clear();
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