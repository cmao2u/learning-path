/*写者的话：
本文件尚未完成，很多只是初步尝试
利用类和对象封装多个函数初步尝试
仅作锻炼
后续会完善内容
至此，c++已经学习40天
等到继续精进c++时，再回来完善这个文件
2025年11月2日
*/
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
			wm.AddEmp();
			break; 
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.DelEmp();
			break;
		case 4:
			wm.ModEmp();
			break;
		case 5:
			wm.FindEmp();
			break;
		case 6:
			wm.SortEmp();
			break;
		case 7:
			wm.CleanFile();
			break;
		default:
			cout << "输入有误，请重新输入!" << endl;
			system("cls");
			break;
		}
	}


	return 0;
}