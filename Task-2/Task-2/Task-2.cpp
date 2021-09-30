
#include <iostream>
#include <chrono>
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

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::string m_name;
    std::chrono::time_point<clock_t> m_beg;
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now()
            - m_beg).count();
    }
public:
    Timer() : m_beg(clock_t::now()) { }
    Timer(std::string name) : m_name(name), m_beg(clock_t::now()) { }
    void start(std::string name) {
        m_name = name;
        m_beg = clock_t::now();
    }
    void print() const {
        std::cout << m_name << ":\t" << elapsed() * 1000 << " ms" << '\n';
    }
};


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
    
    //vector<int*> intVector;
    //for (size_t i = 0; i < 10; i++)
    //{
    //    int* a = new int(rand() &1000);
    //    intVector.push_back(a);
    //}
    //cout << "[ ";
    //for (int* a : intVector)
    //{
    //    cout << *a << " ";
    //}
    //cout << "] Data" << endl;

    //Functional::sortPointers<int>(intVector);
    //cout << "[ ";
    //for (int* a : intVector)
    //{
    //    cout << *a << " ";
    //}
    //cout << "] Sorted data" << endl;

//-------------------------------

//---------- Задание 3 ----------

    setlocale(LC_ALL, "rus");
    std::ifstream file("C:\\Users\\1\\Desktop\\C++ сложные моменты\\Projects\\Task-2\\Task-2\\Input.txt", ios_base::in);
    if (!file.is_open())
        cout << "Can not open file" << endl;

    Timer timer("Time");

    int vowelsNumber = Functional::countVowelsSecond(file);
    cout << "Number of vowels is " << vowelsNumber << endl;

    //int vowelsNumber = Functional::countVowelsFourth(file);
    //cout << "Number of vowels is " << vowelsNumber << endl;

    timer.print();
//-------------------------------
    
    return 0;
}

