#include<iostream>
#include<string>

/*
* 'This' could be used to help constructor to initiate objects.
* 
*/

// declare function
void PrintEntity(Entity* e);

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
		: x(x), y(y) {}

	// solution 1:
	Entity(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

	// solution 2: 
	Entity(int x, int y)
	{
		(*this).x = x;
		(*this).y = y;
	}

	int GetX() const
	{
		const Entity* e = this;
		return e->x;
	}
};

void PrintEntity(Entity* e)
{
	
}

int main() 
{
	std::cin.get();
}