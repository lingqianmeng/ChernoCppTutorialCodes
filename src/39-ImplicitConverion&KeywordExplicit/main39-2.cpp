#include<iostream>
#include<string>

/*
* Note: It is not recommended to use implicit conversion.
* With using explicit keyword ahead of constructor can avoid this. 
*/

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name) // with explicit the implicit conversion should not be possible any more.
		: m_Name(name), m_Age(-1) {}
	explicit Entity(int age)		// with explicit the implicit conversion should not be possible any more.
		: m_Name("Unknown"), m_Age(age) {}
};

void PrintEntity(const Entity& entity)
{
	// printing
}

int main()
{
	/*
	* normally create an object
	*/
	Entity a = Entity("cherno");
	Entity b = Entity(22);
	Entity c("cherno");
	Entity d(22);

	/*
	* To create an object with implicit conversion
	*/
	Entity e = std::string("cherno"); // cherno is not a string but a char array. 
	Entity f = 22;

	/*
	* Passing by the object input into a function normally
	*/
	PrintEntity(Entity("Chernot"));
	PrintEntity(Entity(22));

	/*
	* Passing by the object input into a function with using implicit conversion
	*/
	PrintEntity(22);	// its amazing to me it works now...
	PrintEntity(std::string("Cherno")); // Implicit Conversion could only do once in cpp. 1. Char array to string 2. string to Entity object.


	/*
	* This will not be working.
	*/
	Entity e = "cherno";		// will not work. According to the video from cherno it should work but not. 
	PrintEntity("Chernot"); // will not work. Because conversions must be happend twice.

	std::cin.get();
}