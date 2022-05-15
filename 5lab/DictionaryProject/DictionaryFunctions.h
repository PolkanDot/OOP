#pragma once
#include <iostream>
#include <map>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <optional>
#include <iterator>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void ReadDictionary(istream& inputStream, map<string, string>& dictionary);

bool Translate(istream& inputStream, ostream& outputStream, map<string, string>& dictionary, map<string, string>& dictionaryWithNewWords);

void WriteRecordToFile(fstream& file, map<string, string>& dictionary);
