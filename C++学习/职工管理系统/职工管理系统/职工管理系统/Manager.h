#pragma once
#include <string>
#include <iostream>
#include "Worker.h"
using namespace std;
class manager :public worker
{
public:
	manager(int id, string name, int deptid);
	void ShowInfo();
	string GetDeptName();

};
