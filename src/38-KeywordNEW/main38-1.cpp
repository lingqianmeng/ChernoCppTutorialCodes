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
	* after creating variables and objects with NEW on heap. You must be using delete to free the memories. 
	*/
	int a = 2;
	int* b = new int;
	int* c = new int[50]; // 200 bytes
	Entity* e = new(c) Entity; // assign pointer c to the Entity Pointer e to allocate 200 bytes memory for the object.

	delete b;
	delete[] c;

	/*
	* new vs. malloc
	*/
	Entity* e1 = new Entity(); // the constructor of this class will be called and object will be allocated on heap
	Entity* e2 = (Entity*)malloc(sizeof(Entity)); // constructor will not be called. Just allocated.

	std::cin.get();
}