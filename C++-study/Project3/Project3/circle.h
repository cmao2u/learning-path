#pragma once
#include <iostream>
#include"point.h"
using namespace std;
class circle
{
private:
	int m_R;
	point m_Center;
public:
	void setR(int r);
	int getR();
	void setcenter(point center);
	point getcenter();
};