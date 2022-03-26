#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

vector<float> ReadingVector(std::ifstream& input)
{
	vector<float> PrimaryVector;
	float number;

	while (!input.eof()) {
		input >> number;
		PrimaryVector.push_back(number);
	}
	return PrimaryVector;
}

void FindingMinMax(vector<float>& Vector, vector<float>::iterator& MaxIter, vector<float>::iterator& MinIter)
{
	MaxIter = std::max_element(Vector.begin(), Vector.end());
	MinIter = std::min_element(Vector.begin(), Vector.end());	
}