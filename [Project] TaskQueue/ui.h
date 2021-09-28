#pragma once
#include <iostream>

namespace INFO
{
	const std::string VERSION = "PreAlpha";
	const std::string PRODUCER = "Intelek";
	const std::string HEADLINE = "----------Task Queue App----------\n\n";
}


int MainMenu();
void About();
int ProducerMenu();
int CustomerMenu();
