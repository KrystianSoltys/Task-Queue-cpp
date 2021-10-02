#pragma once
#include "task.h"
#include <string>
#include <vector>


namespace INFO
{
	const std::string VERSION = "PreAlpha";
	const std::string PRODUCER = "Intelek";
	const std::string HEADLINE = "----------Task Queue App----------\n\n";
	const std::string CONTACT = "intelektft@gmail.com";
}


int MainMenu();
void About();
void TaskList(std::vector<Task>& vec);
size_t VirtualSetTask(std::vector<Task>& vec, Task::StatusEnum en); //used in every set task function

//Producer
int ProducerMenu();
void SetTaskCompleted (std::vector<Task>& vec);
void SetTaskAwaiting  (std::vector<Task>& vec);
void SetTaskCantbedone(std::vector<Task>& vec);

//Cutomer
int CustomerMenu();
void AddTask(std::vector<Task>& vec);
void DeleteTask(std::vector<Task>& vec);
void EditTask(std::vector<Task>& vec);

