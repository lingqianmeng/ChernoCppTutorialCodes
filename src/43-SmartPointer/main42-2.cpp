#include<iostream>
#include<string>
#include<memory>

/*
* Demonstrate Shared Pointer and Weak Pointer.
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

	void print()
	{}
};


int main()
{
	std::cout << "create object on heap using Shared Pointer..." << std::endl;
	{
		std::shared_ptr<Entity> e;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e = sharedEntity;
		}
	} // In Debug: the pointer will not be destroyed until hit here. Because 'e' still the last referance to it. 

	std::cout << "create object on heap using Weak Pointer..." << std::endl;
	{
		std::weak_ptr<Entity> e;
		{
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
			e = sharedEntity;
		} // In Debug: the pointer will be destroyed once out of the first scope. Because 'e' a weak pointer.  
	}

	std::cin.get();
}