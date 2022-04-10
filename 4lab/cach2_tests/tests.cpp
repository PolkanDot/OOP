#include <iostream>
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include "../VectorProject/WorkWithVector.h"

std::vector<double> GetInputVector()
{
	std::vector<double> input;
	input.push_back(15.0);
	input.push_back(20.0);
	input.push_back(10.0);
	return input;
}

std::vector<double> GetExpectedVector()
{
	std::vector<double> expected;
	expected.push_back(7.5);
	expected.push_back(10.0);
	expected.push_back(5.0);
	return expected;
}

std::vector<double> GetSortedVector()
{
	std::vector<double> input;
	input.push_back(10.0);
	input.push_back(15.0);
	input.push_back(20.0);
	return input;
}

TEST_CASE("Test reading vector")
{
	std::stringstream ss("15.0 20.0 10.0");
	REQUIRE(ReadingVector(ss) == GetInputVector());
	ss.clear();

	ss.str("");
	REQUIRE(ReadingVector(ss) == std::nullopt);
	ss.clear();
}

TEST_CASE("Test print vector")
{
	std::stringstream ss;
	PrintVector(ss, GetInputVector());
	REQUIRE(ss.str() == "15.000 20.000 10.000 \n");
}

TEST_CASE("Test process vector")
{
	auto vector = GetInputVector();
	double max = 20.0;
	double min = 10.0;
	MultiplicationByMaximumAndDivisionByMinimum(vector, max, min);
	REQUIRE(vector == GetExpectedVector());


}

TEST_CASE("Test sort vector in ascending order")
{
	auto vector = GetInputVector();
	SortVectorInAscendingOrder(vector);
	REQUIRE(vector == GetSortedVector());
}

TEST_CASE("Test find min and max elements")
{
	auto vector = GetInputVector();
	std::optional<ExtremeElements> args1 = FindingMinMax(vector);
	REQUIRE(args1->Min == 10.0);
	REQUIRE(args1->Max == 20.0);

	vector = GetInputVector();
	vector.push_back(0);
	std::optional<ExtremeElements> args2 = FindingMinMax(vector);
	REQUIRE(args2 == std::nullopt);
}


