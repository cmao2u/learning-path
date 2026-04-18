#pragma once
#include <iostream>
#include "Worker.h"
#include "employee.h"
#include "Manager.h"
#include "boss.h"
#include <fstream>
#define FILENAME "empFile.txt"
using namespace std;
class WorkerManager
{
	public:
	WorkerManager();
	~WorkerManager();
	void ShowMenu();
	void ExitSystem();
	void AddEmp();
	int m_EmpNum;
	worker** m_EmpArray;
	void SaveFile();
	bool m_IsFileEmpty();
	void ShowEmp();
	void DelEmp();
	int IstExist(int id);
	void ModEmp();
	void FindEmp();
	void SortEmp();
	void CleanFile();

};

