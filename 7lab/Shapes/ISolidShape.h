#pragma once
#include "IShape.h"
const std::string wordFill = "Fill color: ";
// Интерфейс для фигур с цветом заливки
class ISolidShape: public IShape
{
public:
	virtual std::string GetFillColor() const = 0;
protected:
	~ISolidShape() = default;
};

