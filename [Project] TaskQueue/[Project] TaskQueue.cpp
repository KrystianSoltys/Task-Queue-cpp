#include "pch.h"
#include <iostream>
#include "task.h"
#include <ctime>

int main()
{

	Task x("Appointment", "Make a nice appointment", Task::StatusEnum::AWAITING, Date(10, 4, 2002, 15, 0));
	Task y("TODO App", "Make a great TODO App", Task::StatusEnum::COMPLETED, Date(30, 9, 2021, 19, 30));

	std::cout << x << "\n" << y;
	return 0;
	
}
