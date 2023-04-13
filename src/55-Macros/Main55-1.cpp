#include<iostream>
#include<string>

/*
* Using Macros for Logging
*/

#define LOG(x) std::cout << x << std::endl;
int main()
{
	LOG("Hello World");
	std::cin.get();
}