#include<iostream>
#include<string>

/*
* Demonstrate the arrow operator.  
*/

class Entity
{
private:
	int x;
public:
	Entity(int a) 
		:x(a) {}
	void Print() const { std::cout << "Hello!" << std::endl; }
};

int main() 
{
	Entity* e_ptr = new Entity(1);
	(*e_ptr).Print();
	e_ptr->Print(); // only to public members
	std::cin.get();
}