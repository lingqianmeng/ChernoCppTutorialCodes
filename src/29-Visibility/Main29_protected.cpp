#include<iostream>

/*Show how protected in class works*/

class Entity
{
protected:		// Make it protected. Can be accessed from class itsself and its friends and sub classes. 
	int x, y;
	void Print() {}
public:
	Entity()
	{
		x = 0;
		Print(); // OK from class methods
	}
};

class Player : public Entity
{
public:
	Player()
	{
		x = 2; // OK from subclass
		Print(); // OK from subclass
	}
};

int main()
{
	Player p;
	p.x; // not OK 
	p.Print(); // not OK

}