#include<iostream>
#include<thread>

static bool s_Finisched = false;

void DoWork()
{
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;
	while (!s_Finisched)
	{
		std::cout << "Working...\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void DoStudy()
{
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;
	while (!s_Finisched)
	{
		std::cout << "Studying...\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void DoPlay()
{
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;
	while (!s_Finisched)
	{
		std::cout << "Playing...\n";
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

void main()
{
	// multi threads
	std::thread worker(DoWork);
	std::thread student(DoStudy);
	std::thread player(DoPlay);

	std::cin.get();
	s_Finisched = true;

	// The completion of the thread identified by *this synchronizes with the corresponding successful return from join(). 
	worker.join();
	student.join();
	player.join();

	std::cout << "Finished." << std::endl;
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	std::cin.get();
}