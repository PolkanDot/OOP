#include <iostream>
#include <fstream>
#include <string>
#include <optional>
// подумать почему не использую метод реплэйс
// исправить проверку на пустую строку, почему проверка на каждой строке
struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string findingString;
	std::string insertString;
};

// Функция парсинга входящих параметров
// с проверкой на правильное их количество
std::optional<Args> ParseArguments(int argc, char* argv[])
{
	if (argc != 5)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.findingString = argv[3];
	args.insertString = argv[4];
	return args;
}

// Функция замены во входящей строке всех искомых подстрок на соответствующие
std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{
	size_t pos = 0;
	std::string result;
	while (pos < subject.length())
	{
		size_t foundPos = subject.find(searchString, pos);
		result.append(subject, pos, foundPos - pos);
		if (foundPos == std::string::npos)
		{
			break;
		}
		result.append(replacementString);
		pos = foundPos + searchString.length();
		
	}
	return result;
}

// Функция для построчного прохода входного файла
// с записью уже измененных строк в выходной файл
void CopyFileWithReplace(std::istream& input, std::ostream& output,
	const std::string& searchString, const std::string& replacementString)
{
	std::string line;

	while (std::getline(input, line))
	{
		output << ReplaceString(line, searchString, replacementString) << "\n";
	}
}

void CopyFile(std::istream& input, std::ostream& output)
{
	std::string line;

	while (std::getline(input, line))
	{
		output << line << "\n";
	}
}

int main(int argc, char* argv[])
{

	auto args = ParseArguments(argc, argv);

	if (!args) // вынести в функцию ParseArguments
	{
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(args->inputFileName);

	if (!inputFile.is_open())
	{
		std::cout << "Failed to open " << args->inputFileName << " for reading\n";
		return 1;
	}

	std::ofstream outputFile;
	outputFile.open(args->outputFileName);

	if (!outputFile.is_open())
	{
		std::cout << "Failed to open " << args->inputFileName << " for writing\n";
		return 1;
	}

	if (args->findingString.length() != 0)
	{
		CopyFileWithReplace(inputFile, outputFile, args->findingString, args->insertString);
	}
	else
	{
		CopyFile(inputFile, outputFile);
	}
	if (!outputFile.flush()) // Если не удалось сбросить данные на диск
	{
		std::cout << "Failed to save data on disk\n";
		return 1;
	}
	return 0;
}