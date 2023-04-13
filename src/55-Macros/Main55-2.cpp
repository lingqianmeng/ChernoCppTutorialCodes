#include<iostream>
#include<string>

/*
* Using Macros for Logging advanced, that you can control, if you want your debug logging appear to your productino code or not.
*/

// assign 1 or 0 to the Micro LM_DEBUG to control if you want logging being inclusive or not. 
// = 1 yes -> Hello World will be seen. 
// = 0 no -> Hello World will not be printed. 
#define LM_DEBUG 1

#if LM_DEBUG == 1
#define LOG(x) std::cout << x << std::endl;
#else
#define LOG(x)
#endif // LM_DEBUG

int main()
{
	LOG("Hello World");
	std::cin.get();
}