#pragma once
#include <iostream>
#include "CPoint.h"
#include <string>

const std::string blank = " ";
const std::string newLn = "\n";

// Интерфейс фигур без цвета закраски
class IShape
{
public:
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual std::string GetOutlineColor() const = 0;
	virtual std::string GetName() const = 0;
};