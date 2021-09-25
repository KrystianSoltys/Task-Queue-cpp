#include "pch.h"
#include "date.h"
#include <iostream>

bool isLeapYear(int year)
{
	if (year % 4 == 0) //year validated in Date(class) constructor
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
				return true;
			else
				return false;
		}
		else
			return true;
	}
	
	return false;
}

Date::Date(unsigned int d, unsigned int m, unsigned int y,
	unsigned int h, unsigned int mi) :
	day(d), month(m), year(y), hour(h), min(mi)
{
	CheckDate();
}

std::string Date::ShowDayDate(bool system12h) const noexcept
{
	std::string	strDayDate = "";
	if (day < 10) strDayDate += '0';
	strDayDate += std::to_string(day) + '.';
	if (month < 10) strDayDate += '0';
	strDayDate += std::to_string(month) + '.' + std::to_string(year);

	return strDayDate;
}

void Date::CheckDate() const
{
	if (year < 1900 || year > 3000) throw BadNumbersInDate("Date.year is not between <1900,3000>.");
	if (month < 1 || month > 12) throw BadNumbersInDate("Date.month is not between <1,12>.");
	if (day < 1 || day > MonthsArr[month - 1])
	{
		if (isLeapYear(year) && month == 2 && day == 29);
		else throw BadNumbersInDate("Date.day is not correct day number.");
	}
	if (hour < 1 || hour > 24) throw BadNumbersInDate("Date.hour is not between <1,24>.");
	if (min < 1 || min > 60) throw BadNumbersInDate("Date.min is not between <1,60>");
}