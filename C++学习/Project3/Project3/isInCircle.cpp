#include "isInCircle.h"


void isInCircle(circle& c, point& p)
{
	int distance = (p.getX() - c.getcenter().getX())*(p.getX() - c.getcenter().getX()) +
		(p.getY() - c.getcenter().getY()) * (p.getY() - c.getcenter().getY());
	int r = c.getR() * c.getR();
	if(distance<r)
	{
		cout << "点在圆内" << endl;
	}
	else if(distance==r)
	{
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆外" << endl;
	}
}