#include "pch.h"
#include <iostream>
#include "task.h"
#include <ctime>

int main()
{

	Date x(10, 4, 2021, 14, 56);

	std::cout << x.isBeforeNow();

	return 0;
	
}
