#include "pch.h"
#include "task.h"
#include <Windows.h>
#include <iomanip>

Task::Task(const std::string& nm, const std::string& desc,
		   StatusEnum stat, const Date& dt) :
		name(nm), description(desc), taskStatus(stat), questDate(dt)
{
}

bool Task::operator<(const Task & obj) const noexcept
{
	return (this->questDate < obj.questDate);
}

void Task::setStatus(Task::StatusEnum en) noexcept
{
	taskStatus = en;
}

bool Task::isBeforeNow()
{
	return questDate.isBeforeNow();
}

std::ostream& operator<< (std::ostream& os, const Task& obj) //to rebuild, just for debug
{
	using std::cout;
	using std::endl;
	using std::setw;

	auto handleCon = GetStdHandle(STD_OUTPUT_HANDLE);
	os << std::left;
	switch (obj.taskStatus)
	{
	case Task::StatusEnum::COMPLETED:
		{
			SetConsoleTextAttribute(handleCon, 10);
			os << setw(20) << obj.name << "\t" << setw(40) << obj.description 
				<< "\t(Completed)\t" << obj.questDate.ShowFullDate();
			break;
		}
	case Task::StatusEnum::AWAITING:
	{
		SetConsoleTextAttribute(handleCon, 14);
		os << setw(20) << obj.name << "\t" << setw(40) << obj.description
			<< "\t(Awaiting)\t" << obj.questDate.ShowFullDate();
		break;
	}
	case Task::StatusEnum::CANTBEDONE:
	{
		SetConsoleTextAttribute(handleCon, 13);
		os << setw(20) << obj.name << "\t" << setw(40) << obj.description
			<< "\t(Can't be done)\t" << obj.questDate.ShowFullDate();
		break;
	}
	case Task::StatusEnum::TIMEISUP:
	{
		SetConsoleTextAttribute(handleCon, 12);
		os << setw(20) << obj.name << "\t" << setw(40) << obj.description
			<< "\t(Time is up)\t" << obj.questDate.ShowFullDate();
		break;
	}
	default:
		break;
	}

	SetConsoleTextAttribute(handleCon, 7); //should change to prev
	 
	return os;
}