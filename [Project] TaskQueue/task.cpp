#include "pch.h"
#include "task.h"
#include <Windows.h>

Task::Task(const std::string& nm, const std::string& desc,
		   StatusEnum stat, const Date& dt) :
		name(nm), description(desc), taskStatus(stat), questDate(dt)
{
}

std::ostream& operator<< (std::ostream& os, const Task& obj) //to rebuild, just for debug
{
	using std::cout;
	using std::endl;

	HANDLE handleCon = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (obj.taskStatus)
	{
	case Task::StatusEnum::COMPLETED:
		{
			SetConsoleTextAttribute(handleCon, 10);
			os << obj.name << "\t" << obj.description << "\t(Completed)\t"
				<< obj.questDate.ShowFullDate();
			break;
		}
	case Task::StatusEnum::AWAITING:
	{
		SetConsoleTextAttribute(handleCon, 14);
		os << obj.name << "\t" << obj.description << "\t(Awaiting)\t"
			<< obj.questDate.ShowFullDate();
		break;
	}
	case Task::StatusEnum::CANTBEDONE:
	{
		SetConsoleTextAttribute(handleCon, 13);
		os << obj.name << "\t" << obj.description << "\t(Can't be done)\t"
			<< obj.questDate.ShowFullDate();
		break;
	}
	case Task::StatusEnum::TIMEISUP:
	{
		SetConsoleTextAttribute(handleCon, 12);
		os << obj.name << "\t" << obj.description << "\t(Time's up)\t"
			<< obj.questDate.ShowFullDate();
		break;
	}
	default:
		break;
	}

	SetConsoleTextAttribute(handleCon, 7); //should change to prev
	 
	return os;
}