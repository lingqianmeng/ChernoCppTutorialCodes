#include<iostream>
#include<string>

struct Vector2 
{
	int x, y;
};

int main() 
{
	/*
	* changing b won't change a. a and b saved on two seperate locations in the memory. 
	* Assign a to b make copying.
	*/
	Vector2 a = { 5,10 };
	Vector2 b = a;
	b.x = 10;

	/*
	* a and b pointers point to the same location of memory. 
	*/
	Vector2* a_ptr=new Vector2;
	Vector2* b_ptr = a_ptr;
	b_ptr->x = 10;

	std::cin.get();
}