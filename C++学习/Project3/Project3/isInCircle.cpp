#include "isInCircle.h"


void isInCircle(circle& c, point& p)
{
	int distance = (p.getX() - c.getcenter().getX())*(p.getX() - c.getcenter().getX()) +
		(p.getY() - c.getcenter().getY()) * (p.getY() - c.getcenter().getY());
	int r = c.getR() * c.getR();
	if(distance<r)
	{
		cout << "����Բ��" << endl;
	}
	else if(distance==r)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}