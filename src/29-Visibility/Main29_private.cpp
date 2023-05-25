#include<iostream>

/*Show how private in class works*/

class Entity
{
private:		// Make it private. Only can be accessed from class itsself and its friends.
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
		x = 2; // not OK from subclass
		Print(); // not OK from subclass
	}
};

int main()
{
	Player p;
	p.x; // not OK 
	p.Print(); // not OK

}