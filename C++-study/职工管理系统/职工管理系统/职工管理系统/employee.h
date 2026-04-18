#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;
class employee :public worker
{
public:
	employee(int id,string name,int deptid);
	void ShowInfo();
	string GetDeptName();

};
