#include "CLineSegment.h"

double CLineSegment::GetArea() const
{
	return 0;
}
double CLineSegment::GetPerimeter() const
{
	return length;
}
std::string CLineSegment::ToString() const
{
	std::string info = coord1;
	info += std::to_string(firstPoint.x);
	info += " ";
	info += std::to_string(firstPoint.y);
	info += coord2;
	info += std::to_string(secondPoint.x);
	info += " ";
	info += std::to_string(secondPoint.y);
	info += len;
	info += std::to_string(length);
	return info;
}
std::string CLineSegment::GetOutlineColor() const
{
	return outlineColor;
}
std::string CLineSegment::GetName() const
{
	return name;
}

CPoint CLineSegment::GetFirstPoint() const
{
	return firstPoint;
}
CPoint CLineSegment::GetSecondPoint() const
{
	return secondPoint;
}