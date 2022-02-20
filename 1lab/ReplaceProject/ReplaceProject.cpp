#include <iostream>
#include <fstream>
#include <string>
#include <optional>
// Нужно сделать тесты
// Нужно вывести работу с файлами в отдельное

struct Args
{
	std::string inputFileName;
	std::string outputFileName;
	std::string findingString;
	std::string insertString;
};

std::optional<Args> ParsArguments(int argc, char* argv[])
{
	if (argc != 5)
	{
		return std::nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.outputFileName = argv[2];
	args.findingString = argv[3];
	args.insertString = argv[4];
	return args;
}

std::string ReplaceString(const std::string& subject,
	const std::string& searchString, const std::string& replacementString)
{
	size_t pos = 0;
	std::string result;
	while (pos < subject.length())
	{
		if (searchString.length() != 0)
		{
			size_t foundPos = subject.find(searchString, pos);
			result.append(subject, pos, foundPos - pos);
			if (foundPos != std::string::npos)
			{
				result.append(replacementString);
				pos = foundPos + searchString.length();
			}
			else
			{
				break;
		    }
		}
		else
		{
			return subject;
		}
	}
	return result;
}

void CopyFileWithReplace(std::istream& input, std::ostream& output,
	const std::string& searchString, const std::string& replacementString)
{
	std::string line;

	while (std::getline(input, line))
	{
		output << ReplaceString(line, searchString, replacementString) << "\n";
	}
}

int main(int argc, char* argv[])
{
	auto args = ParsArguments(argc, argv);

	if (!args)
	{
		std::cout << "Invalid argument count\n"
			<< "Usage: replace.exe <inputFile> <outputFile> <searchString> <replacementString>\n";
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open(args->inputFileName);

	std::ofstream outputFile;
	outputFile.open(args->outputFileName);

	CopyFileWithReplace(inputFile, outputFile, args->findingString, args->insertString);
	outputFile.flush();

	return 0;
}