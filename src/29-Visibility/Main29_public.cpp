#include<iostream>

/*Show how public in class works*/

class Entity
{
public:				// Almost from every where to access it. Class itsself, friends, sub classes and outside of classes. 
	int x, y;
	void Print() {}
public:
	Entity()
	{
		x = 0;
		Print();	// OK from class methods
	}
};

class Player : public Entity
{
public:
	Player()
	{
		x = 2;		// OK from subclass
		Print();	// OK from subclass
	}
};

int main()
{
	Player p;
	p.x;			// OK from outside of classes
	p.Print();		// OK from outside of classes

}