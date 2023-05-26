#include<iostream>
#include<array>

/* Two kinds of arrays coverd here: 
*	1.Raw array: a. on stack 
*				 b. on heap
*	2.Standard array: 
*/

/* 5. Size of an array must be fixed to avoid */
class Entity
{
public:
	static const int numsSize = 5;
	int* nums = new int[numsSize];

	Entity()
	{
		for (int i = 0; i < numsSize; i++)
			nums[i] = 2;
	}
};

int main()
{
	/* Define an RAW Array */
	int example[5];

	/* 1. For loop matches array very much */
	for (int i = 0; i < 5; i++)
		example[i] = 2;

	/* 2. Arrays also Pointers */
	int* ptr = example; // it is just a pointer
	example[2] = 5;
	std::cout << "The second element in array is: " << example[2] << std::endl;
	*(ptr + 2) = 6;
	std::cout << "The second element in array is: " << example[2] << std::endl;
	*((int*)((char*)ptr + 8)) = 7;
	std::cout << "The second element in array is: " << example[2] << std::endl;

	/* 3. Create an Array on Heap */
	int* another = new int[5];
	// the way to delete array pointer.
	delete[] another; 

	/* 4. size of an RAW array */
	int a[5];
	int count = sizeof(a) / sizeof(int);
	std::cout << "The size of a array is: " << count << std::endl;

	/* 5. Standard array */
	std::array<int, 5> sArray;
	for (int i = 0; i < sArray.size(); i++)
		example[i] = 2;
	std::cin.get();
}
