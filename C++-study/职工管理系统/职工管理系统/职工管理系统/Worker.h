#pragma once
#include <string>
#include <iostream>
using namespace std;
class worker
{
public:
	virtual void ShowInfo() = 0;
	virtual string GetDeptName() = 0;
	int m_ID;
	string m_Name;
	int m_DeptID;

};
