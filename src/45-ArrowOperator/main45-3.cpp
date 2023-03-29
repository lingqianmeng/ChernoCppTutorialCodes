#include<iostream>
#include<string>

/*
* Demonstrate to figure out offset each member variable in memory
*/

struct Vector3
{
	float x, y, z; // one float is 4 bytes
};

int main()
{
	// could be this 
	int offset_x = (int)&((Vector3*)nullptr)->x; // the unit is byte. 

	// or this 
	offset_x = (int)&((Vector3*)0)->x;
	int offset_y = (int)&((Vector3*)0)->y;
	int offset_z = (int)&((Vector3*)0)->z;
	std::cout << offset_x << std::endl;
	std::cout << offset_y << std::endl;
	std::cout << offset_z << std::endl;
	// the output is 0 4 8
	std::cin.get();
}