#include "CRectangle.h"

double CRectangle::GetArea() const
{
	return width * height;
}
double CRectangle::GetPerimeter() const
{
	return 2 * (width + height);
}
std::string CRectangle::ToString() const
{
	std::string info = coord;
	info += std::to_string(leftTopVertex.x);
	info += blank;
	info += std::to_string(leftTopVertex.y);
	info += newLn;
	info += widthRect;
	info += std::to_string(width);
	info += newLn;
	info += heightRect;
	info += std::to_string(height);
	return info;
}
std::string CRectangle::GetOutlineColor()  const
{
	return outlineColor;
}
std::string CRectangle::GetFillColor()  const
{
	return fillColor;
}
std::string CRectangle::GetName() const
{
	return name;
}