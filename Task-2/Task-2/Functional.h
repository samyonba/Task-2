#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>

class Functional
{
private:
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

	static int countVowels_count_if_find(std::string& source, std::string& vowels);
	static int countVowels_count_if_for(std::string& source, std::string& vowels);
	static int countVowels_for_find(std::string& source, std::string& vowels);
	static int countVowels_for_for(std::string& source, std::string& vowels);
};
