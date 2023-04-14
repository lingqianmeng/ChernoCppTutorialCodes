#include<iostream>

/*
*	Demonstrate how to define a function pointer and when to use it. 
*/

void HelloWorld()
{
	std::cout << "Hello World" << std::endl;
}

void HelloWorld2(std::string who)
{
	std::cout << "Hello World to: "<< who << std::endl;
}

void HelloWorld3(std::string country)
{
	std::cout << "Greetings from: " << country << std::endl;
}

void Location_Italia(std::string who)
{
	std::cout << "Hi! " << who << ",I would like to go to Italia." << std::endl;
}

void Location_Tirol(std::string who)
{
	std::cout << "Hi! " << who << ",I would like to go to Tirol." << std::endl;
}

void Time_May()
{
	std::cout << "I want to have my vacation in May." << std::endl;
}

void Time_July()
{
	std::cout << "I want to have my vacation in July." << std::endl;
}

void Plan(std::string name, void(*Location)(std::string), void(*Time)()) 
{
	Location(name);
	Time();
}

int main()
{
	// --- function pointer : easy ---
	// The type of it could be created by using 'auto'
	auto func = HelloWorld;
	func();

	// --- function pointer : with inputs ---
	auto func2 = HelloWorld2;
	func2("Lingqian");

	// define a func pointer by the type is void (*foo) ()
	void (*func3)(std::string) = HelloWorld3;
	func3("Italia");

	// functions as parameters can be now fed into another function
	Plan("Antonio", Location_Italia, Time_May);
	Plan("Markus", Location_Tirol, Time_July);

	std::cin.get();
}