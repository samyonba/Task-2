
#include <iostream>
#include <string>
#include <iomanip>
#include "Functional.h"

/*1. Реализуйте шаблонную функцию Swap, которая принимает два указателя и обменивает
местами значения, на которые указывают эти указатели.
2. Реализуйте шаблонную функцию SortPointers, которая принимает вектор указателей и
сортирует указатели по значениям, на которые они указывают.
3. Подсчитайте количество гласных букв в книге “Война и мир”.Для подсчета используйте 4
способа:
    ○ count_if и find
    ○ count_if и цикл for
    ○ цикл for и find
    ○ 2 цикла for
Замерьте время каждого способа подсчета и сделайте выводы.*/


int main()
{
//---------- Задание 1 ----------

    std::cout << "----- Task 1 -----" << std::endl;
    int* first = new int(1);
    int* second = new int(2);
    std::cout << "first: " << * first << " , second: " << *second << std::endl;

    Functional::swap<int>(first, second);
    std::cout << "swap\n" << "first: " << *first << " , second: " << *second << "\n" << std::endl;

//-------------------------------

//---------- Задание 2 ----------
    
    std::cout << "----- Task 2 -----" << std::endl;
    std::vector<int*> intVector;
    for (size_t i = 0; i < 10; i++)
    {
        int* a = new int(rand() &1000);
        intVector.push_back(a);
    }
    std::cout << "[ ";
    for (int* a : intVector)
    {
        std::cout << *a << " ";
    }
    std::cout << "] - Data" << std::endl;

    Functional::sortPointers<int>(intVector);
    std::cout << "[ ";
    for (int* a : intVector)
    {
        std::cout << *a << " ";
    }
    std::cout << "] - Sorted data\n" << std::endl;

//-------------------------------

//---------- Задание 3 ----------
    std::cout << "----- Task 3 -----" << std::endl;
    setlocale(LC_ALL, "rus");
    std::ifstream file("C:\\Users\\1\\Desktop\\C++ сложные моменты\\Projects\\Task-2\\Task-2\\Input.txt", std::ios_base::in);
    if (!file.is_open())
        std::cout << "Can not open file" << std::endl;

    std::string vowelsString = "аоуэыяёеюи";
    std::string sourseString;
    std::string buffer;
    while (file)
    {
        std::getline(file, buffer);
        sourseString.append(buffer);
    }
    std::transform(sourseString.begin(), sourseString.end(), sourseString.begin(), [](unsigned char c) {return std::tolower(c); });

    std::cout << std::setw(32) << "vowels: " << Functional::countVowels_count_if_find(sourseString, vowelsString) << "\n" << std::endl;
    std::cout << std::setw(32) << "vowels: " << Functional::countVowels_count_if_for(sourseString, vowelsString) << "\n" << std::endl;
    std::cout << std::setw(32) << "vowels: " << Functional::countVowels_for_find(sourseString, vowelsString) << "\n" << std::endl;
    std::cout << std::setw(32) << "vowels: " << Functional::countVowels_for_for(sourseString, vowelsString) << "\n" << std::endl;

//-------------------------------
    
    return 0;
}
