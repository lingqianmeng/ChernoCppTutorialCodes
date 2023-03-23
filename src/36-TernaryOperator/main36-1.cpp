#include<iostream>
#include<string>

static int s_Level = 10;
static int s_Speed = 0;

int main()
{
	
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;
	
	// equals to this:
	s_Speed = s_Level > 5 ? 10 : 5;

	std::string rank = s_Level > 5 ? "Master" : "Beginner";

	std::cout << s_Speed << std::endl;
	std::cout << rank << std::endl;

	std::cin.get();
}