#include <iostream>
#include "ArgsParser.h"
#include "WorkWithBases.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

// В консоль выводить успешные тесты с описанием проверки
// Все текстовые сообщения выводить в константы
// Сколько разных тестов нужно написать?

const string IncorrectParametersNumber = "Expected 3 arguments\nArguments: <source notation> <destination notation> <value>";
const string InvalidNotation = "Error: invalid notation\nMust be between 2 and 36";

int main(int argc, char* argv[])
{
	auto args = ParseProgramArguments(argc, argv);
	if (!args)
	{
		cout << IncorrectParametersNumber  << endl;
		return 1;
	}

	if (!(IsValidBase(args->srcBase) &&
		IsValidBase(args->destBase)))
	{
		cout << InvalidNotation << endl;
		return 1;
	}

	int srcBase = std::stoi(args->srcBase);
	int destBase = std::stoi(args->destBase);
	string value = args->value;

	string result{};
	try
	{
		result = CastToBase(srcBase, destBase, value);
	}
	catch (std::exception e)
	{
		cout << "Error: " << e.what() << endl;
		return 1;
	}

	cout << result << endl;
}