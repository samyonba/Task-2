
#include <iostream>
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

using namespace std;

int main()
{
//---------- Задание 1 ----------

    //int* first = new int(1);
    //int* second = new int(2);
    //cout << *first << " " << *second << endl;

    //Functional::swap<int>(first, second);
    //cout << *first << " " << *second << endl;

//-------------------------------

//---------- Задание 2 ----------
    
    vector<int*> intVector;
    for (size_t i = 0; i < 10; i++)
    {
        int* a = new int(rand() &1000);
        intVector.push_back(a);
    }
    cout << "[ ";
    for (int* a : intVector)
    {
        cout << *a << " ";
    }
    cout << "] Data" << endl;

    Functional::sortPointers<int>(intVector);
    cout << "[ ";
    for (int* a : intVector)
    {
        cout << *a << " ";
    }
    cout << "] Sorted data" << endl;

//-------------------------------

//---------- Задание 3 ----------



//-------------------------------
    
    return 0;
}

