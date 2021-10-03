#include "pch.h"
#include "loader.h"
#include <fstream>
#include <algorithm>

const char* file = "data.txt";



void LoadData(std::vector<Task>& vec)
{
	std::ofstream createFile(file, std::ios_base::app); //weird way to avoid opening not existing file
	createFile.close();

	std::ifstream fin;
	fin.open(file, std::ios_base::in);
	if (!fin.is_open()) throw FileException("File opening failure");


	std::string name, description, status;
	unsigned int day, month, year, hour, min;
	Task::StatusEnum en;

	while (std::getline(fin, name))
	{	
		std::getline(fin, description);
		fin >> status;
		fin >> day >> month >> year >> hour >> min;
		if (status == "cantbedone")		en = Task::CANTBEDONE;
		else if (status == "completed") en = Task::COMPLETED;
		else if (status == "timeisup")	en = Task::CANTBEDONE;
		else							en = Task::AWAITING;

		vec.push_back(Task(name, description, en, Date(day, month, year, hour, min)));

		
	}

	fin.close();

	std::sort(vec.begin(), vec.end());
	SetTimeIsUp(vec);
}

void SaveData(std::vector<Task>& vec)
{
	using std::endl;

	SetTimeIsUp(vec);
	std::ofstream fout(file, std::ios_base::out);
	if (!fout.is_open())	throw FileException("File opening failure");

	for (const auto& i : vec)
	{
		fout << i.name << endl;
		fout << i.description << endl;
		switch (i.taskStatus)
		{
		case Task::AWAITING:
			fout << "awaiting";
			break;
		case Task::CANTBEDONE:
			fout << "cantbedone";
			break;
		case Task::COMPLETED:
			fout << "completed";
			break;
		case Task::TIMEISUP:
			fout << "timeisup";
		default:
			fout << "awaiting";
			break;
		}
		fout << " " << i.questDate.FullDateForSave();
	}

	fout.close();
}