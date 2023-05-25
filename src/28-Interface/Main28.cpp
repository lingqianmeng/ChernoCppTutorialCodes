#include<iostream>
#include<string>

/* Show what interface can do in c++. */

class Printable // this the interface
{
public:
	virtual std::string GetClassName() = 0; // mark this function to be PURE virtual function. No implementation at all. 
};

class Entity : public Printable
{
public:
	std::string GetClassName() override { return "Entity"; }  // sub class from this interface must have all pure virtual functions in the interface.
};

class Player : public Printable
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}
	std::string GetClassName() override { return "Player"; }  // sub class from this interface must have all pure virtual functions in the interface.
};

void FunctionGetName(Printable* obj)
{
	std::cout << obj->GetClassName() << std::endl;
}


int main()
{
	Entity* e = new Entity();
	Player* p = new Player("Lingqian");

	FunctionGetName(e);	 // 'Entity'
	FunctionGetName(p);	 // 'Player'

	delete e, p;

	std::cin.get();
}