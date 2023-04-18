#include<iostream>
#include<vector>
#include<algorithm>

/*funtion poiner + lambda expression*/

void ForEach(const std::vector<int>& values, void(*func)(int)) // function pointer
{
	for (int value : values)
		func(value);
}

int main()
{
	std::vector<int> values = { 1,3,4,5,2 };

	ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl; }); // lambda expression

	std::cin.get();
}