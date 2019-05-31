#include "pch.h"
#include "History.h"

using namespace std;

History::History()
{

}

History::~History()
{

}

int History::Listen()
{
	while (true)
	{
		if (kbhit()) // слушатель нажатия на клаву
		{
			switch (cod_simvola = getch()) // ждёт нажатия на клаву без Enter после этого
			{
			case 72: //вверх
				cout << "Up" << endl;
				break;
			case 80: //вниз
				cout << "Down" << endl;
				break;
				/*case 75: //влево
					cout << "left" << endl;
					break;
				case 77: //вправо
					cout << "Right" << endl;
					break;*/
			}
		}
	}
}
