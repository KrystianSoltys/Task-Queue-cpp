#include "pch.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int MainMenu();
void About();
int ProducerMenu();
int CustomerMenu();



int MainMenu()
{
	using std::cout;
	using std::endl;

	int x;
	system("cls");

	cout << INFO::HEADLINE;
	cout << "Select module:\n";
	cout << "[1] Producer\n";
	cout << "[2] Customer\n\n";
	cout << "[3] About\n";
	cout << "[4] Exit\n";
	//while (std::cin.get() != '\n') continue;
	std::cin >> x;

	return x;
}

void About()
{
	using std::cout;
	using std::endl;

	system("cls");

	cout << INFO::HEADLINE;
	cout << "Version: " << INFO::VERSION;
	cout << "\nProducer: " << INFO::PRODUCER;
	cout << endl;
	while (std::cin.get() != '\n') continue;
	std::cin.get();
}

int ProducerMenu()
{
	
	using std::cout;
	using std::endl;

	int x;
	system("cls");

	cout << INFO::HEADLINE;
	cout << "Select action:\n";
	cout << "[1] Set task 'completed'\n";
	cout << "[2] Set task 'awaiting'\n";
	cout << "[3] Mark task as 'can't be done'\n";
	cout << "[4] Show all tasks\n\n";

	cout << "[0] Exit program\n" << endl;

	std::cin >> x;

	return x;
}


int CustomerMenu()
{
	using std::cout;
	using std::endl;

	int x;
	system("cls");

	cout << INFO::HEADLINE;
	cout << "Select action:\n";
	cout << "[1] Add Task\n";
	cout << "[2] Remove Task\n";
	cout << "[3] Edit Task\n";
	cout << "[4] Show all tasks\n\n";

	cout << "[0] Exit program\n" << endl;

	std::cin >> x;

	return x;
}



size_t VirtualSetTask(std::vector<Task>& vec, Task::StatusEnum en)
{
	//std::sort(vec.begin(), vec.end()); //probably not good idea

	system("cls");
	std::cout << INFO::HEADLINE;
	std::cout << "Choose task from list:\n\n";

	size_t ct = 1;
	int choice;

	for (auto& i : vec)
	{
		std::cout << "(" << ct++ << ") " << i << "\n";
	}

	std::cout << std::endl << "Provide number of ";
	switch (en)
	{
	case Task::COMPLETED:
		std::cout << "'Completed'";
		break;
	case Task::AWAITING:
		std::cout << "'Awaiting'";
		break;
	case Task::CANTBEDONE:
		std::cout << "'Can't be done'";
		break;
	case Task::TIMEISUP:
		std::cout << "'Time is up'";
		break;
	default:
		std::cout << "'Unknown'";
		break;
	}
	std::cout << " Task (0 to cancel): ";


	while (std::cin >> choice, (choice < 0 || choice > vec.size()))
	{
		system("cls");
		std::cout << INFO::HEADLINE;
		std::cout << "Choose task from list:\n\n";

		ct = 1;
		for (auto& i : vec)
		{
			std::cout << "(" << ct++ << ") " << i << "\n";
		}

		std::cout << std::endl << "Provide correct number of ";
		switch (en)
		{
		case Task::COMPLETED:
			std::cout << "'Completed'";
			break;
		case Task::AWAITING:
			std::cout << "'Awaiting'";
			break;
		case Task::CANTBEDONE:
			std::cout << "'Can't be done'";
			break;
		case Task::TIMEISUP:
			std::cout << "'Time is up'";
			break;
		default:
			std::cout << "'Unknown'";
			break;
		}
		std::cout << " Task (0 to cancel): ";
	}

	return choice;
}


void SetTaskCompleted(std::vector<Task>& vec)
{
	int x = VirtualSetTask(vec, Task::COMPLETED);
	if (x > 0)
	{
		vec.at(x - 1).setStatus(Task::COMPLETED);
	}
}

void SetTaskAwaiting(std::vector<Task>& vec)
{
	int x = VirtualSetTask(vec, Task::AWAITING);
	if (x > 0)
	{
		vec.at(x - 1).setStatus(Task::AWAITING);
	}
}

void SetTaskCantbedone(std::vector<Task>& vec)
{
	int x = VirtualSetTask(vec, Task::CANTBEDONE);
	if (x > 0)
	{
		vec.at(x - 1).setStatus(Task::CANTBEDONE);
	}
}


void TaskList(std::vector<Task>& vec)
{
	//std::sort(vec.begin(), vec.end()); //probably not good idea

	system("cls");
	std::cout << INFO::HEADLINE;
	std::cout << "List of tasks\n\n";

	size_t ct = 1;
	for (auto& i : vec)
	{
		std::cout << "(" << ct++ << ") " << i << "\n";
	}

	while (std::cin.get() != '\n') continue;
	std::cin.get();
}


void AddTask(std::vector<Task>& vec)
{
	using std::cout;
	using std::cin;
	using std::endl;

	std::string name, description;
	unsigned int day, month, year, hour, min;

	system("cls");
	cout << INFO::HEADLINE;

	while (std::cin.get() != '\n') continue;
	cout << "Enter task name: ";
	std::getline(cin, name);
	cout << "Enter task description: ";
	std::getline(cin, description);
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter hour: ";
	cin >> hour;
	cout << "Enter minute: ";
	cin >> min;

	vec.push_back(Task(name, description, Task::AWAITING, Date(day, month, year, hour, min)));

	std::sort(vec.begin(), vec.end());
}

void DeleteTask(std::vector<Task>& vec)
{
	system("cls");
	std::cout << INFO::HEADLINE;
	std::cout << "Choose task from list:\n\n";

	size_t ct = 1;
	int choice;

	for (auto& i : vec)
	{
		std::cout << "(" << ct++ << ") " << i << "\n";
	}

	std::cout << std::endl << "Provide number of removing Task (0 to cancel): ";
	while (std::cin >> choice, (choice < 0 || choice > vec.size()))
	{
		system("cls");
		std::cout << INFO::HEADLINE;
		std::cout << "Choose task from list:\n\n";

		ct = 1;
		for (auto& i : vec)
		{
			std::cout << "(" << ct++ << ") " << i << "\n";
		}

		std::cout << std::endl << "Provide correct number of removing Task(0 to cancel): ";
	}

	if (choice > 0)
	{
		vec.erase(vec.begin() + (choice - 1));
	}

	std::sort(vec.begin(), vec.end());
}

void EditTask(std::vector<Task>& vec)
{
	using std::cout;
	using std::cin;

	system("cls");
	cout << INFO::HEADLINE;
	cout << "Choose task from list:\n\n";

	size_t ct = 1;
	int choice;

	for (auto& i : vec)
	{
		cout << "(" << ct++ << ") " << i << "\n";
	}

	cout << std::endl << "Provide number of editing Task (0 to cancel): ";
	while (cin >> choice, (choice < 0 || choice > vec.size()))
	{
		system("cls");
		cout << INFO::HEADLINE;
		cout << "Choose task from list:\n\n";

		ct = 1;
		for (auto& i : vec)
		{
			cout << "(" << ct++ << ") " << i << "\n";
		}

		cout << std::endl << "Provide correct number of editing Task(0 to cancel): ";
	}

	std::string name, description, status;
	unsigned int day, month, year, hour, min;
	Task::StatusEnum en;

	system("cls");
	std::cout << INFO::HEADLINE;
	std::cout << vec[choice - 1] << std::endl;

	while (std::cin.get() != '\n') continue;
	cout << "Enter task name: ";
	std::getline(cin, name);
	cout << "Enter task description: ";
	std::getline(cin, description);
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter hour: ";
	cin >> hour;
	cout << "Enter minute: ";
	cin >> min;
	cout << "Enter status ('Awaiting', 'Cantbedone', 'Completed', 'Timeisup') : ";
	std::cin >> status;
	for (auto& i : status)
	{
		i = tolower(i);			//TimeIsUp -> timeisup
	}
	if (status == "cantbedone")		en = Task::CANTBEDONE;
	else if (status == "completed") en = Task::COMPLETED;
	else if (status == "timeisup")	en = Task::CANTBEDONE;
	else							en = Task::AWAITING;

	vec[choice - 1] = Task(name, description, en, Date(day, month, year, hour, min));

	std::sort(vec.begin(), vec.end());
}
