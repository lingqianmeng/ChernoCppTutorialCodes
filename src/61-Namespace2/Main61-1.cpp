#include<iostream>
#include<string>

/* Namespace is used to avoid naming conflicts. 
*/

namespace apple {

	void Print(const char* text)
	{
		std::cout << text << std::endl;
	}
}

namespace orange {

	void Print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}
/*
* Now the both Print() have the same type of inputs and same names.
*/
using namespace apple;
using namespace orange;

int main()
{
	// Now the Print function can not be called without specify namespace infront of it. 
	Print("Hello");

	// This still works
	apple::Print("Hello");
	orange::Print("Hello");

	std::cin.get();
}