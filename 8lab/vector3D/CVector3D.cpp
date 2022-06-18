#include "CVector3D.h"

// Возвращает длину вектора
double CVector3D::GetLength() const
{
	return (sqrt(x * x + y * y + z * z));
}

// Нормализует вектор (приводит его к единичной длине)
void CVector3D::Normalize()
{
	double len = GetLength();
	if (len == 0)
	{
		return;
	}
	x /= len;
	y /= len;
	z /= len;
}

// Унарный минус (разворачивает вектор)
CVector3D operator -(CVector3D const& vector)
{
	return CVector3D(-vector.x, -vector.y, -vector.z);
}

// Унарный плюс (для полноты)
CVector3D operator +(CVector3D const& vector)
{
	return vector;
}

// Бинарный оператор сложения векторов
CVector3D CVector3D::operator +(CVector3D const& vector) const
{
	return CVector3D(x + vector.x, y + vector.y, z + vector.z);
}

// Бинарный оператор вычитания векторов
CVector3D CVector3D::operator -(CVector3D const& vector) const
{
	return CVector3D(x - vector.x, y - vector.y, z - vector.z);
}

// Выполняют увеличение длины вектора на длину второго вектора
CVector3D CVector3D::operator +=(CVector3D const& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

// Выполняют уменьшение длины вектора на длину второго вектора
CVector3D  CVector3D::operator -=(CVector3D const& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

// Умножает вектор на скаляр
CVector3D CVector3D::operator *(double number) const
{
	return CVector3D(x * number, y * number, z * number);
}

//Умножает скаляр на вектор
CVector3D operator *(double number, CVector3D const& vector)
{
	return vector * number;
}

//Выполняет деление вектора на скаляр
CVector3D CVector3D::operator /(double number) const
{
	CVector3D newVector(0, 0, 0);
	if (number == 0)
	{
		throw std::invalid_argument(divByZero);
	}
	newVector.x = x / number;
	newVector.y = y / number;
	newVector.z = z / number;
	return newVector;
}

//Умножает существующий вектор на скаляр
CVector3D CVector3D::operator *=(double number)
{
	x *= number;
	y *= number;
	z *= number;
	return *this;
}

//Делит существующий вектор на скаляр
CVector3D CVector3D::operator /=(double number)
{
	if (number == 0)
	{
		throw std::invalid_argument(divByZero);
	}
	x = x / number;
	y = y / number;
	z = z / number;
	return *this;
}

//Выполняет проверку векторов на приблизительное равенство
bool CVector3D::operator ==(CVector3D const& vector) const
{
	return (std::abs(x - vector.x) <= DBL_EPSILON)
		&& (std::abs(y - vector.y) <= DBL_EPSILON)
		&& (std::abs(z - vector.z) <= DBL_EPSILON);
}

//Выполняет проверку векторов на неравенство
bool CVector3D::operator !=(CVector3D const& vector) const
{
	return (!(*this == vector));
}

//Оператор вывода в выходной поток
void operator <<(std::ostream& outputStream, CVector3D const& vector)
{
	outputStream << std::to_string(vector.x) <<
    blankComma << std::to_string(vector.y) <<
	blankComma << std::to_string(vector.z) << newLn;
}

//Оператор ввода из входного потока
void operator >>(std::istream& inputStream, CVector3D& vector)
{
	double x, y, z;

	if ((inputStream >> x) && (inputStream.get() == ',') &&
		(inputStream >> y) && (inputStream.get() == ',') &&
		(inputStream >> z))
	{
		vector = CVector3D(x, y, z);
	}
	else
	{
		throw std::invalid_argument(notNumber);
	}

}

//Вычисляет результат скалярного произведения двух трехмерных векторов
double DotProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	return (vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z);
}

//Вычисляет результат векторного произведения двух трехмерных векторов
CVector3D CrossProduct(CVector3D const& vector1, CVector3D const& vector2)
{
	double x = vector1.y * vector2.z - vector1.z * vector2.y;
	double y = vector1.x * vector2.z - vector1.z * vector2.x;
	double z = vector1.x * vector2.y - vector1.y * vector2.x;
	return CVector3D(x, y, z);
}

// Нормализует вектор (приводит его к единичной длине)
CVector3D Normalize(CVector3D const& v)
{
	CVector3D newVector(v.x, v.y, v.z);
	double len = newVector.GetLength();
	if (len > 0)
	{
		newVector.x /= len;
		newVector.y /= len;
		newVector.z /= len;
	}	
	return newVector;
}