#include<iostream>
#include<string>

/**
*	Class template with two arguments
*/

template<typename T, int N> // make type and the size of array dynamic

class Array
{
private:
	T m_Array[N]; // The type of elements in the array keep dynamic. keep N dynamic 
public:
	int Getsize() const { return N; }
};

int main()
{
	Array<std::string, 5> array; // N is 5 now. 
	Array<float, 10> array2;
	std::cout << array.Getsize() << std::endl;
	std::cout << array2.Getsize() << std::endl;
	std::cin.get();
}