#pragma once
#include "ISolidShape.h"

const std::string coord = "Coordinates of the upper left point: ";
const std::string heightRect = "Rectangle height: ";
const std::string widthRect = "Rectangle width: ";

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTopVertex, double width, double height, std::string outlineColor, std::string fillColor)
	{
		CRectangle::leftTopVertex = leftTopVertex;
		CRectangle::width = width;
		CRectangle::height = height;
		CRectangle::outlineColor = outlineColor;
		CRectangle::fillColor = fillColor;
	}
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	std::string GetName() const override;
private:
	std::string name = "Rectangle";
	CPoint leftTopVertex;
	double width;
	double height;
	std::string outlineColor;
	std::string fillColor;
};