#include<iostream>
#include<string>

/* Demonstrate why you should not use namespace everywhere
*/

namespace apple {

	void Print(const std::string& text)
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

// you can put using namespace out of main, or in one spectacular function
// Don't ever put using namespace into a header file. Said Cherno.
using namespace apple;
using namespace orange;

int main()
{
	// "olleH" got printed
	Print("Hello");

	// instead of this, using this:
	apple::Print("Hello");
	orange::Print("Hello");

	std::cin.get();
}