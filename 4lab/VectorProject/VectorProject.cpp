#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <vector>
#include "ArgsParser.h"
#include "WorkWithVector.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

struct FileName
{
	std::string inputFileName;
	std::string outputFileName;
	std::string findingString;
	std::string insertString;
};

const string IncorrectParametersNumber = "Expected 2 arguments\nUsage: <input file> <output file>";
const string OpeningFaild = "Failed to open ";
const string Reading = " for reading";
const string Writing = " for writing";
const string FlushError = "Failed to save data on disk";

int main(int argc, char* argv[])
{

	auto files = ParseProgramArguments(argc, argv);

	if (!files)
	{
		cout << IncorrectParametersNumber << endl;;
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(files->inputFileName);

	if (!inputFile.is_open())
	{
		std::cout << OpeningFaild << files->inputFileName << Reading << endl;
		return 1;
	}

	std::ofstream outputFile;
	outputFile.open(files->outputFileName);

	if (!outputFile.is_open())
	{
		std::cout << OpeningFaild << files->inputFileName << Writing << endl;
		return 1;
	}

	vector<float> PrimaryVector = ReadingVector(inputFile);

	vector<float>::iterator MaxIter;
	vector<float>::iterator MinIter;

	FindingMinMax(PrimaryVector, MaxIter, MinIter);

	for (int i = 0; i < PrimaryVector.size(); i++)
	{
		cout << PrimaryVector[i] << endl;
	}

	cout << *MaxIter << endl;
	cout << *MinIter << endl;
	if (!outputFile.flush()) // Если не удалось сбросить данные на диск
	{
		std::cout << FlushError << endl;
		return 1;
	}
	return 0;
}
