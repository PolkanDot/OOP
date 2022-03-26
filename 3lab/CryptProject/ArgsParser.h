#pragma once
#include <iostream>
#include <optional>
#include <fstream>
#include <string>

const std::string invalidArgsCount = "Invalid arguments count\n";
const std::string inputCryptFormat = "Usage: crypt <input file> <output file> <key>\n";
const std::string orBetween = "Or\n";
const std::string inputEncryptFormat = "Usage: encrypt <input file> <output file> <key>\n";
const std::string crypt = "crypt";
const std::string encrypt = "encrypt";
const std::string errArrpoachName = "Error in the approach name. The <decrypt> and <encrypt> approaches are supported\n";

// —труктура дл€ хранени€ аргументов командной строки
struct Args
{
	std::string approachName;
	std::string inputFileName;
	std::string outputFileName;
	int keyNumber;
};

// ѕарсинг аргументов, идущих на вход программе, проверка на правильность их количества
std::optional<Args> ParseArgs(int argc, char* argv[])
{

	if (argc != 5)
	{
		std::cout << invalidArgsCount;
		std::cout << inputCryptFormat;
		std::cout << orBetween;
		std::cout << inputEncryptFormat;
		return std::nullopt;
	}

	Args args;
	args.approachName = argv[1];

	if (!(args.approachName == crypt || args.approachName == encrypt))
	{
		std::cout << errArrpoachName;
		return std::nullopt;
	}
	args.inputFileName = argv[2];
	args.outputFileName = argv[3];
	std::string temp = argv[4];
	if (temp == "")
	{
		return std::nullopt;
	}
	for (size_t i = 0; i < size(temp); i++)
	{
		if (temp[i] < '0' || temp[i] > '9')
		{
			return std::nullopt;
		}
	}
	int count = stoi(temp);
	args.keyNumber = count;
	return args;
}