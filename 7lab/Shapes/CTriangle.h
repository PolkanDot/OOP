#pragma once
#include "ISolidShape.h"

const std::string firstCoord = "Coordinates of the first point: ";
const std::string secondCoord = "\nCoordinates of the second point: ";
const std::string thirdCoord = "\nCoordinates of the third point: ";

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, std::string outlineColor, std::string fillColor)
	{
		CTriangle::vertex1.x = vertex1.x;
		CTriangle::vertex1.y = vertex1.y;
		CTriangle::vertex2.x = vertex2.x;
		CTriangle::vertex2.y = vertex2.y;
		CTriangle::vertex3.x = vertex3.x;
		CTriangle::vertex3.y = vertex3.y;
		CTriangle::outlineColor = outlineColor;
		CTriangle::fillColor = fillColor;
		firstSideLength = CalculateSideLength(vertex1, vertex2);
		secondSideLength = CalculateSideLength(vertex1, vertex3);
		thirdSideLength = CalculateSideLength(vertex3, vertex2);
		halfPerimeter = (firstSideLength + secondSideLength + thirdSideLength) / 2;
	}
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetFillColor() const override;
	std::string GetName() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;
	
private:
	double CalculateSideLength(CPoint firstPoint, CPoint secondPoint)
	{
		return (double(sqrt((firstPoint.x - secondPoint.x) * (firstPoint.x - secondPoint.x) + (firstPoint.y - secondPoint.y) * (firstPoint.y - secondPoint.y))));
	}
	const std::string name = "Triangle";
	CPoint vertex1{0, 0};
	CPoint vertex2{0, 0};
	CPoint vertex3{0, 0};
	std::string  outlineColor;
	std::string  fillColor;
	double firstSideLength = 0;
	double secondSideLength = 0;
	double thirdSideLength = 0;
	double halfPerimeter = 0;
};