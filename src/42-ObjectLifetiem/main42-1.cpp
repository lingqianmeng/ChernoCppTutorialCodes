#include<iostream>
#include<string>

/*
* The object on stack will be destroyed automaticlly out of scoupe.
* The object on heap will not be destroyed out of scoupe. 
*/

class Entity 
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

int main()
{
	/**
	* both created and destroyed showed up.  
	*/
	std::cout << "create object on stack..." << std::endl;
	{
		Entity e;
	}

	/*
	* only created showed up. 
	*/
	std::cout << "create object on heap..." << std::endl;
	{
		Entity* e = new Entity;
	}

	std::cin.get();
}