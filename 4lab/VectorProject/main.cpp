#include <iostream>
#include <string>
#include <vector>
#include "WorkWithVector.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

const std::string DivisionByZero = "Error: Uncorrect set of numbers (0 - minimum number -> division by zero)";

int main(int argc, char* argv[])
{
	
	auto PrimaryVector = ReadingVector(cin);;
	if (!(PrimaryVector.has_value()))
	{
		return 1;
	}
	
	std::optional<ExtremeElements> operands = FindingMinMax(PrimaryVector.value());

	if (operands->Min == 0)
	{
		cout << DivisionByZero << endl;
		return 1;		
	}
	
	MultiplicationByMaximumAndDivisionByMinimum(PrimaryVector.value(), operands->Max, operands->Min);
	SortVectorInAscendingOrder(PrimaryVector.value());

	PrintVector(cout, PrimaryVector.value());
	return 0;
}
