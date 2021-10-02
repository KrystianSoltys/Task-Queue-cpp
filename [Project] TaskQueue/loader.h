#pragma once
#include "task.h"
#include <vector>


class FileException : std::exception
{
public:
	FileException(const char* str) : std::exception(str) {}
	virtual const char* what() const { return std::exception::what(); }
};


void LoadData(std::vector<Task>& vec);
void SaveData(std::vector<Task>& vec);