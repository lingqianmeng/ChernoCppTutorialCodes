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

	const String& Getname() const { return m_Name;  }
};

int main()
{
	Entity e; // constructor 1
	std::cout << e.Getname() << std::endl;
	std::cin.get();
}