#include<iostream>
#include<vector>
#include<algorithm> // to use sort 
#include<functional> // to use std::greater

/*
* Demonstrate std::sort
*/

int main()
{

	std::vector<int> values = { 3,5,2,1,4 };
	/*
	* Low to High
	*/
	std::sort(values.begin(), values.end());

	for (int value : values)
		std::cout << value << std::endl;

	/*
	* High to Low
	*/
	std::sort(values.begin(), values.end(), std::greater<int>());

	for (int value : values)
		std::cout << value << std::endl;

	/*
	* Low to High
	*/
	std::sort(values.begin(), values.end(), [](int a, int b)
		{
			return a < b;
		});

	for (int value : values)
		std::cout << value << std::endl;

	/*
	* High to Low
	*/
	std::sort(values.begin(), values.end(), [](int a, int b)
		{
			return a > b;
		});

	for (int value : values)
		std::cout << value << std::endl;

	/*
	* Low to High, and move all '1's to the end of line.
	*/
	values = { 3,5,2,1,4,1 };
	std::sort(values.begin(), values.end(), [](int a, int b)
		{
			if (a == 1)
			return false;
	if (b == 1)
		return true;
	return a < b;
		});

	for (int value : values)
		std::cout << value << std::endl;

	std::cin.get();
}