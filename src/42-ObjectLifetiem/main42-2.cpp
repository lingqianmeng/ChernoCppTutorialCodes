#include<iostream>
#include<string>

/*
* With using smart pointer or scouped pointer the object will be created on heap and destroyed wenn its ever finished.
*/

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	// destructor
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

// one basic scoped pointer
class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		:m_Ptr(ptr) {}
	~ScopedPtr()
	{
		delete m_Ptr;
	}
};

int main()
{
	std::cout << "create object on heap..." << std::endl;
	{
		Entity* e = new Entity;
	}

	std::cout << "create object on heap but using scouped pointer..." << std::endl;
	{
		ScopedPtr e(new Entity());
		//ScopedPtr e(Entity * e); // it won't work. Must be using 'new'
	}

	std::cin.get();
}