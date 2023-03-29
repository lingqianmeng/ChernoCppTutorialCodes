#include<iostream>
#include<string>

/*
* Demonstrate arrow operator in scoped pointer
*/

// The class itsself
class Entity
{
private:
	int x;
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

// The scoped pointer to the class
class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		:m_Obj(entity)
	{

	}
	~ScopedPtr()
	{
		delete m_Obj;
	}
	// arrow operator
	Entity* operator->()
	{
		return m_Obj;
	}
	// const version of arrow operator. Thus the function 'Print()' of the class must be const too. 
	const Entity* operator->() const
	{
		return m_Obj;
	}
};

int main()
{
	ScopedPtr entity = new Entity;
	entity->Print(); // so now arrow operator could be used in scoped pointer
	std::cin.get();
}