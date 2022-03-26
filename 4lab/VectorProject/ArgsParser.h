#pragma once
#include <string>
#include <optional>

struct Files
{
	std::string inputFileName;
	std::string outputFileName;
};

std::optional<Files> ParseProgramArguments(int argc, char* argv[])
{
	if (argc != 3)
	{
		return std::nullopt;
	}

	Files files{};
	files.inputFileName = argv[1];
	files.outputFileName = argv[2];

	return files;
}
