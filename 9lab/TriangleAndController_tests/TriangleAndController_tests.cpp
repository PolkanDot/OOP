#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../Triangle/CTriangle.h"
#include "../Triangle/Controller.h"
#include <Windows.h>

SCENARIO("Тестирование класса Triangle")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	WHEN("Поступление на вход коректных данных")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		CTriangle triangle = CTriangle(1, 1.5, 1.7);
		THEN("Сформировался объект triangle")
		{
			double side1 = triangle.GetSide1();
			double side2 = triangle.GetSide2();
			double side3 = triangle.GetSide3();
			double area = triangle.GetArea();
			double perimeter = triangle.GetPerimeter();
			CHECK(side1 == 1);
			CHECK(side2 == 1.5);
			CHECK(side3 == 1.7);
			CHECK(round(area * 100) / 100 == 9.52);
			CHECK(perimeter == 4.2);
		}
	}

	WHEN("Поступление на вход ноля")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		CTriangle triangle = CTriangle(1, 1, 0);
		THEN("Сформировался объект triangle")
		{
			double side1 = triangle.GetSide1();
			double side2 = triangle.GetSide2();
			double side3 = triangle.GetSide3();
			double area = triangle.GetArea();
			double perimeter = triangle.GetPerimeter();
			CHECK(side1 == 1);
			CHECK(side2 == 1);
			CHECK(side3 == 0);
			CHECK(area == 0);
			CHECK(perimeter == 2);
		}
	}

	WHEN("Поступление на вход 2 нолей")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		THEN("Получение исключения типа domain_error")
		{
			try
			{
				CTriangle triangle = CTriangle(0, 0, 1);
			}
			catch (std::domain_error dExeption)
			{
				std::string temp = dExeption.what();
				CHECK(temp == domainError);
			}
		}
	}

	WHEN("Поступление на вход трех нолей")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		CTriangle triangle = CTriangle(0, 0, 0);
		THEN("Сформировался объект triangle")
		{
			double side1 = triangle.GetSide1();
			double side2 = triangle.GetSide2();
			double side3 = triangle.GetSide3();
			double area = triangle.GetArea();
			double perimeter = triangle.GetPerimeter();
			CHECK(side1 == 0);
			CHECK(side2 == 0);
			CHECK(side3 == 0);
			CHECK(area == 0);
			CHECK(side1 == 0);
		}
	}

	WHEN("Поступление на вход отрицательных чисел")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		THEN("Получение исключения типа invalid_exeption")
		{
			try
			{
				CTriangle triangle = CTriangle(-1, 1.5, 1.7);
			}
			catch (std::invalid_argument iExeption)
			{
				std::string temp = iExeption.what();
				CHECK(temp == invalidArgument1);
			}
		}
	}

	WHEN("Некорректные длинны для формирования треугольника")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		THEN("Получение исключения типа domain_error")
		{
			try
			{
				CTriangle triangle = CTriangle(1, 1, 10);
			}
			catch (std::domain_error dExeption)
			{
				std::string temp = dExeption.what();
				CHECK(temp == domainError);
			}
		}
	}
}
SCENARIO("Тестирование класса Controller")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	WHEN("Поступление на вход коректных данных")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::istringstream inputStream("1, 1.5, 1.7\n");
		std::ostringstream outputStream;
		Controller controller;
		controller.Starting(inputStream, outputStream);
		THEN("Вывод корректных данных о площади и периметре")
		{
			std::string temp = outputStream.str();
			CHECK(temp == intro + "\n" + "Area: 9.5247\nPerimeter: 4.2\n");

		}
	}

	WHEN("Поступление на вход буквенного выражения")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::istringstream inputStream("asad1, 1.5, 1.7\n");
		std::ostringstream outputStream;
		Controller controller;
		controller.Starting(inputStream, outputStream);
		THEN("Вывод сообщения об ошибке")
		{
			std::string temp = outputStream.str();
			CHECK(temp == intro + "\n" + notNumberOrNotComma + "\n");

		}
	}

	WHEN("Поступление на вход выражения в неправильном формате")
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		std::istringstream inputStream("1 1.5, 1.7\n");
		std::ostringstream outputStream;
		Controller controller;
		controller.Starting(inputStream, outputStream);
		THEN("Вывод сообщения об ошибке")
		{
			std::string temp = outputStream.str();
			CHECK(temp == intro + "\n" + notNumberOrNotComma + "\n");

		}
	}
}