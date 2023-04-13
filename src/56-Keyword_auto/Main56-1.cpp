#include<iostream>
#include<string>
#include<vector>

/*
* Keyword 'auto'
* exp.1: use auto to make code more readble by replacing complated type. 
* exp.2: use auto to reference variable/object by with &
*/

int main()
{
	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	// exp.1
	std::cout << "---Demonstrate keyword 'auto'---" << std::endl;

	for (auto it = strings.begin(); it != strings.end(); it++) // make code more readble
	{
		std::cout << *it << std::endl;
	}

	// exp.2
	std::cout << "---Demonstrate keyword 'auto' by using reference---" << std::endl;

	const auto& strings_auto = strings; // dont forget &. Otherwise it would be copy but not reference

	strings.push_back("Banana"); // put new element in 'strings' to see if any change on 'strings_auto'. To prove not copy but reference being done.

	for (auto it = strings_auto.begin(); it != strings_auto.end(); it++)
	{
		std::cout << *it << std::endl;
	}

	std::cin.get();
}