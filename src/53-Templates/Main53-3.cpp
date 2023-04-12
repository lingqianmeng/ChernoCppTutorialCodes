#include<iostream>
#include<string>

/**
*	Class template
*/

template<int N>

class Array
{
private:
	int m_Array[N]; // keep N dynamic 
public:
	int Getsize() const { return N; }
};

int main()
{
	Array<5> array; // N is 5 now. 
	Array<10> array2;
	std::cout << array.Getsize() << std::endl;
	std::cout << array2.Getsize() << std::endl;
	std::cin.get();
}