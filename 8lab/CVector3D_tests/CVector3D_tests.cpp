#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Vector3D/CVector3D.h"
#include <sstream>
#include <Windows.h>

SCENARIO("Создём экземпляр вектора")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WHEN("Без параметров")
	{
		CVector3D vector;
		THEN("Координаты вектора нулевые")
		{
			CHECK(vector.x == 0);
			CHECK(vector.y == 0);
			CHECK(vector.z == 0);
		}
	}
	WHEN("С параметрами")
	{
		CVector3D vector(2, 1, 9);
		THEN("Координаты вектора корректны")
		{
			CHECK(vector.x == 2);
			CHECK(vector.y == 1);
			CHECK(vector.z == 9);
		}
	}
}

SCENARIO("Получаем длину вектора")
{
	WHEN("Ненулевой вектор с положительными координатами")
	{
		CVector3D vector(3, 7, 2);
		double len = vector.GetLength();
		CHECK(round(len * 100) / 100 == 7.87);
	}
	WHEN("Ненулевой вектор сотрицательными координатами")
	{
		CVector3D vector(-3, -7, -2);
		double len = vector.GetLength();
		CHECK(round(len * 100) / 100 == 7.87);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D vector;
		double len = vector.GetLength();
		CHECK(len == 0);
	}
}

SCENARIO("Нормализуем вектор методом класса")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WHEN("Ненулевой вектор")
	{
		CVector3D vector(3, 7, 2);
		vector.Normalize();
		CHECK(round(vector.x * 100) / 100 == 0.38);
		CHECK(round(vector.y * 100) / 100 == 0.89);
		CHECK(round(vector.z * 100) / 100 == 0.25);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D vector;
		vector.Normalize();
		CHECK(vector.x == 0);
		CHECK(vector.y == 0);
		CHECK(vector.z == 0);
	}
}

SCENARIO("Нормализуем вектор свободной функцией")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WHEN("Ненулевой вектор")
	{
		CVector3D vector(3, 7, 2);
		CVector3D normalizedVector = Normalize(vector);
		CHECK(round(normalizedVector.x * 100) / 100 == 0.38);
		CHECK(round(normalizedVector.y * 100) / 100 == 0.89);
		CHECK(round(normalizedVector.z * 100) / 100 == 0.25);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D vector;
		CVector3D normalizedVector = Normalize(vector);
		CHECK(normalizedVector.x == 0);
		CHECK(normalizedVector.y == 0);
		CHECK(normalizedVector.z == 0);
	}
}

SCENARIO("Проверяем унарный оператор +")
{
	WHEN("Ненулевой вектор")
	{
		CVector3D vector(3, 7, 2);
		CVector3D changedVector = +vector;
		CHECK(changedVector.x == 3);
		CHECK(changedVector.y == 7);
		CHECK(changedVector.z == 2);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D vector;
		CVector3D changedVector = +vector;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем унарный оператор -")
{
	WHEN("Ненулевой вектор")
	{
		CVector3D vector(3, 7, 2);
		CVector3D changedVector = -vector;
		CHECK(changedVector.x == -3);
		CHECK(changedVector.y == -7);
		CHECK(changedVector.z == -2);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D vector;
		CVector3D changedVector = -vector;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем бинарный оператор +")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(3, 7, 2);
		CVector3D secondVector(2, -1, 4);
		CVector3D changedVector = firstVector + secondVector;
		CHECK(changedVector.x == 5);
		CHECK(changedVector.y == 6);
		CHECK(changedVector.z == 6);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		CVector3D changedVector = firstVector + secondVector;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем бинарный оператор -")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(3, 7, 2);
		CVector3D secondVector(2, -1, 4);
		CVector3D changedVector = firstVector - secondVector;
		CHECK(changedVector.x == 1);
		CHECK(changedVector.y == 8);
		CHECK(changedVector.z == -2);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		CVector3D changedVector = firstVector - secondVector;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем оператор +=")
{
	WHEN("Ненулевой вектор")
	{
		CVector3D firstVector(3, 7, 2);
		CVector3D secondVector(2, -1, 4);
		firstVector += secondVector;
		CHECK(firstVector.x == 5);
		CHECK(firstVector.y == 6);
		CHECK(firstVector.z == 6);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		firstVector += secondVector;
		CHECK(firstVector.x == 0);
		CHECK(firstVector.y == 0);
		CHECK(firstVector.z == 0);
	}
}

SCENARIO("Проверяем оператор -=")
{
	WHEN("Ненулевой вектор")
	{
		CVector3D firstVector(3, 7, 2);
		CVector3D secondVector(2, -1, 4);
		firstVector -= secondVector;
		CHECK(firstVector.x == 1);
		CHECK(firstVector.y == 8);
		CHECK(firstVector.z == -2);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		firstVector -= secondVector;
		CHECK(firstVector.x == 0);
		CHECK(firstVector.y == 0);
		CHECK(firstVector.z == 0);
	}
}

SCENARIO("Проверяем бинарный оператор * вектора на скаляр")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(3, 7, 2);
		double scalar = 4;
		CVector3D changedVector = firstVector * scalar;
		CHECK(changedVector.x == 12);
		CHECK(changedVector.y == 28);
		CHECK(changedVector.z == 8);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		double scalar = 4;
		CVector3D changedVector = firstVector * scalar;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем бинарный оператор * скаляра на вектор")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(3, 7, 2);
		double scalar = 4;
		CVector3D changedVector = scalar * firstVector;
		CHECK(changedVector.x == 12);
		CHECK(changedVector.y == 28);
		CHECK(changedVector.z == 8);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		double scalar = 4;
		CVector3D changedVector = scalar * firstVector;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем бинарный оператор / вектора на скаляр")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(4, 8, 16);
		double scalar = 4;
		CVector3D changedVector = firstVector / scalar;
		CHECK(changedVector.x == 1);
		CHECK(changedVector.y == 2);
		CHECK(changedVector.z == 4);
	}
	WHEN("Нулевые вектора, то есть деление на ноль")
	{
		CVector3D firstVector;
		double scalar = 4;
		CVector3D changedVector = firstVector / scalar;
		CHECK(changedVector.x == 0);
		CHECK(changedVector.y == 0);
		CHECK(changedVector.z == 0);
	}
}

SCENARIO("Проверяем оператор /=")
{
	WHEN("Ненулевой вектор")
	{
		CVector3D firstVector(4, 8, 24);
		double number = 4;
		firstVector /= number;
		CHECK(firstVector.x == 1);
		CHECK(firstVector.y == 2);
		CHECK(firstVector.z == 6);
	}
	WHEN("Нулевой вектор")
	{
		CVector3D firstVector;
		double number = 4;
		firstVector /= number;
		CHECK(firstVector.x == 0);
		CHECK(firstVector.y == 0);
		CHECK(firstVector.z == 0);
	}
	WHEN("Деление на ноль")
	{
		CVector3D firstVector;
		double number = 0;
		try
		{
			firstVector /= number;
		}
		catch (std::invalid_argument const& err)
		{
			CHECK(firstVector.x == 0);
			CHECK(firstVector.y == 0);
			CHECK(firstVector.z == 0);
			std::cout << err.what();
		}
	}
}

SCENARIO("Проверяем оператор ==")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(3, 7, 2);
		CVector3D secondVector(3, 7, 2);
		CHECK(firstVector == secondVector);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		CHECK(firstVector == secondVector);
	}
}

SCENARIO("Проверяем оператор !=")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(-3, -7, -2);
		CVector3D secondVector(3, 7, 2);
		CHECK(firstVector != secondVector);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		CHECK((firstVector != secondVector) == false);
	}
}

SCENARIO("Проверяем оператор вывода в поток <<")
{
	WHEN("Ненулевые вектора")
	{
		std::ostringstream outputStream;
		CVector3D firstVector(-3, -7, -2);
		outputStream << firstVector;
		CHECK(outputStream.str() == "-3.000000, -7.000000, -2.000000\n");
	}
	WHEN("Нулевые вектора")
	{
		std::ostringstream outputStream;
		CVector3D firstVector;
		outputStream << firstVector;
		CHECK(outputStream.str() == "0.000000, 0.000000, 0.000000\n");
	}
}

SCENARIO("Проверяем оператор ввода из входного потока >>")
{
	WHEN("В ненулевой вектор")
	{
		std::istringstream inputStream("3.55, -7.22, 2.81");
		CVector3D firstVector(4, 1, 2);
		inputStream >> firstVector;
		CHECK(firstVector.x == 3.55);
		CHECK(firstVector.y == -7.22);
		CHECK(firstVector.z == 2.81);
	}
	WHEN("В нулевой вектор")
	{
		std::istringstream inputStream("-3.55, 7.22, 2.81");
		CVector3D firstVector;
		inputStream >> firstVector;
		CHECK(firstVector.x == -3.55);
		CHECK(firstVector.y == 7.22);
		CHECK(firstVector.z == 2.81);
	}
	WHEN("Передаём не число")
	{
		std::istringstream inputStream("-3.55fff, -gsg7.22, ss2.81");
		CVector3D firstVector(0, 0, 0);
		try
		{
			inputStream >> firstVector;
		}
		catch (std::invalid_argument const& err)
		{
			CHECK(firstVector.x == 0);
			CHECK(firstVector.y == 0);
			CHECK(firstVector.z == 0);
			std::cout << err.what();
		}
	}
}

SCENARIO("Проверяем функцию вычисления скалярного произведения двух трехмерных векторов")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(-3, -7, -2);
		CVector3D secondVector(3, 7, 2);
		double scalarMultiply = DotProduct(firstVector, secondVector);
		CHECK(scalarMultiply == -62.0);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		double scalarMultiply = DotProduct(firstVector, secondVector);
		CHECK(scalarMultiply == 0);
	}
}

SCENARIO("Проверяем функцию вычисления векторного произведения двух трехмерных векторов")
{
	WHEN("Ненулевые вектора")
	{
		CVector3D firstVector(-3, -7, -2);
		CVector3D secondVector(4, 2, 44);
		CVector3D multiplyVector = CrossProduct(firstVector, secondVector);
		CHECK(multiplyVector.x == -304.0);
		CHECK(multiplyVector.y == -124.0);
		CHECK(multiplyVector.z == 22.0);
	}
	WHEN("Нулевые вектора")
	{
		CVector3D firstVector;
		CVector3D secondVector;
		CVector3D multiplyVector = CrossProduct(firstVector, secondVector);
		CHECK(multiplyVector.x == 0);
		CHECK(multiplyVector.y == 0);
		CHECK(multiplyVector.z == 0);
	}
}

SCENARIO("Выражение с различными операторами")
{
	WHEN("Арифметические операции")
	{
		CVector3D firstVector(-3, -7, -2);
		CVector3D secondVector(4, 2, 14);
		CVector3D multiplyVector = firstVector + secondVector * 3.0 + secondVector - firstVector;
		CHECK(multiplyVector.x == 16.0);
		CHECK(multiplyVector.y == 8.0);
		CHECK(multiplyVector.z == 56.0);
	}
	WHEN("Арифметические операции с операторами присваивания")
	{
		CVector3D firstVector(-3, -7, -2);
		CVector3D secondVector(4, 2, 14);
		CVector3D multiplyVector;
		multiplyVector += (firstVector /= 4.0) + (secondVector *= 3.0) + (secondVector -= firstVector);
		CVector3D requiredVector(27.25, 34.25, 63.5);
		CHECK(requiredVector == multiplyVector);
	}
}
