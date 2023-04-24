#include<iostream>

/*
	Demonstrate how it is dangerous not to use virtual for base class destructor
*/

class Base
{
public:
	Base() { std::cout << "Constructor Base" << std::endl; }
	~Base() { std::cout << "Destructor Base" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Constructor Derived" << std::endl; }
	~Derived() { std::cout << "Destructor Derived" << std::endl; }
};

int main()
{
	Base* base = new Base();
	delete base;

	std::cout << "----------------" << std::endl;

	Derived* derived = new Derived;
	delete derived;

	std::cout << "----------------" << std::endl;

	Base* poly = new Derived;	// This is a polymorphic type of object. 
	delete poly;				// Destructor derived was missing... -> It leads to memory leaks.

	std::cin.get();
}