#include "WorkerManager.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	ifs.open(FILENAME, ios::in);
	if (ifs.eof())
	{

		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		return;
	}

}
WorkerManager::~WorkerManager()
{

}
void WorkerManager::ShowMenu()
{
	cout << "*****************************************" << endl;
	cout << "***********欢迎使用职工管理系统!*********" << endl;
	cout << "*************0.退出管理系统**************" << endl;
	cout << "*************1.增加职工信息**************" << endl;
	cout << "*************2.显示职工信息**************" << endl;
	cout << "*************3.删除离职职工**************" << endl;
	cout << "*************4.修改职工信息**************" << endl;
	cout << "*************5.查找职工信息**************" << endl;
	cout << "*************6.按照编号排序**************" << endl;
	cout << "*************7.清空所有文档**************" << endl;
	cout << "*****************************************" << endl;

}
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::AddEmp()
{
	cout << "增加职工数量" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		int NewSize = this->m_EmpNum + addNum;
		worker** newSpace = new worker * [NewSize];
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int ID;
			string name;
			int DeptSelect;

			cout << "请输入第 " << i + 1 << " 个新职工的编号:" << endl;
			cin >> ID;
			cout << "请输入第 " << i + 1 << " 个新职工的姓名:" << endl;
			cin >> name;
			cout << "请选择该职工的岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> DeptSelect;
			worker* worker = NULL;
			switch (DeptSelect)
			{
			case 1:
				worker = new employee(ID, name, 1);
				break;
			case 2:
				worker = new manager(ID, name, 2);
				break;
			case 3:
				worker = new boss(ID, name, 3);
				break;

			default:
				cout << "输入有误,默认设置为普通职工" << endl;
				worker = new employee(ID, name, 1);
				break;
			}
			newSpace[m_EmpNum + i] = worker;
		}/*修复说明：
		1.	原代码在每次循环内都执行了 delete[] this->m_EmpArray; 和 this->m_EmpArray = newSpace; ，导致后续循环时 newSpace 指针可能失效，且多次释放同一块内存，容易造成缓冲区溢出和内存错误。
			2.	修复后，将释放原有空间和赋值新空间的操作移到循环外部，只执行一次，确保 newSpace 指针始终有效，且不会越界写入。
			3.	这样 newSpace[m_EmpNum + i] 的写入不会超出分配的 NewSize 空间，缓冲区溢出问题得到解决。*/

		// 释放原有空间
		delete[] this->m_EmpArray;//
		this->m_EmpArray = newSpace;
		this->m_EmpNum = NewSize;
		this->SaveFile();
		cout << "成功添加 " << addNum << " 名新职工!" << endl;
	}
	else
	{
		cout << "输入有误!" << endl;
	}
	system("pause");
	system("cls");

}
void WorkerManager::SaveFile()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs<<this->m_EmpArray[i]->m_ID<<" "<<this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}
bool WorkerManager::m_IsFileEmpty()
{
    // 可以根据实际需求返回文件是否为空的状态
    // 例如：如果职工数量为0，则认为文件为空
    return this->m_EmpNum == 0;
}
void WorkerManager::ShowEmp()
{
	if (this->m_IsFileEmpty())
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::DelEmp()
{
	if (this->m_IsFileEmpty())
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "输入想要删除的职工编号:" << endl;	
		int id = 0;
		cin >> id;
		int index = this->IstExist(id);
		if (index != -1)
		{
			for (int i = index; i <this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->SaveFile();
			cout << "删除成功!" << endl;
		}
		else
		{
			cout << "删除失败,未找到该职工!" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IstExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_ID == id)
		{
			index = i;
				break;
		}

	}
	return index;
}
void WorkerManager::ModEmp()
{
	if (this->m_IsFileEmpty())
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入想要修改的职工编号:" << endl;
		int id = 0;
		cin >> id;
		int index = this->IstExist(id);
		if (index != -1)
		{
			delete this->m_EmpArray[index];
			int newID;
			string newName;
			int newDeptID;
			cout << "查到该职工,请输入新职工号:" << endl;
			cin >> newID;
			cout << "请输入新姓名:" << endl;
			cin >> newName;
			cout << "请输入岗位:" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> newDeptID;
			worker* worker = NULL;
			switch (newDeptID)
			{
			case 1:
				worker = new employee(newID, newName, 1);
				break;
			case 2:
				worker = new manager(newID, newName, 2);
				break;
			case 3:
				worker = new boss(newID, newName, 3);
				break;
			default:
				cout << "输入有误,默认设置为普通职工" << endl;
				worker = new employee(newID, newName, 1);
				break;
			}
			this->m_EmpArray[index] = worker;
			this->SaveFile();
			cout << "修改成功!" << endl;
		}
		else
		{
			cout << "修改失败,未找到该职工!" << endl;
		}
		system("pause");	
		system("cls");	
	}
}
void WorkerManager::FindEmp()
{
	if (this->m_IsFileEmpty())
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		cout << "请输入想要查找的职工编号或姓名:" << endl;
		string info;
		cin >> info;
		bool flag = false;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (to_string(this->m_EmpArray[i]->m_ID) == info || this->m_EmpArray[i]->m_Name == info)
			{
				this->m_EmpArray[i]->ShowInfo();
				flag = true;
			}
		}
		if (flag == false)
		{
			cout << "未找到该职工!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::SortEmp()
{
	cout << "我不会排序" << endl;
	cout << "排序功能待完善..." << endl;
	system("pause");
	system("cls");
}
void WorkerManager::CleanFile()
{
	cout << "确认清空?" << endl;
	cout << "1.确认" << endl;
	cout << "2.取消" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();//清空文件
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
		}//清空内存
		cout << "清空成功!" << endl;
	}
	else
	{
		cout << "取消清空!" << endl;
	}
	system("pause");
	system("cls");
}