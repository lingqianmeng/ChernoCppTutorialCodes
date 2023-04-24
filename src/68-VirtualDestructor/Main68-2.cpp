#include<iostream>

/*
	Demonstrates how virtual destructor helps destruct a polymorphic type object.
*/

class Base
{
public:
	Base() { std::cout << "Constructor Base" << std::endl; }
	virtual ~Base() { std::cout << "Destructor Base" << std::endl; } // add virtual in front of base class destructor.
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
	delete poly;				// Destructor derived was now called... -> No more Memory Leaking.

	std::cin.get();
}