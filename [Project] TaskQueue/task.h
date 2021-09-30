#pragma once
#include "date.h"
#include <iostream>
#include <string>
#include <vector>

class Task;

std::ostream& operator<< (std::ostream& os, const Task& obj);


class Task
{
public:
	enum StatusEnum {COMPLETED, AWAITING, CANTBEDONE, TIMEISUP};

	Task(const std::string& nm, const std::string& desc, StatusEnum stat,
		 const Date& dt);

	bool operator< (const Task& obj) const noexcept;
	void setStatus(Task::StatusEnum en = COMPLETED) noexcept;

	friend std::ostream& operator<< (std::ostream& os, const Task& obj);


private:

	std::string name;
	std::string description;
	StatusEnum taskStatus;
	Date questDate;

};

