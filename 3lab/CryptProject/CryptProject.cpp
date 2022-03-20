#include <iostream>
#include <Windows.h>
#include <optional>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

const string invalidArgsCount = "Invalid arguments count\n";
const string inputCryptFormat = "Usage: crypt.exe crypt <input file> <output file> <key>\n";
const string orBetween = "Or\n";
const string inputEncryptFormat = "Usage: crypt.exe encrypt <input file> <output file> <key>\n";
const string errorRealCount = "Enter an integer count\n";
const string errorRange = "The count must be in the range from 0 to 255\n";
const string writeToFile = "Error when writing to a file\n";
const string crypt = "crypt";
const string encrypt = "encrypt";
const string errArrpoachName = "Error in the approach name. The <decrypt> and <encrypt> approaches are supported\n";
const string errOpenFile = "Failed to open ";
const string reading = " for reading\n";
const string writing = " for writing\n";

// В структуре данного типа будем хранить аргументы командной строки
struct Args
{
	string approachName;
	string inputFileName;
	string outputFileName;
	int keyNumber;
};

// Парсинг аргументов, идущих на вход программе, проверка на правильность их количества
optional<Args> ParseArgs(int argc, char* argv[])
{

	if (argc != 5)
	{
		cout << invalidArgsCount;
		cout << inputCryptFormat;
		cout << orBetween;
		std::cout << inputEncryptFormat;
		return std::nullopt;
	}

	// Объявляем переменную args типа Args
	Args args;
	args.approachName = argv[1];

	if (!(args.approachName == crypt || args.approachName == encrypt))
	{
		std::cout << errArrpoachName;
		return std::nullopt;
	}
	args.inputFileName = argv[2];
	args.outputFileName = argv[3];
	string temp = argv[4];
	if (temp == "")
	{
		return std::nullopt;
	}
	for (int i = 0; i < size(temp); i++)
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

int CryptData(istream& input, ostream& output,
	const string& approach, const int& number)
{
	char inputByte;
	char* ptr = &inputByte;
	while (input.read(ptr, 1))
	{
		inputByte ^= number;
		// создаём выходной байт, и заполняем его в соответствии по алгоритму
		char outputByte = { 0b0 };
		// проверяем что стоит на n-ой позиции в байте
		bool compare = (bool((1 << 5) & inputByte));
		// если true то ставим в позицию перемещения 1
		if (compare)
		{
			outputByte |= 1;
		}
		compare = (bool((1 << 6) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 1);;
		}
		compare = (bool(1 & inputByte));
		if (compare)
		{
			outputByte |= (1 << 2);
		}
		compare = (bool((1 << 1) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 3);
		}
		compare = (bool((1 << 2) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 4);
		}
		compare = (bool((1 << 7) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 5);
		}
		compare = (bool((1 << 3) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 6);
		}
		compare = (bool((1 << 4) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 7);
		}
		output.write((char*)&outputByte, 1);
	}
	return 0;

	// кладём в файл output 
	// очистить память в bufer
}

int EncryptData(istream& input, ostream& output,
	const string& approach, const int& number)
{
	char inputByte;
	// Пока возможно прочитать строку из входного файла выполняем запись в выходной файл
	char* ptr = &inputByte;
	while (input.read(ptr, 1))
	{
		// создаём выходной байт, и заполняем его в соответствии по алгоритму
		char outputByte = { 0b0 };
		// проверяем что стоит на n-ой позиции в байте
		bool compare = (bool((1 << 2) & inputByte));
		// если true то ставим в позицию перемещения 1
		if (compare)
		{
			// бит на 0 позиции
			outputByte |= 1;
		}
		compare = (bool((1 << 3) & inputByte));
		if (compare)
		{
			// бит на 1 позиции
			outputByte |= (1 << 1);;
		}
		compare = (bool((1 << 4) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 2);
		}
		compare = (bool((1 << 6) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 3);
		}
		compare = (bool((1 << 7) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 4);
		}
		compare = (bool(1 & inputByte));
		if (compare)
		{
			outputByte |= (1 << 5);
		}
		compare = (bool((1 << 1) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 6);
		}
		compare = (bool((1 << 5) & inputByte));
		if (compare)
		{
			outputByte |= (1 << 7);
		}
		outputByte ^= number;
		output.write((char*)&outputByte, 1);
	}
	return 0;
}

// Обработка файла в зависимости от подхода
void ProcessFile(istream& input, ostream& output,
	const string& approach, const int& number)
{
	if (approach == crypt)
	{
		CryptData(input, output, approach, number);
	}
	else
	{
		EncryptData(input, output, approach, number);
	}
}

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
		const string errFileRead = "";
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