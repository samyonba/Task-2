#include "Functional.h"

int Functional::countVowels_count_if_find(std::string& source, std::string& vowels)
{
	Timer timer("countVowels_count_if_find time");

	int vowelsNumber = std::count_if(source.begin(), source.end(), [vowels](char c)
		{
			return std::find(vowels.begin(), vowels.end(), c) != vowels.end();
		});

	timer.print();
	return vowelsNumber;
}

int Functional::countVowels_count_if_for(std::string& source, std::string& vowels)
{
	Timer timer("countVowels_count_if_for time");

	int vowelsNumber = std::count_if(source.begin(), source.end(), [vowels](char c)
		{
			for (char vowel : vowels)
			{
				if (vowel == c)
				{
					return true;
				}
			}
			return false;
		});

	timer.print();
	return vowelsNumber;
}

int Functional::countVowels_for_find(std::string& source, std::string& vowels)
{
	Timer timer("countVowels_for_find time");
	
	int vowelsNumber = 0;
	for (char c : source)
	{
		if (std::find(vowels.begin(), vowels.end(), c) != vowels.end())
			++vowelsNumber;
	}

	timer.print();
	return vowelsNumber;
}

int Functional::countVowels_for_for(std::string& source, std::string& vowels)
{
	Timer timer("countVowels_for_for time");

	int vowelsNumber = 0;
	for (char c : source)
	{
		for (char vowel : vowels)
		{
			if (c == vowel)
				++vowelsNumber;
		}
	}

	timer.print();
	return vowelsNumber;
}
