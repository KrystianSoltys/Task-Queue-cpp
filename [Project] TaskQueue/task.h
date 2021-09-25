#pragma once

#include <string>
#include <vector>

struct Date
{
	unsigned short day;
	unsigned short month;
	unsigned short year;
	unsigned short hour;
	unsigned short min;

	Date(unsigned short d, unsigned short m, unsigned short y,
		unsigned short h, unsigned short mi) :
		day(d), month(m), year(y), hour(h), min(mi) noexcept {}

	
};

class Task
{
	std::string name;
	std::string desc;
	bool finished;
	
};