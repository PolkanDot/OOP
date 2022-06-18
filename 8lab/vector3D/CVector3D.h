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
	// Конструирует нулевой вектор
	CVector3D()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	// Конструирует вектор с заданными координатами
	CVector3D(double x0, double y0, double z0)
	{
		x = x0;
		y = y0;
		z = z0;
	}

	// Возвращает длину вектора
	double GetLength() const;

	// Нормализует вектор (приводит его к единичной длине)
	void Normalize();

	// Бинарный оператор сложения векторов
	CVector3D operator +(CVector3D const& vector) const;

	// Бинарный оператор вычитания векторов
	CVector3D operator -(CVector3D const& vector) const;

	// Выполняют увеличение длины вектора на длину второго вектора
	CVector3D operator +=(CVector3D const& vector);

	// Выполняют уменьшение длины вектора на длину второго вектора
	CVector3D operator -=(CVector3D const& vector);

	// Умножает вектор на скаляр
	CVector3D operator *(double number) const;

	//Выполняет деление вектора на скаляр
	CVector3D operator /(double number) const;

	//Умножает существующий вектор на скаляр
	CVector3D operator *=(double number);

	//Делит существующий вектор на скаляр
	CVector3D operator /=(double number);

	//Выполняет проверку векторов на приблизительное равенство
	bool operator ==(CVector3D const& vector) const;

	//Выполняет проверку векторов на неравенство
	bool operator !=(CVector3D const& vector) const;

	// В данном случае данные можно сделать публичными
	double x = 0, y = 0, z = 0;
};

// Унарный плюс
CVector3D operator +(CVector3D const& vector);

// Унарный минус
CVector3D operator -(CVector3D const& vector);

//Умножает скаляр на вектор
CVector3D operator *(double number, CVector3D const& vector);

//Оператор вывода в выходной поток
void operator <<(std::ostream& outputStream, CVector3D const& vector);

//Оператор ввода из входного потока
void operator >>(std::istream& inputStream, CVector3D& vector);

//Вычисляет результат скалярного произведения двух трехмерных векторов
double DotProduct(CVector3D const& v1, CVector3D const& v2);

//Вычисляет результат векторного произведения двух трехмерных векторов
CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);

// Нормализует вектор (приводит его к единичной длине)
CVector3D Normalize(CVector3D const& v);