#include<iostream>
#include<string>

/*Show what virtual function can do -> To make overloaded functions do the work in a polymorphism situation.*/

// Inheretance classes without using virtual function
class Entity
{
public:
	std::string GetName() { return "Entity"; }
};

class Player :public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name)
		: m_Name(name) {}
	std::string GetName() { return m_Name; }
};

void FunctionGetName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}

// Solution: Use virtual functions in class.
class Entity_V
{
public:
	virtual std::string GetName() { return "Entity"; } // 1. Mark the function with virtual in base class. So it can be overrided.
};

class Player_V :public Entity_V
{
private:
	std::string m_Name;
public:
	Player_V(const std::string& name)
		: m_Name(name) {}
	std::string GetName() override { return m_Name; } // 2. Mark the function in sub class with override. It is optional though, but strongly recommended. It is better for reading and understanding.
};

void FunctionGetName(Entity_V* entity)
{
	std::cout << entity->GetName() << std::endl;
}

void PrintSpalter(const std::string& spalter)
{
	std::cout << "-------" << spalter << "-------" << std::endl;
}

int main()
{
	Entity* e = new Entity();
	Player* p = new Player("Lingqian");

	std::cout << e->GetName() << std::endl;  // 'Entity'
	std::cout << p->GetName() << std::endl;	 // 'Lingqian'

	PrintSpalter("Problem: Polymorphism");

	/*
	* Problem: Polymorphism, or multi types. 
	*/
	Entity* e1 = p;
	std::cout << e1->GetName() << std::endl; // 'Entity' instead of my name will be printed

	// Same as using following function
	FunctionGetName(e);						// 'Entity' 
	FunctionGetName(p);						// 'Entity' instead of my name will be printed

	delete e, p, e1;

	PrintSpalter("Solution: virtual functions in class");

	/*
	* Solution: virtual functions in class
	*/
	Entity_V* e_v = new Entity_V();
	Player_V* p_v= new Player_V("Lingqian");

	FunctionGetName(e_v);						// 'Entity' 
	FunctionGetName(p_v);						// 'Lingqian'

	delete e_v, p_v;

	std::cin.get();
}