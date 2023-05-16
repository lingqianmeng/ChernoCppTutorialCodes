#include<iostream>

// In this case the typical usage of reference will be demonstrated, that would be passing variables to functions. 

void Log(int var)
{
	std::cout << var << std::endl;
}

void Increment_Ptr(int* var)
{
	(*var)++;
}

void Increment_Ref(int& var)
{
	var++;
}
int main()
{
	// 1. Demonstrates how reference affects the being referenced variable, in this case, int a
	int a = 8;
	int& ref = a;
	ref = 2;
	Log(a); // 2 will be printed out.

	// 2a. Demonstrates passing a variable to a function with pointer.
	int b = 5;
	Increment_Ptr(&b);
	Log(b); // 6 will be printed out.

	// 2b. Demonstrates passing a variable to a function with reference. -> Nicer than with pointer!
	int c = 5;
	Increment_Ref(c);
	Log(c); // 6 will be printed out.

	// 3. Demontstrates the disadvantage against using pointers, that pointers could be assigned again, meanwhile reference not. 
	int d = 5;
	int e = 10;

	int* ptr = &d;
	*ptr = 1;
	ptr = &e;
	*ptr = 2;
	Log(d);
	Log(e); // 1 and 2 will be printed out. 

	std::cin.get();
}