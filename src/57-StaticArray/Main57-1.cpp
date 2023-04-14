#include<iostream>
#include<array>

/*
*  It demonstrate why you should use std::array over c array.
*	
*/

/*
*  With using std::array and template you can put any type and any size of an array you want.
*/
template<typename T, size_t N> // the template must stay close to the function. Otherwise it will not work.
void PrintArray(const std::array<T,N>& stdArr)
{
	for (int i = 0; i < N; i++) // for (int i = 0; i < stdArr.size(); i++)
		std::cout << stdArr[i] << std::endl;
}

/*
*  In contrast to that, by using c array, you must specify tpye and size of an array before you put in a function.
*/

void PrintArray(const int* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << std::endl;
}

void PrintArray(const char* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << std::endl;
}

void PrintArray(const std::string* array, unsigned int size)
{
	for (int i = 0; i < size; i++)
		std::cout << array[i] << std::endl;
}



int main()
{
	// --- int array ---
	std::array<int, 5> std_arr_int5;
	std_arr_int5[0] = 0;
	std_arr_int5[4] = 1;

	int c_arr_int5[5];
	c_arr_int5[0] = 0;
	c_arr_int5[4] = 1;

	PrintArray(std_arr_int5);
	PrintArray(c_arr_int5,5);

	// --- char array ---
	std::array<char, 5> std_arr_char5;
	std_arr_char5[0] = 'M';
	std_arr_char5[4] = 'E';

	char c_arr_char5[5];
	c_arr_char5[0] = 'M';
	c_arr_char5[4] = 'E';

	PrintArray(std_arr_char5);
	PrintArray(c_arr_char5,5);

	// --- std::string array ---
	std::array<std::string, 5> std_arr_string5;
	std_arr_string5[0] = "Hello";
	std_arr_string5[4] = "World";

	std::string c_arr_string5[5];
	c_arr_string5[0] = "Hello";
	c_arr_string5[4] = "World";

	PrintArray(std_arr_string5);
	PrintArray(c_arr_string5,5);

	// --- show difference between how to reference arrays ---
	// c array is literally a pointer point to the first element of an array
	int* _p_arr = c_arr_int5;
	c_arr_int5[3] = 3;
	_p_arr[3] = 10; // 10 will be printed.

	// std array but not
	std::array<int,5>* _p_stdarr = &std_arr_int5;

	PrintArray(_p_arr, 5);

	std::cin.get();
}