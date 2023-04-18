#include<iostream>
#include<vector>
#include<algorithm>
#include<functional> // include this

/* lambda expression
*/

void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}

int main()
{
	std::vector<int> values = { 1,3,4,5,2 };
	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; }); // lambda
	std::cout << *it << std::endl;

	// by using lambda you can pass variable through capture[] into the function
	int a = 5;
	auto lambda = [=](int value) {std::cout << "Value: " << a << std::endl; };
	ForEach(values, lambda);

	std::cin.get();
}