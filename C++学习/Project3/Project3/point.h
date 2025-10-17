#pragma once
#include <iostream>
using namespace std;

class point
{
public:
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();	
private:	
	int m_X;
	int m_Y;

};

