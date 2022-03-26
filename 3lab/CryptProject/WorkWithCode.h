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
		// ������ �������� ����, � ��������� ��� � ������������ �� ���������
		char outputByte = { 0b0 };
		// ��������� ��� ����� �� n-�� ������� � �����
		bool compare = (bool((1 << 5) & inputByte));
		// ���� true �� ������ � ������� ����������� 1
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
	// ���� �������� ��������� ������ �� �������� ����� ��������� ������ � �������� ����
	char* ptr = &inputByte;
	while (input.read(ptr, 1))
	{
		// ������ �������� ����, � ��������� ��� � ������������ �� ���������
		char outputByte = { 0b0 };
		// ��������� ��� ����� �� n-�� ������� � �����
		bool compare = (bool((1 << 2) & inputByte));
		// ���� true �� ������ � ������� ����������� 1
		if (compare)
		{
			// ��� �� 0 �������
			outputByte |= 1;
		}
		compare = (bool((1 << 3) & inputByte));
		if (compare)
		{
			// ��� �� 1 �������
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

// ��������� ����� � ����������� �� �������
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
