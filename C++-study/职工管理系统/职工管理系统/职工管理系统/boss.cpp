#include "boss.h"
#include <iostream>
using namespace std;
boss::boss(int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
}
void boss::ShowInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->GetDeptName()
		<< "\t岗位职责:管理公司所有事务" << endl;
}
string boss::GetDeptName()
{
	return string("总裁");
}