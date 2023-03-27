#include<iostream>
#include<string>
#include<memory>

/*
* Demonstrate using Unique pointer. Pointer exists not any more once out of scope.
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

	std::cout << "create object on heap using Unique Pointer..." << std::endl;
	{
		std::unique_ptr<Entity> e(new Entity);
		e->print();
	}

	std::cout << "create object on heap using Unique Pointer with regard to exception safety..." << std::endl;
	{
		std::unique_ptr<Entity> e = std::make_unique<Entity>();
		e->print();
	}

	// you can not copy an Unique Pointer like:
	{
		std::unique_ptr<Entity> e(new Entity);
		std::unique_ptr<Entity> e1 = e; // this will not compile... So that we need shared pointer
	}

	std::cin.get();
}