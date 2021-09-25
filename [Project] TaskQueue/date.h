#pragma once

#include <exception>
#include <string>

const int MonthsArr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year);


class Date
{
public:

	class BadNumbersInDate : public std::exception
	{
	public:
		BadNumbersInDate(const char* str) : std::exception(str) {}
		virtual char const* what() const { return std::exception::what(); }
	};

	Date(unsigned int d = 1, unsigned int m = 1, unsigned int y = 1,
		unsigned int h = 1, unsigned int mi = 1);


	std::string ShowDayDate(bool system12h = false) const noexcept;


private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	unsigned int hour;
	unsigned int min;

	void CheckDate() const; //throws exception if date elements are not valid


};
