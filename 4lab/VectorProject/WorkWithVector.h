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

std::optional<vector<double>> ReadingVector(std::istream& input);

std::optional<ExtremeElements> FindingMinMax(vector<double>& Vector);

void MultiplicationByMaximumAndDivisionByMinimum(vector<double>& vector, double max, double min);

void SortVectorInAscendingOrder(std::vector<double>& vector);

void PrintVector(std::ostream& output, const std::vector<double>& vector);
