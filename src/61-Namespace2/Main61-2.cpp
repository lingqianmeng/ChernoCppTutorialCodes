#include<iostream>
#include<string>

/* Demonstrate nested namespace and how to use it.
*/

// nested namespace
namespace apple {
	namespace functions {
		void Print(const char* text)
		{
			std::cout << text << std::endl;
		}
	}

	namespace utilites {}
}

namespace orange {

	void Print(const char* text)
	{
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}


int main()
{
	namespace a = apple::functions;
	// This will help wenn you have nested namespace
	a::Print("Hello");
	orange::Print("Hello");

	std::cin.get();
}