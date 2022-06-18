#include "Controller.h"

const std::string intro = "Enter the names of the shapes and information about them in this format: \n"
"About the rectangle:\nrectangle <x coordinate of the upper left point> <y coordinate of the upper left point> "
"<width> <height> <stroke color> <fill color>\n"
"About triangle:\ntriangle <x1 coordinate> <y1 coordinate> <x2 coordinate> <y2 coordinate> <x3 coordinate> <y3 coordinate> "
"<stroke color> <fill color>\n"
"About the circle:\ncircle <x coordinate of the center> <y coordinate of the center> <radius length> "
"<stroke color> <fill color>\n"
"About the line segment:\nline segment <x1 coordinate> <y1 coordinate> <x2 coordinate> <y2 coordinate> <stroke color>\n"
"If you want to shut down, press Enter\n";
const std::string rectangleWord = "rectangle";
const std::string triangleWord = "triangle";
const std::string circleWord = "circle";
const std::string lineWord = "line";
const std::string segmentWord = "segment";
const std::string shapeWithMinPer = "Data about the shape with the smallest perimeter: \n";
const std::string shapeWithMaxAr = "Data about the figure with the largest area: \n";
const std::string areaWord = "Area: ";
const std::string perimeterWord = " Perimeter: ";
const std::string outlineWord = "Stroke color: ";
const std::string lSWord = "Line segment";

void Controller::Starting(istream& const inputStream, ostream& outputStream)
{
	std::string shapeInfo, shapeName;
	cout << intro;
	getline(inputStream, shapeInfo);
	while (!(shapeInfo == ""))
	{
		istringstream shape(shapeInfo);
		shape >> shapeName;
		std::string outColor, fillColor;

		if (shapeName == rectangleWord)
		{
			CPoint point;
			double width, height;
			if (shape >> point.x >> point.y >> width >> height >> outColor >> fillColor)
			{
				if (height < 0 || width < 0)
				{
					getline(inputStream, shapeInfo);
					continue;
				}
				shapes.push_back(make_shared<CRectangle>(point, width, height, outColor, fillColor));
			}
		}
		else if (shapeName == triangleWord)
		{
			CPoint pnt1, pnt2, pnt3;
			if (shape >> pnt1.x >> pnt1.y >> pnt2.x >> pnt2.y >> pnt3.x >> pnt3.y >> outColor >> fillColor)
			{
				shapes.push_back(make_shared<CTriangle>(pnt1, pnt2, pnt3, outColor, fillColor));
			}
		}
		else if (shapeName == circleWord)
		{
			CPoint pnt;
			double radiusLen = 0;
			if (shape >> pnt.x >> pnt.y >> radiusLen >> outColor >> fillColor)
			{
				if (radiusLen <= 0)
				{
					getline(inputStream, shapeInfo);
					continue;
				}
				shapes.push_back(make_shared<CCircle>(pnt, radiusLen, outColor, fillColor));
			}
		}
		else if (shapeName == lineWord)
		{
			CPoint pnt1, pnt2;
			shape >> shapeName;
			if (shapeName == segmentWord)
			{
				double len = 0;
				if (shape >> pnt1.x >> pnt1.y >> pnt2.x >> pnt2.y >> outColor)
				{
					shapes.push_back(make_shared<CLineSegment>(pnt1, pnt2, outColor));
				}
			}
		}
		getline(inputStream, shapeInfo);
	}
	if (!shapes.empty())
	{
		std::shared_ptr<IShape> minPerimeterShape, maxAreaShape;
		minPerimeterShape = FindMinPerimeterShape();
		maxAreaShape = FindMaxAreaShape();
		outputStream << shapeWithMinPer;
		GetInfo(outputStream, minPerimeterShape);
		outputStream << endl << shapeWithMaxAr;
		GetInfo(outputStream, maxAreaShape);
	}
}

std::shared_ptr<IShape> Controller::FindMinPerimeterShape() const
{
	auto minPerimeterShapePtr = std::min_element(shapes.begin(), shapes.end(),
		[](const std::shared_ptr<IShape>& shape1, const std::shared_ptr<IShape>& shape2) {
			return shape1->GetPerimeter() < shape2->GetPerimeter();
		});

	return *minPerimeterShapePtr;
}

std::shared_ptr<IShape> Controller::FindMaxAreaShape() const
{
	auto maxAreaShapePtr = std::max_element(shapes.begin(), shapes.end(),
		[](const std::shared_ptr<IShape>& shape1, const std::shared_ptr<IShape>& shape2) {
			return shape1->GetArea() < shape2->GetArea();
		});

	return *maxAreaShapePtr;
}

void Controller::GetInfo(ostream& outputStream, std::shared_ptr<IShape> figura) 
{
	outputStream << figura->GetName() << newLn << areaWord;
	outputStream << figura->GetArea() << perimeterWord << figura->GetPerimeter();
	outputStream << newLn << outlineWord << figura->GetOutlineColor() << newLn;
	if (!(figura->GetName() == lSWord))
	{
		ISolidShape& solid = dynamic_cast<ISolidShape&>(*figura);
		outputStream << wordFill << solid.GetFillColor() << newLn;
	}
	outputStream << figura->ToString() << newLn;
}