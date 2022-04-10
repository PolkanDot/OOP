#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct ExtremeElements
{
	double Min;
	double Max;
};

std::optional<vector<double>> ReadingVector(std::istream& input)
{
	std::vector<double> result;
	double num;
	while (input >> num)
	{
		result.push_back(num);
	}
	if (result.empty())
	{
		return std::nullopt;
	}
	return result;
};

std::optional<ExtremeElements> FindingMinMax(vector<double>& Vector)
{
	double Max = *std::max_element(Vector.begin(), Vector.end());
	double Min = *std::min_element(Vector.begin(), Vector.end());

	if (Min == 0)
	{
		return std::nullopt;
	}

	ExtremeElements elements;
	elements.Max = Max;
	elements.Min = Min;

	return elements;
}

void MultiplicationByMaximumAndDivisionByMinimum(vector<double>& vector, double max, double min)
{
	std::transform(vector.begin(), vector.end(), vector.begin(), [min, max](double item) -> double { return (item * min) / max; });
}

void SortVectorInAscendingOrder(std::vector<double>& vector)
{
	std::sort(vector.begin(), vector.end());
}

void PrintVector(std::ostream& output, const std::vector<double>& vector)
{
	output.setf(std::ios::fixed);
	output.precision(3);
	std::copy(vector.begin(), vector.end(), std::ostream_iterator<double>(output, " "));
	output << endl;
}