#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Shapes/Controller.h"

SCENARIO("Checking the correctness of calculating the area of each figure")
{
	WHEN("Triangle")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 }, pnt3{ 3, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(round(triangle.GetArea()) == 2.0);
	}
	WHEN("Rectangle")
	{
		CPoint pnt1{ 1, 1 };
		double height = 10, width = 5;
		CRectangle rectangle(pnt1, width, height, "55rf55", "88gg88");
		CHECK(rectangle.GetArea() == 50);
	}
	WHEN("Circle")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 10;
		CCircle circle(pnt1, radius, "jjgj", "85jg99");
		CHECK(round(circle.GetArea()) == 314.0);
	}
	WHEN("Line segment")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 };
		CLineSegment lineSegment(pnt1, pnt2, "jgk45g");
		CHECK(lineSegment.GetArea() == 0);
		CHECK(lineSegment.GetPerimeter() == 2);
	}
}

SCENARIO("Checking the correctness of the perimeter of each figure")
{
	WHEN("Triangle")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 }, pnt3{ 3, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(round(triangle.GetPerimeter()) == 7.0);
	}
	WHEN("Triangle in line")
	{
		CPoint pnt1{ 0, 1 }, pnt2{ 0, 2 }, pnt3{ 0, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(round(triangle.GetPerimeter()) == 4.0);
	}
	WHEN("Rectangle")
	{
		CPoint pnt1{ 1, 1 };
		double height = 10, width = 5;
		CRectangle rectangle(pnt1, width, height, "55rf55", "88gg88");
		CHECK(rectangle.GetPerimeter() == 30.0);
	}
	WHEN("Rectangle in line")
	{
		CPoint pnt1{ 1, 1 };
		double height = 0, width = 5;
		CRectangle rectangle(pnt1, width, height, "55rf55", "88gg88");
		CHECK(rectangle.GetPerimeter() == 10.0);
	}
	WHEN("Circle")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 10;
		CCircle circle(pnt1, radius, "jjgj", "85jg99");
		CHECK(round(circle.GetPerimeter()) == 63.0);
	}
	WHEN("Circle in point")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 0;
		CCircle circle(pnt1, radius, "jjgj", "85jg99");
		CHECK(round(circle.GetPerimeter()) == 0.0);
	}
	WHEN("Line segment")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 };
		CLineSegment lineSegment(pnt1, pnt2, "jgk45g");
		CHECK(lineSegment.GetPerimeter() == 2.0);
	}
	WHEN("Line segment in point")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 1, 1 };
		CLineSegment lineSegment(pnt1, pnt2, "jgk45g");
		CHECK(lineSegment.GetPerimeter() == 0.0);
	}
}

SCENARIO("Checking the correctness of the transmitted stroke color")
{
	WHEN("Triangle")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 }, pnt3{ 3, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(triangle.GetOutlineColor() == "ff55ff");
	}
	WHEN("Rectangle")
	{
		CPoint pnt1{ 1, 1 };
		double height = 10, width = 5;
		CRectangle rectangle(pnt1, width, height, "ff55ff", "88gg88");
		CHECK(rectangle.GetOutlineColor() == "ff55ff");
	}
	WHEN("Circle")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 10;
		CCircle circle(pnt1, radius, "ff55ff", "85jg99");
		CHECK(circle.GetOutlineColor() == "ff55ff");
	}
	WHEN("Line segment")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 };
		CLineSegment lineSegment(pnt1, pnt2, "ff55ff");
		CHECK(lineSegment.GetOutlineColor() == "ff55ff");
	}
}

SCENARIO("Checking the correctness of the transmitted fill color")
{
	WHEN("Triangle")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 }, pnt3{ 3, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(triangle.GetFillColor() == "55ff55");
	}
	WHEN("Rectangle")
	{
		CPoint pnt1{ 1, 1 };
		double height = 10, width = 5;
		CRectangle rectangle(pnt1, width, height, "ff55ff", "55ff55");
		CHECK(rectangle.GetFillColor() == "55ff55");
	}
	WHEN("Circle")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 10;
		CCircle circle(pnt1, radius, "ff55ff", "55ff55");
		CHECK(circle.GetFillColor() == "55ff55");
	}
}

SCENARIO("Checking the correctness of the shape name")
{
	WHEN("Triangle")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 }, pnt3{ 3, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(triangle.GetName() == "Triangle");
	}
	WHEN("Rectangle")
	{
		CPoint pnt1{ 1, 1 };
		double height = 10, width = 5;
		CRectangle rectangle(pnt1, width, height, "ff55ff", "55ff55");
		CHECK(rectangle.GetName() == "Rectangle");
	}
	WHEN("Circle")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 10;
		CCircle circle(pnt1, radius, "ff55ff", "55ff55");
		CHECK(circle.GetName() == "Circle");
	}
	WHEN("Line segment")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 };
		CLineSegment lineSegment(pnt1, pnt2, "ff55ff");
		CHECK(lineSegment.GetName() == "Line segment");
	}
}

SCENARIO("Checking data specific to a particular shape")
{
	WHEN("Triangle")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 }, pnt3{ 3, 3 };
		CTriangle triangle(pnt1, pnt2, pnt3, "ff55ff", "55ff55");
		CHECK(triangle.ToString() == "Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 3.000000 1.000000\n"
			"Coordinates of the third point: 3.000000 3.000000");
	}
	WHEN("Rectangle")
	{
		CPoint pnt1{ 1, 1 };
		double height = 10, width = 5;
		CRectangle rectangle(pnt1, width, height, "ff55ff", "55ff55");
		CHECK(rectangle.ToString() == "Coordinates of the upper left point: 1.000000 1.000000\n"
			"Rectangle width: 5.000000\n"
			"Rectangle height: 10.000000");
	}
	WHEN("Circle")
	{
		CPoint pnt1{ 1, 1 };
		double radius = 10;
		CCircle circle(pnt1, radius, "ff55ff", "55ff55");
		CHECK(circle.ToString() == "Circle radius: 10.000000\n"
			"Coordinates of the center of the circle: 1.000000 1.000000");
	}
	WHEN("Line segment")
	{
		CPoint pnt1{ 1, 1 }, pnt2{ 3, 1 };
		CLineSegment lineSegment(pnt1, pnt2, "ff55ff");
		CHECK(lineSegment.ToString() == "Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 3.000000 1.000000\n"
			"Length of the line segment: 2.000000");
	}
}

SCENARIO("We do not transmit information about figures")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Controller controller;
	ostringstream result;
	WHEN("Passing an empty string")
	{
		istringstream inputCommands{ "" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "");
	}
}

SCENARIO("Passing one shape")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Controller controller;
	ostringstream result;
	WHEN("Figure - triangle")
	{
		istringstream inputCommands{ "triangle 1 1 4 1 5 5 ff0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "Data about the shape with the smallest perimeter: \n"
			"Triangle\n"
			"Area: 6 Perimeter: 12.78\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 4.000000 1.000000\n"
			"Coordinates of the third point: 5.000000 5.000000\n\n"
			"Data about the figure with the largest area: \n"
			"Triangle\n"
			"Area: 6 Perimeter: 12.78\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 4.000000 1.000000\n"
			"Coordinates of the third point: 5.000000 5.000000\n");
	}
	WHEN("Figure - rectangle")
	{
		istringstream inputCommands{ "rectangle 1 1 4 1 ff0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "Data about the shape with the smallest perimeter: \n"
			"Rectangle\n"
			"Area: 4 Perimeter: 10\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Coordinates of the upper left point: 1.000000 1.000000\n"
			"Rectangle width: 4.000000\n"
			"Rectangle height: 1.000000\n\n"

			"Data about the figure with the largest area: \n"
			"Rectangle\n"
			"Area: 4 Perimeter: 10\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Coordinates of the upper left point: 1.000000 1.000000\n"
			"Rectangle width: 4.000000\n"
			"Rectangle height: 1.000000\n");
	}
	WHEN("Figure - circle")
	{
		istringstream inputCommands{ "circle 1 1 4 ff0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "Data about the shape with the smallest perimeter: \n"
			"Circle\n"
			"Area: 50.24 Perimeter: 25.12\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Circle radius: 4.000000\n"
			"Coordinates of the center of the circle: 1.000000 1.000000\n\n"
			"Data about the figure with the largest area: \n"
			"Circle\n"
			"Area: 50.24 Perimeter: 25.12\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Circle radius: 4.000000\n"
			"Coordinates of the center of the circle: 1.000000 1.000000\n");
	}
	WHEN("Figure - line segment")
	{
		istringstream inputCommands{ "line segment 1 1 4 1 ff0000\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "Data about the shape with the smallest perimeter: \n"
			"Line segment\n"
			"Area: 0 Perimeter: 3\n"
			"Stroke color: ff0000\n"
			"Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 4.000000 1.000000\n"
			"Length of the line segment: 3.000000\n\n"
			"Data about the figure with the largest area: \n"
			"Line segment\n"
			"Area: 0 Perimeter: 3\n"
			"Stroke color: ff0000\n"
			"Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 4.000000 1.000000\n"
			"Length of the line segment: 3.000000\n");
	}
}

SCENARIO("We transmit information about several figures")
{
	Controller controller;
	ostringstream result;
	WHEN("Figure of different types")
	{
		istringstream inputCommands{ "triangle 1 1 4 1 5 5 ff0000 55ff55\nrectangle 1 1 4 1 ff0000 55ff55\n"
			"circle 1 1 4 ff0000 55ff55\nline segment 1 1 4 1 ff0000\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "Data about the shape with the smallest perimeter: \n"
			"Line segment\n"
			"Area: 0 Perimeter: 3\n"
			"Stroke color: ff0000\n"
			"Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 4.000000 1.000000\n"
			"Length of the line segment: 3.000000\n\n"
			"Data about the figure with the largest area: \n"
			"Circle\n"
			"Area: 50.24 Perimeter: 25.12\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Circle radius: 4.000000\n"
			"Coordinates of the center of the circle: 1.000000 1.000000\n");
	}
	WHEN("Single type figures")
	{
		istringstream inputCommands{ "triangle 1 1 4 1 5 5 ff0000 55ff55\ntriangle 2 2 5 5 9 1 ff00ff 55ff55\n"
			"triangle -3 -4 1 1 5 -5 ff0000 55ff55\ntriangle -1000 -1000 -1040 -1040 -1000 -1040 gg0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "Data about the shape with the smallest perimeter: \n"
			"Triangle\n"
			"Area: 6 Perimeter: 12.78\n"
			"Stroke color: ff0000\n"
			"Fill color: 55ff55\n"
			"Coordinates of the first point: 1.000000 1.000000\n"
			"Coordinates of the second point: 4.000000 1.000000\n"
			"Coordinates of the third point: 5.000000 5.000000\n\n"
			"Data about the figure with the largest area: \n"
			"Triangle\n"
			"Area: 800 Perimeter: 136.569\n"
			"Stroke color: gg0000\n"
			"Fill color: 55ff55\n"
			"Coordinates of the first point: -1000.000000 -1000.000000\n"
			"Coordinates of the second point: -1040.000000 -1040.000000\n"
			"Coordinates of the third point: -1000.000000 -1040.000000\n");
	}
}

SCENARIO("Transmitting incorrect data about the rectangle")
{
	Controller controller;
	ostringstream result;
	WHEN("Negative height")
	{
		istringstream inputCommands{ "rectangle 1 1 -4 1 ff0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "");
	}
	WHEN("Negative width")
	{
		istringstream inputCommands{ "rectangle 1 1 14 -1 ff0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "");
	}
}

SCENARIO("We transmit incorrect data about the circle")
{
	Controller controller;
	ostringstream result;
	WHEN("Negative radius")
	{
		istringstream inputCommands{ "circle 1 1 -4 ff0000 55ff55\n" };
		controller.Starting(inputCommands, result);
		CHECK(result.str() == "");
	}
}