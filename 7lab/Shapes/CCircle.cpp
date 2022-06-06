#include "CCircle.h";

double CCircle::GetArea()  const
{
	return 3.14 * radius * radius;
}
double CCircle::GetPerimeter() const
{
	return 2 * 3.14 * radius;
}
std::string CCircle::ToString() const
{
	std::string info = radiusCircle;
	info += std::to_string(radius);
	info += newLn;
	info += centerCircle;
	info += std::to_string(center.x);
	info += blank;
	info += std::to_string(center.y);
	return info;
}
std::string CCircle::GetOutlineColor() const
{
	return outlineColor;
}
std::string CCircle::GetFillColor() const
{
	return fillColor;
}
std::string CCircle::GetName() const
{
	return name;
}
