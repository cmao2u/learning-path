#pragma once
#include "Worker.h"
#include <string>
using namespace std;
class boss :public worker
{
	public:
	boss(int id, string name, int deptid);
	void ShowInfo();
	string GetDeptName();
};