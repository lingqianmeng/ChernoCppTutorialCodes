#include<iostream>
#include<string>

/**
*	Funciton overloading without having templates
*/

void Print(int value)
{
	std::cout << value << std::endl;
}

void Print(float value)
{
	std::cout << value << std::endl;
}

void Print(std::string value)
{
	std::cout << value << std::endl;
}

int main()
{
	Print(5);
	Print(5.5f);
	Print("Hello World");
	std::cin.get();
}