#pragma once

#include <exception>
#include <string>

const int MonthsArr[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isLeapYear(int year);
int abs(int x);


class Date
{
public:

	class BadNumbersInDate : public std::exception
	{
	public:
		BadNumbersInDate(const char* str) : std::exception(str) {}
		virtual char const* what() const { return std::exception::what(); }
	};

	Date
	(unsigned int d = 1, unsigned int m = 1, unsigned int y = 2000,
	 unsigned int h = 0, unsigned int mi = 0, bool checkBefore = true);
	
	void setDate
	(unsigned int d = 1, unsigned int m = 1, unsigned int y = 2000,
	 unsigned int h = 0, unsigned int mi = 0);

	bool operator< (const Date& obj) const noexcept;
	bool isBeforeNow();

	//std::string ShowRemaining() const; //need to count propertly
	std::string ShowDayDate() const noexcept;
	std::string ShowHourDate(bool system12h = false) const noexcept;
	std::string ShowFullDate(bool system12h = false) const noexcept;



private:
	unsigned int day;
	unsigned int month;
	unsigned int year;
	unsigned int hour;
	unsigned int min;
	bool beforeNow;

	void CheckDate() const; //throws exception if date elements are not valid
	bool CheckIsBeforeNow() const;
};
