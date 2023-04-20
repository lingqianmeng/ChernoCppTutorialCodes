#include <iostream>
#include <chrono>
#include <thread>

/*
* This demonstrates how to realize a timer function, to see how much time will be needed to run through of one function.
*/

struct Timer
{
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;

	Timer()
		: duration(0.0f)
	{
		start = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;
		float ms = duration.count() * 1000.0f;
		std::cout << "Duration: " << ms << "s" << std::endl;
	}
};

void function()
{
	Timer timer; // Object lifetime: if out of brackets, the object timer will be destroyed. So the timer function realized. 

	for (int i = 0; i < 100; i++)
		std::cout << "Hello World!" << std::endl;
}

int main()
{
	function();

	std::cin.get();
}