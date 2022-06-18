#include "CPoint.h"
// Переопределяем оператор == для класса CPoint (для удобства определения равенства)
bool CPoint::operator==(const CPoint& other) const
{
	return (this->x == other.x) && (this->y == other.y);
}