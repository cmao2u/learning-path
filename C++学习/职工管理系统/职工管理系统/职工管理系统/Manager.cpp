#include "Manager.h"
#include <iostream>
using namespace std;
manager::manager(int id, string name, int deptid)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
}
void manager::ShowInfo()
{
	cout << "职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->GetDeptName()
		<< "\t岗位职责:完成老板交给的任务,并下发任务给员工" << endl;
}
string manager::GetDeptName()
{
return string("经理");
}