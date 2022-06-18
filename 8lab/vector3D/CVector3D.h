#pragma once
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <float.h>
#include <string>
#include <cstdlib>
#include <string>

const std::string blankComma = ", ";
const std::string newLn = "\n";
const std::string divByZero = "Division by zero";
const std::string notNumber = "Not a number passed";

class CVector3D
{
public:
	// ������������ ������� ������
	CVector3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	// ������������ ������ � ��������� ������������
	CVector3D(double x0, double y0, double z0)
	{
		x = x0;
		y = y0;
		z = z0;
	}

	// ���������� ����� �������
	double GetLength() const;

	// ����������� ������ (�������� ��� � ��������� �����)
	void Normalize();

	// �������� �������� �������� ��������
	CVector3D operator +(CVector3D const& vector) const;

	// �������� �������� ��������� ��������
	CVector3D operator -(CVector3D const& vector) const;

	// ��������� ���������� ����� ������� �� ����� ������� �������
	CVector3D operator +=(CVector3D const& vector);

	// ��������� ���������� ����� ������� �� ����� ������� �������
	CVector3D operator -=(CVector3D const& vector);

	// �������� ������ �� ������
	CVector3D operator *(double number) const;

	//��������� ������� ������� �� ������
	CVector3D operator /(double number) const;

	//�������� ������������ ������ �� ������
	CVector3D operator *=(double number);

	//����� ������������ ������ �� ������
	CVector3D operator /=(double number);

	//��������� �������� �������� �� ��������������� ���������
	bool operator ==(CVector3D const& vector) const;

	//��������� �������� �������� �� �����������
	bool operator !=(CVector3D const& vector) const;

	// � ������ ������ ������ ����� ������� ����������
	double x = 0, y = 0, z = 0;
};

// ������� ����
CVector3D operator +(CVector3D const& vector);

// ������� �����
CVector3D operator -(CVector3D const& vector);

//�������� ������ �� ������
CVector3D operator *(double number, CVector3D const& vector);

//�������� ������ � �������� �����
void operator <<(std::ostream& outputStream, CVector3D const& vector);

//�������� ����� �� �������� ������
void operator >>(std::istream& inputStream, CVector3D& vector);

//��������� ��������� ���������� ������������ ���� ���������� ��������
double DotProduct(CVector3D const& v1, CVector3D const& v2);

//��������� ��������� ���������� ������������ ���� ���������� ��������
CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

// ����������� ������ (�������� ��� � ��������� �����)
CVector3D Normalize(CVector3D const& v);