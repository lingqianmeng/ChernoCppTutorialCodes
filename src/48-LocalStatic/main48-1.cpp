#include<iostream>

/*
* Demonstrate local static on variable. 
* 
* static variable in a function can live outside the scope like global variables, but not be accessed from outside. 
* By access if you mean to call its value and assign it to other, then you are right. 
* Otherwise to change its content is not available at least as I just tried.
*/

void Function()
{
	static int i = 0;
	i++;
	std::cout << i << std::endl;
}

// equals to 

int j = 0;
void Function2()
{
	j++;
	std::cout << j << std::endl;
}

int main()
{	
	Function();
	Function();
	Function();
	Function();
	Function();
	Function2();
	Function2();
	Function2();
	Function2();
	Function2();
}

/*
const int* Function()
{
	static int i = 0;
	const int* i_ptr = &i;
	i++;
	std::cout << i << std::endl;
	return i_ptr;
}
*/