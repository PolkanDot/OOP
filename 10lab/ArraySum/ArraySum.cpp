#include <iostream>
#include <fstream>
#include "ArraySum.h"

int main()
{
    std::cout << "int " << std::numeric_limits<int>::max() << std::endl;
    std::cout << "float " << std::numeric_limits<float>::max() << std::endl;
    std::cout << "double " << std::numeric_limits<double>::max() << std::endl;
    std::vector<int> arr1{ -2134, -956, -9345 };
    int sum1 = ArraySum(arr1);
    std::cout << sum1 << std::endl;
    std::vector<float> arr2{ 1.40282e+38 , 1.40282e+38 };
    float sum2 = ArraySum(arr2);
    std::cout << sum2 << std::endl;
    std::vector<double> arr3{ 0.59769e+308, 0.59769e+308, 0.59769e+308 };
    double sum3 = ArraySum(arr3);
    std::cout << sum3 << std::endl;
    std::ifstream inputFile;
    inputFile.open("WaP1.txt");

    if (!inputFile.is_open())
    {
        std::cout << "Failed to open input.txt for reading\n";
        return 1;
    }

    std::vector<std::string> arr4{};
    while (!inputFile.eof())
    {
        std::string str;
        getline(inputFile, str);
        arr4.push_back(str);
    }
    std::string sum4 = ArraySum(arr4);
    std::cout << sum4 << std::endl;
    std::vector<std::string> arr5{ "a", "b", "c" };
    std::string sum5 = ArraySum(arr5);
    std::cout << sum5 << std::endl;
}
