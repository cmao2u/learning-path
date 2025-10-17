#include "circle.h"
void circle::setR(int r)
{
	m_R = r;
}
int circle::getR()
{
	return m_R;
}	
void circle::setcenter(point center)
{
	m_Center = center;
}
point circle::getcenter()
{
	return m_Center;
}