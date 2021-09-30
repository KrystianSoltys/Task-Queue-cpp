#include "pch.h"
#include "ui.h"
#include <iostream>
#include <string>
#include <algorithm>

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

void SetTaskCompleted()
{
	using std::cout;
	using std::endl;

	int x;
	system("cls");

	cout << INFO::HEADLINE;
	tsk.setStatus(Task::COMPLETED); //TODO
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

void TaskList(std::vector<Task>& vec)
{
	std::sort(vec.begin(), vec.end()); //probably not good idea

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

