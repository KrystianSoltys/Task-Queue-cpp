#include "pch.h"
#include <iostream>
#include "date.h"

int main()
{
	try
	{
		Date x(31, 3, 2004, 17, 24);
		std::cout << x.ShowFullDate();
	}
	catch (const Date::BadNumbersInDate& exc)
	{
		std::cerr <<exc.what();
		return 0;
	}
	catch (const std::exception& exc)
	{
		std::cerr << exc.what();
		return 0;
	}
	
	int y;
	std::cin >> y;

	
}
