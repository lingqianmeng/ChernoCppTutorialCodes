#include<iostream>
#include<string>

using String = std::string;

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& Getname() const { return m_Name; }
};

int main()
{
	/*
	* First way to create an object: on Stack 
	* if: the object is small. Because stack is always small.
	* and if: performance is necessary. Because allocation on heap slower than on stack.
	* delete object after is not necessary. It will be gone from stack if out of scope. 
	*/
	Entity* e;
	{
		Entity entity("Cherno"); // object allocation now on Stack
		e = &entity;
		std::cout << entity.Getname() << std::endl;
	} // the entity object will be gone from stack after end of scope.
	std::cin.get();
}