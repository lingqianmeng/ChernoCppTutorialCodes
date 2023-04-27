#include<chrono>
#include<iostream>

/*
  Benchmark for C++ 
*/

class Timer
{
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
public:
	Timer()
	{
		m_StartTimepoint = std::chrono::high_resolution_clock::now();
	}

	~Timer()
	{
		Stop();
	}

	void Stop()
	{
		auto m_EndTimepoint = std::chrono::high_resolution_clock::now();
		
		auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
		auto end = std::chrono::time_point_cast<std::chrono::microseconds>(m_EndTimepoint).time_since_epoch().count();
		
		auto duration = end - start;
		double ms = duration * 0.001;

		std::cout << "Duration: " << duration << " us (" << ms << " ms)" << std::endl;
	}
};

int main()
{
	int value = 0;
	{
		// Attention: Release is other than debug. 
		//				In release mode no means to measure. See assembly. 
		Timer timer; 
		for (int i = 0; i < 1000000; i++)
		value += 2;
	}
	
	std::cout << value << std::endl;
}