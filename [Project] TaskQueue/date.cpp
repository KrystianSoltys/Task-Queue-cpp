#include "pch.h"
#include "date.h"
#include <iostream>
#include <ctime>

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

int abs(const unsigned int& a, const unsigned int &b)
{
	int x = (a - b);
	if (x < 0) x = -x;
	return x;
}

/////////////////////////////////////////////////////////////

Date::Date(unsigned int d, unsigned int m, unsigned int y,
	unsigned int h, unsigned int mi, bool checkBefore) :
	day(d), month(m), year(y), hour(h), min(mi)
{
	CheckDate();
	if(checkBefore == true)
		beforeNow = CheckIsBeforeNow();
}

void Date::setDate(unsigned int d, unsigned int m, unsigned int y, unsigned int h, unsigned int mi)
{
	day = d;
	month = m;
	year = y;
	hour = h;
	min = mi;

	CheckDate();
}

bool Date::operator<(const Date & obj) const noexcept
{
	if (year < obj.year) return true;
	else if (year > obj.year) return false;
	else
	{
		if (month < obj.month) return true;
		else if (month > obj.month) return false;
		else
		{
			if (day < obj.day) return true;
			else if (day > obj.day) return false;
			else
			{
				if (hour < obj.hour) return true;
				else if (hour > obj.hour) return false;
				else
				{
					if (min < obj.min) return true;
					else if (min > obj.min) return false;
				}

			}
		}
	}

	return false;
}

bool Date::isBeforeNow()
{
	CheckIsBeforeNow();

	return beforeNow;
}

//std::string Date::ShowRemaining() const //need to be refactored
//{
//	time_t t = time(0);
//	tm local;
//	localtime_s(&local, &t);
//
//	Date currentDate(local.tm_mday, local.tm_mon + 1, local.tm_year + 1900, local.tm_hour, local.tm_min, false);
//
//	std::string temp = "";
//	bool needMultiEnding = false;
//
//	if (abs(year, currentDate.year) > 0)
//	{
//		if(abs(year, currentDate.year > 1)) needMultiEnding = true;
//		temp += std::to_string(abs(currentDate.year, year)) + " year";
//	}
//	else if (abs(month, currentDate.month) > 0)
//	{
//		if (abs(month, currentDate.month > 1)) needMultiEnding = true;
//		temp += std::to_string(abs(currentDate.month, month)) + " month";
//	}
//	else if (abs(day, currentDate.day) > 0)
//	{
//		if (abs(day, currentDate.day > 1)) needMultiEnding = true;
//		temp += std::to_string(abs(currentDate.day, day)) + " day";
//	}
//	else if (abs(hour, currentDate.hour) > 0)
//	{
//		if (abs(hour, currentDate.hour > 1)) needMultiEnding = true;
//		temp += std::to_string(abs(currentDate.hour, hour)) + " hour";
//	}
//	else if (abs(min, currentDate.min) > 0)
//	{
//		if (abs(min, currentDate.min > 1)) needMultiEnding = true;
//		temp += std::to_string(abs(currentDate.min, min)) + " minute";
//	}
//
//	if (needMultiEnding) temp += "s";		//more than 2 year,days etc.
//	if (currentDate < *this) temp += " remaining";
//	else temp += " deleayed";				//exacly the same time means "delayed"!
//
//	
//	return temp;
//}

std::string Date::ShowDayDate() const noexcept
{
	std::string	strDayDate = "";
	if (day < 10) strDayDate += '0';
	strDayDate += std::to_string(day) + '.';
	if (month < 10) strDayDate += '0';
	strDayDate += std::to_string(month) + '.' + std::to_string(year);

	return strDayDate;
}

std::string Date::ShowHourDate(bool system12h) const noexcept
{
	std::string strHourDate = "";
	if (!system12h)
	{
		if (hour < 10) strHourDate += '0';
		strHourDate += std::to_string(hour);
	}
	else
	{
		int tempHour = hour;
		if (hour > 12) tempHour -= 12;
		if (hour < 10) strHourDate += '0';
		strHourDate += std::to_string(tempHour);
	}

	strHourDate += ":";

	if(min < 10) strHourDate += '0';
	strHourDate += std::to_string(min);

	return strHourDate;

}

std::string Date::ShowFullDate(bool system12h) const noexcept
{
	return  ShowDayDate() + " " +ShowHourDate(system12h);
}

std::string Date::FullDateForSave() const noexcept
{
	return std::to_string(day) + ' ' + std::to_string(month) + ' ' + std::to_string(year)+
			' ' + std::to_string(hour) + ' ' + std::to_string(min);
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
	if (hour < 0 || hour > 24) throw BadNumbersInDate("Date.hour is not between <1,24>.");
	if (min < 0 || min > 60) throw BadNumbersInDate("Date.min is not between <1,60>");
}

bool Date::CheckIsBeforeNow() const
{
	time_t t = time(0);
	tm local;
	localtime_s(&local, &t);

	Date currentDate(local.tm_mday, local.tm_mon + 1, local.tm_year + 1900, local.tm_hour, local.tm_min, false);

	//std::clog << currentDate.ShowFullDate(); //debug message

	return (currentDate < *this);
}
