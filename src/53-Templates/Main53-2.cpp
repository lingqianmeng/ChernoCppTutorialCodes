#include<iostream>
#include<string>

/**
*	Funciton overloading by using templates
*/

template<typename T>
// or
//template<class T> // class or typename, whatever

void Print(T value)
{
	std::cout << value << std::endl;
}

int main()
{
	Print(5); // What type we specified here in the function goes into the argument T.
	Print(5.5f);
	Print("Hello World");

	// or
	Print<int>(5); // What type we specified here in the function goes into the argument T.
	Print<float>(5.5f);
	Print<std::string>("Hello World");

	std::cin.get();
}