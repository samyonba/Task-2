#pragma once
#include <vector>
#include <algorithm>
#include <fstream>

class Functional
{
public:
	template <typename T>
	static void swap(T* first, T* second)
	{
		T temp = *first;
		*first = *second;
		*second = temp;
	}

	template <typename T>
	static void sortPointers(std::vector<T*> &v)
	{
		std::sort(v.begin(), v.end(), [](T* first, T* second)
			{
				return (*first < *second);
			});
	}

	static int countVowelsFirst(std::ifstream& file);
	static int countVowelsSecond(std::ifstream& file);
	static int countVowelsThird(std::ifstream& file);
	static int countVowelsFourth(std::ifstream& file);
};

