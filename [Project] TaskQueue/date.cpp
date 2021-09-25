#include "date.h"

bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0) //year validated in Date(struct) constructor
		return true;
	
	return false;
}

Date::Date(unsigned short d, unsigned short m, unsigned short y,
	unsigned short h, unsigned short mi) :
	day(d), month(m), year(y), hour(h), min(mi)
{
	CheckDate();
}