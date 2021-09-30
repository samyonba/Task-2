#include "Functional.h"

int Functional::countVowelsFirst(std::ifstream& file)
{
	unsigned long vowelsNumber = 0;
	std::string buffer;
	const std::vector<char> vowels{ 'À', 'à', 'Î', 'î', 'Ó', 'ó', 'Ý', 'ý', 'Û', 'û', 'ß', 'ÿ', '¨', '¸', 'Å', 'å', 'Þ', 'þ', 'È', 'è'};
	//while (!file.eof())
	//{
	//	file >> buffer;
	//	vowelsNumber += std::count_if(buffer.begin(), buffer.end(), [vowels](char ch)
	//		{
	//			return std::find(vowels.begin(), vowels.end(), ch);
	//		});
	//}
	return vowelsNumber;
}

int Functional::countVowelsSecond(std::ifstream& file)
{
	unsigned long vowelsNumber = 0;
	std::string buffer;
	const std::vector<char> vowels{ 'À', 'à', 'Î', 'î', 'Ó', 'ó', 'Ý', 'ý', 'Û', 'û', 'ß', 'ÿ', '¨', '¸', 'Å', 'å', 'Þ', 'þ', 'È', 'è'};
	while (!file.eof())
	{
		file >> buffer;
		vowelsNumber += std::count_if(buffer.begin(), buffer.end(), [vowels](char ch)
			{
				for (char vowel : vowels)
				{
					if (vowel == ch)
					{
						return true;
					}
				}
				return false;
			});
	}
	return vowelsNumber;
}

int Functional::countVowelsThird(std::ifstream& file)
{
	return 0;
}

int Functional::countVowelsFourth(std::ifstream& file)
{
	unsigned long vowelsNumber = 0;
	std::string buffer;
	const std::vector<char> vowels{ 'À', 'à', 'Î', 'î', 'Ó', 'ó', 'Ý', 'ý', 'Û', 'û', 'ß', 'ÿ', '¨', '¸', 'Å', 'å', 'Þ', 'þ', 'È', 'è' };
	while (!file.eof())
	{
		file >> buffer;
		for (size_t i = 0; i < buffer.size(); i++)
		{
			for (char vowel : vowels)
			{
				if (buffer.at(i) == vowel)
					vowelsNumber++;
			}
		}
	}
	return vowelsNumber;
}
