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
	* Second way to create an object: on Heap using pointer and key word "new"
	* if: the object is big. Because stack is always small.
	* and if: performance is not that necessary. Because allocation on heap slower than on stack.
	* Warning: do not forget to call delete after finish using an object.
	*/
	Entity* e;
	{
		Entity* entity = new Entity entity("Cherno"); // object allocation now on Heap, with using the key word "new"
		e = entity;
		std::cout << *entity.Getname() << std::endl;
		// equals to
		std::cout << entity->Getname() << std::endl; // arrow operator
	}
	std::cin.get();
	delet entity; // once the object was allocated on heap, it can not be destroyed by itsself, but manually.
}