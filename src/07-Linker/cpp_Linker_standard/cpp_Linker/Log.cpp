#include<iostream>
#include"Log.h"

void InitialLog()
{
	Log("Initial Logging");
}

void Log(const char* message)
{
	std::cout << message << std::endl;
}