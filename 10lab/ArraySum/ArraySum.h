#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <math.h>

const std::string errMessege = "The amount exceeded the limit";
const std::string emptyArr = "An empty array was passed to the function";


template <typename T>
T ArraySum(std::vector<T> const& vect)
{
	T sumWork{};
	T sumMain{};

	if (!vect.empty())
	{
		for (unsigned long i = 0; i < vect.size(); i++)
		{
			if (typeid(vect[i]) == typeid(std::string))
			{
				sumWork += vect[i];
				continue;
			}
			if (((sumWork + vect[i] > sumMain) && (sumWork < sumMain))
				|| ((sumWork + vect[i] < sumMain) && (sumWork > sumMain))
				|| (sumWork + vect[i] > std::numeric_limits<T>::max())
				|| (sumWork + vect[i] < std::numeric_limits<T>::min()))
			{
				throw std::domain_error(errMessege);
			}		
			sumWork += vect[i];
		}
		sumMain = sumWork;
	}
	else
	{
		std::cout << emptyArr;
	}
	return sumMain;
}
