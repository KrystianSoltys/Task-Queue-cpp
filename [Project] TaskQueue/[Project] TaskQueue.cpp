#include "pch.h"
#include "ui.h"
#include "task.h"
#include "date.h"
#include <iostream>
#include <ctime>
#include <vector>

int main()
{
	try {


		std::vector<Task> tab;

		tab.push_back(Task("Appointment", "Make a nice appointment", Task::StatusEnum::AWAITING, Date(2, 10, 2021, 15, 0)));
		tab.push_back(Task("TODO App", "Make a great TODO App", Task::StatusEnum::COMPLETED, Date(1, 10, 2021, 19, 30)));
		tab.push_back(Task("Install app", "Install internet browser", Task::StatusEnum::AWAITING, Date(3, 10, 2021, 15, 20)));
		tab.push_back(Task("Write poem", "Stop writing in C++, write a poem", Task::StatusEnum::CANTBEDONE, Date(4, 10, 2021, 20, 0)));



		int choice;



		while (choice = MainMenu(), (choice != 0))
		{
			switch (choice)
			{
			case 1: //entered to producent menu
				while (choice = ProducerMenu(), choice != 0)
				{
					switch (choice)
					{
					case 1:
						//todo
						break;
					case 2:
						//todo
						break;
					case 3:
						//todo
						break;
					case 4:
						TaskList(tab);
						break;
					default:
						break;
					}
				}
				std::exit(0);

			case 2: //entered to customer menu
			{
				while (choice = CustomerMenu(), choice != 0)
				{
					switch (choice)
					{
					case 1:
						//todo
						break;
					case 2:
						//todo
						break;
					case 3:
						//todo
						break;
					case 4:
						TaskList(tab);
						break;
					default:
						break;
					}
				}
				std::exit(0);
			}
			case 3: //entered about
				About();
			default:
				break;
			}

		}


	}
	catch (Date::BadNumbersInDate& exc)
	{
		std::clog << "Exception caught: " << exc.what() << std::endl
			<< "Please, contact us: " << INFO::CONTACT << std::endl;
		std::exit(EXIT_FAILURE);
	}
	catch (std::exception& exc)
	{
		std::clog << exc.what();
		std::exit(EXIT_FAILURE);
	}
	return 0;
	
}
