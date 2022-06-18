#pragma once
#include <iostream>
#include <sstream>
#include "CLineSegment.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <vector>
#include <algorithm>

using namespace std;

class Controller
{
public:
	void Starting(istream& inputStream, ostream& outputStream);
private:
	void GetInfo(ostream& outputStream, shared_ptr<IShape> figura);
	shared_ptr<IShape> FindMinPerimeterShape() const;
	shared_ptr<IShape> FindMaxAreaShape() const;
	vector<shared_ptr<IShape>> shapes;
};

