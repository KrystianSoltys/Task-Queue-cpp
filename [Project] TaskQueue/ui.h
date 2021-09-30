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

//Producer
int ProducerMenu();
void SetTaskCompleted(Task& tsk);

//Cutomer
int CustomerMenu();

