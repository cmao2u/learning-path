#include "employee.h"
employee::employee(int id, string name, int deptid)//利用构造函数初始化数据
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = deptid;
}
void employee::ShowInfo()
{
	cout<<"职工编号:" << this->m_ID
		<< "\t职工姓名:" << this->m_Name
		<< "\t岗位:" << this->GetDeptName()
		<< "\t岗位职责:完成经理交给的任务" << endl;
}
string employee::GetDeptName()
{
	return string("员工");
}