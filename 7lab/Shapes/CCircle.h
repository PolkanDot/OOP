#pragma once
#include "ISolidShape.h";

const std::string radiusCircle = "Circle radius: ";
const std::string centerCircle = "Coordinates of the center of the circle: ";

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint center, double radius, std::string outlineColor, std::string fillColor)
	{
		CCircle::center = center;
		CCircle::radius = radius;
		CCircle::outlineColor = outlineColor;
		CCircle::fillColor = fillColor;
	};
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	std::string GetName() const override;
private:
	std::string name = "Circle";
	CPoint center;
	double radius;
	std::string outlineColor;
	std::string fillColor;
};