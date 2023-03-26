#include<iostream>
#include<string>

/*
* Functions are outside of construct or classes.
*/

// declare functions
void PrintEntity(Entity* e);
void PrintEntity(const Entity& e);

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

		Entity& e = *this;

		PrintEntity(this); // this is a pointer
		PrintEntity(*this); // dereference this 
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

void PrintEntity(const Entity& e)
{

}

int main()
{
	std::cin.get();
}