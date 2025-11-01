#include <iostream>
#include "WorkerManager.h"
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "boss.h"
using namespace std;
int main()
{
	WorkerManager wm;
	int choice = 0;
	while (1)
	{

		wm.ShowMenu();

		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			break; 
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			cout << "输入有误，请重新输入!" << endl;
			system("cls");
			break;
		}
	}


	return 0;
}