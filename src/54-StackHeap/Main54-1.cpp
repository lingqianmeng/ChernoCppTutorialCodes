#include<iostream>
#include<string>

struct Vector3
{
	int a, b, c;
	Vector3()
		: a(10), b(20), c(30) {}
};

int main()
{
	// Allocation on Stack
	int value = 5;
	int array[5];
	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;
	Vector3 vector;

	// Allocation on Heap
	int* hvalue = new int;
	*hvalue = 5;
	int* harray = new int[5];
	harray[0] = 1;
	harray[1] = 2;
	harray[2] = 3;
	harray[3] = 4;
	harray[4] = 5;
	Vector3* hvector = new Vector3();

	delete hvalue;
	delete[] harray;
	delete hvector;

	std::cin.get();
}