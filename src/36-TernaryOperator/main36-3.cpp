#include<iostream>
#include<string>

static int s_Level = 20;
static int s_Speed = 0;

int main()
{
	if (s_Level > 5)
	{
		if (s_Level > 10)
			s_Speed = 15;
		else
			s_Speed = 10;
	}
	else
		s_Speed = 5;

	// equals to this: 
	// nested expression:
	// try 1, 6, 12, 20, 101
	s_Speed = s_Level > 5 && s_Level < 100 ? s_Level > 10 ? 15 : 10 : 5; 
	// equals to:
	s_Speed = (s_Level > 5 && s_Level < 100) ? s_Level > 10 ? 15 : 10 : 5; 

	std::string rank = s_Level > 5 && s_Level < 100 ? s_Level > 10 ? "Outlawer" : "Master" : "Beginner"; // try 101 for example

	std::cout << s_Speed << std::endl;
	std::cout << rank << std::endl;

	std::cin.get();
}