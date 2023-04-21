#include<iostream>

/*
 It demonstrates Type Punning in C++. Use Debug mode to observe memory would be good here.
*/

struct Entity
{
	int x, y;
};

int main()
{
	Entity e = { 4,9 };

	/*
	* At this point, the struct can be seen as an array.
	*/
	int* position = (int*)&e;

	std::cout << position[0] << ", " << position[1] << std::endl; // print out "4,9"

	/*
	* Pointer casting and then dereference.
	*/

	int y = *(int*)((char*)&e + 4);

	//int y = *(int*)((bool*)&e + 4); // also do

	std::cout << y << std::endl; // print out "9"

	std::cin.get();
}