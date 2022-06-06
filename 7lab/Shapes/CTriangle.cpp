#include "CTriangle.h"

double CTriangle::GetArea() const
{
	if (((vertex3.x - vertex1.x) * (vertex2.y - vertex1.y)) == ((vertex2.x - vertex1.x)*(vertex3.y - vertex1.y)))
	{
		return 0;
	}
	return (double(sqrt(halfPerimeter * (halfPerimeter - firstSideLength) *
		(halfPerimeter - secondSideLength) * (halfPerimeter - thirdSideLength))));
}
double CTriangle::GetPerimeter() const
{
	return (halfPerimeter * 2);
}
std::string CTriangle::ToString() const
{
		std::string info = firstCoord;
		info += std::to_string(vertex1.x);
		info += " ";
		info += std::to_string(vertex1.y);
		info += secondCoord;
		info += std::to_string(vertex2.x);
		info += " ";
		info += std::to_string(vertex2.y);
		info += thirdCoord;
		info += std::to_string(vertex3.x);
		info += " ";
		info += std::to_string(vertex3.y);
		return info;
}
std::string CTriangle::GetOutlineColor() const
{
	return (outlineColor);
}
std::string CTriangle::GetFillColor() const
{
	return (fillColor);
}
CPoint CTriangle::GetVertex1() const
{
	return vertex1;
}
CPoint CTriangle::GetVertex2() const
{
	return vertex2;
}
CPoint CTriangle::GetVertex3() const
{
	return vertex3;
}
std::string CTriangle::GetName() const
{
	return name;
}
