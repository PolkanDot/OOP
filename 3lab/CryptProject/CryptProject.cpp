#include <iostream>
#include <Windows.h>
#include <optional>
#include <fstream>
#include <string>
#include "ArgsParser.h"
#include "WorkWithCode.h"


using namespace std;

const string errorRealCount = "Enter an integer count\n";
const string errorRange = "The count must be in the range from 0 to 255\n";
const string writeToFile = "Error when writing to a file\n";
const string errOpenFile = "Failed to open ";
const string reading = " for reading\n";
const string writing = " for writing\n";

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	auto args = ParseArgs(argc, argv);
	// Проверка правильности аргументов командной строки
	if (!args)
	{
		return 1;
	}

	// Создаём поток для чтение из входного файла 
	ifstream inputFileName;
	inputFileName.open(args->inputFileName, std::ios::in | std::ios::binary);


	// Проверем, открылся ли входной файл
	if (!inputFileName.is_open())
	{

		cout << errOpenFile << args->inputFileName << reading;
		return 1;
	}

	// Создаём поток для записи в выходной файл 
	ofstream outputFileName;
	outputFileName.open(args->outputFileName, std::ios::out | std::ios::binary);


	// Проверем, открылся ли выходной файл
	if (!outputFileName.is_open())
	{
		cout << errOpenFile << args->outputFileName << writing;
		return 1;
	}
	ProcessFile(inputFileName, outputFileName, args->approachName, args->keyNumber);

	// Записываем в файл данные, возможно оставшиеся в буфере
	if (!outputFileName.flush())
	{
		std::cout << writeToFile;
		return 1;
	}
	return 0;
}