#pragma once
#include "IShape.h"

const std::string coord1 = "Coordinates of the first point: ";
const std::string coord2 = "\nCoordinates of the second point: ";
const std::string len = "\nLength of the line segment: ";

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint firstCoordinate, CPoint secondCoordinate, std::string outlineColor)
	{
		firstPoint = firstCoordinate;
		secondPoint = secondCoordinate;
		CLineSegment::length = CalculateSideLength(firstPoint, secondPoint);
		CLineSegment::outlineColor = outlineColor;
	}
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;
	std::string GetName() const override;
	CPoint GetFirstPoint() const;
	CPoint GetSecondPoint() const;
private:
	double CalculateSideLength(CPoint firstPoint, CPoint secondPoint)
	{
		return (double(sqrt((firstPoint.x - secondPoint.x) * (firstPoint.x - secondPoint.x) + (firstPoint.y - secondPoint.y) * (firstPoint.y - secondPoint.y))));
	}
	std::string name = "Line segment";
	CPoint firstPoint;
	CPoint secondPoint;
	double length;
	std::string outlineColor;
};
