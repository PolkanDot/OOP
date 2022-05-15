#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../catch2/catch.hpp"
#include "../DictionaryProject/DictionaryFunctions.h"
#include <Windows.h>

TEST_CASE("Чтение пустого словаря")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, string> dictionary;
	istringstream inputFile("");
	ReadDictionary(inputFile, dictionary);
	REQUIRE(dictionary.size() == 0);
}

TEST_CASE("Чтение непустого словаря")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream dictionaryFile;
	map <string, string> dictionary;
	dictionaryFile.open("../DictionaryProject/dictionary.txt", ios::in);
	if (!dictionaryFile.is_open())
	{
		cout << "Failed to open  for reading\n";
	}
	ReadDictionary(dictionaryFile, dictionary);	
	REQUIRE(dictionary.size() == 9);

}

TEST_CASE("Перевод слова в верхнем регистре")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, string> dictionary{ {"ball", "мячик"} };
	map <string, string> newWordsDictionary;
	fstream inputWord;
	ostringstream response("");
	inputWord.open("test_input1.txt", ios::in);
	string translation("мячик\n");
	Translate(inputWord, response, dictionary, newWordsDictionary);
	REQUIRE(response.str() == translation);
	inputWord.close();
}

TEST_CASE("Перевод слова в нижнем регистре")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, string> dictionary{ {"ball", "мячик"} };
	map <string, string> newWordsDictionary;
	fstream inputWord;
	ostringstream response("");
	inputWord.open("test_input2.txt", ios::in);
	string translation("мячик\n");
	Translate(inputWord, response, dictionary, newWordsDictionary);
	REQUIRE(response.str() == translation);
	inputWord.close();
}

TEST_CASE("Перевод слова, отсутствующего в словаре")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, string> dictionary{ {"ball", "мячик"} };
	map <string, string> newWordsDictionary;
	fstream inputWord;
	ostringstream response("");
	inputWord.open("test_input3.txt", ios::in);
	string word = "translation";
	string translation = "перевод";
	Translate(inputWord, response, dictionary, newWordsDictionary);
	REQUIRE(newWordsDictionary[word] == translation);
	inputWord.close();
}

TEST_CASE("Запись новых переводов в файл словаря")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map <string, string> dictionary{ {"ball", "мячик"}, {"hello", "привет"} };
	fstream outputFile;
	string record;
	outputFile.open("test_input5.txt", ios::out);
	WriteRecordToFile(outputFile, dictionary);
	outputFile.close();
	outputFile.open("test_input5.txt", ios::in);
	string compare;
	compare = "ball;мячик";
	getline(outputFile, record);
	getline(outputFile, record);
	REQUIRE(record == compare);
	getline(outputFile, record);
	compare = "hello;привет";
	REQUIRE(record == compare);
}