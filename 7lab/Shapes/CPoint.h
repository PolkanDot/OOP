#pragma once
class CPoint
{
public:
	double x;
	double y;
	bool operator ==(const CPoint& other) const;
};