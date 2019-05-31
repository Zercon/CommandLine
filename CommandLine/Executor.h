#pragma once



class Executor
{
public:
	Executor() {};
	~Executor() {};
	
	void Help();
	void Exit();
	void Clear();
	void Vivod(char* forPrint);
	void Wait();
	TCHAR* CalculateDir();
	void CreateDir();
	void Listing();


private:


};