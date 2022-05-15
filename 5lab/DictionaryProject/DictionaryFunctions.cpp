#include "DictionaryFunctions.h"


const string enter = "������� ���������� ����� ��� ��������������, ������� ������ ���������: \n";
const string exitCommand = "��� ������ �� ������� ������� \"...\"\n";
const string anonymWord = "����������� �����(��������������) \"";
const string responsable = "\". ������� ������� ��� ������ ������ ��� ������.\n";
const string word = "�����(��������������) \"";
const string ignoreWord = "\" ���������������.\n";
const string save = "\" ��������� � ������� ��� \"";
const string point = "\".\n";
const string points = "...";
const string nextString = "\n";
const string space = " ";

void ReadDictionary(istream& inputStream, map<string, string>& dictionary)
{
	string record, key, value = "";
	while (getline(inputStream, record))
	{
		size_t foundPos = record.find(";", 0);
		string key, value = "";
		key.append(record, 0, foundPos);
		value.append(record, foundPos + 1, record.length() - foundPos);
		dictionary[key] = value;
	}
}

bool Translate(istream& inputStream, ostream& outputStream, map<string, string>& dictionary, map<string, string>& dictionaryWithNewWords)
{
	cout << enter;
	cout << exitCommand;
	string key, response;
	getline(inputStream, key);
	transform(key.begin(), key.end(), key.begin(), tolower);
	map <string, string> ::iterator foundWord;
	bool wordWasAdded = false;
	while (!(key == points))
	{
		foundWord = dictionary.find(key);
		if (foundWord == dictionary.end())
		{
			cout << anonymWord << key << responsable;
			getline(inputStream, response);
			if (response == "")
			{
				cout << word << key << ignoreWord;
			}
			else
			{
				dictionaryWithNewWords[key] = response;
				dictionary[key] = response;
				cout << word << key << save << response << point;
				wordWasAdded = true;
			}
		}
		else
		{
			outputStream << dictionary[key] << nextString;
		}
		getline(inputStream, key);
	}
	return wordWasAdded;
}

void WriteRecordToFile(fstream& file, map<string, string>& dictionary)
{
	map <string, string> ::iterator beginOfNewRecord = dictionary.begin();
	for (beginOfNewRecord; beginOfNewRecord != dictionary.end(); beginOfNewRecord++)
	{
		file << nextString;
		file << beginOfNewRecord->first;
		file << ";";
		file << beginOfNewRecord->second;
	}
}