#pragma once
#include "date.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <vector>


class Task
{
public:
	enum Status {COMPLETED, AWAITING, CANTBEDONE, TIMEISUP};


private:

	std::string name;
	std::string desc;
	Status taskStatus;
	Date quest_date;

};