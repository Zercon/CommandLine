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
		if (kbhit()) // ��������� ������� �� �����
		{
			switch (cod_simvola = getch()) // ��� ������� �� ����� ��� Enter ����� �����
			{
			case 72: //�����
				cout << "Up" << endl;
				break;
			case 80: //����
				cout << "Down" << endl;
				break;
				/*case 75: //�����
					cout << "left" << endl;
					break;
				case 77: //������
					cout << "Right" << endl;
					break;*/
			}
		}
	}
}
