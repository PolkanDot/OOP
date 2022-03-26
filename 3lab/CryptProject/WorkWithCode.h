#pragma once
#include <iostream>
#include <Windows.h>
#include <optional>
#include <fstream>
#include <string>

int CryptData(std::istream& input, std::ostream& output,
	const std::string& approach, const int& number)
{
	char inputByte;
	char* ptr = &inputByte;
	while (input.read(ptr, 1))
	{
		//XOR
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
}

int EncryptData(std::istream& input, std::ostream& output,
	const std::string& approach, const int& number)
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
void ProcessFile(std::istream& input, std::ostream& output,
	const std::string& approach, const int& number)
{
	if (approach == "crypt")
	{
		CryptData(input, output, approach, number);
	}
	else
	{
		EncryptData(input, output, approach, number);
	}
};
