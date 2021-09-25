#pragma once

#include <exception>
#include <string>

const int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year);


class Date
{
public:

	class BadNumbersInDate : public std::exception
	{

	};

	Date(unsigned short d = 1, unsigned short m = 1, unsigned short y = 1,
		unsigned short h = 1, unsigned short mi = 1);


	std::string ShowDate(bool system12h = false) const noexcept;


private:
	unsigned short day;
	unsigned short month;
	unsigned short year;
	unsigned short hour;
	unsigned short min;

	void CheckDate() const //throws exception if date elements are not valid


};
