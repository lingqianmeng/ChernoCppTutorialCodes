#include<iostream>

/*Show the relationship between char array and std::string 
* char array: raw string / c style string
* std::string: standard string / c++ style string
*/

void PrintTitel(const std::string& titel) // pass variable in function by reference not by copy.
{
	std::cout << "----------" << titel << "----------" << std::endl;
}

int main()
{	
	char* name = new char[100];
	name[10] = 'a';
	delete[] name;
	
	PrintTitel("char array");
	char name2[6] = { 'C','H','E','R','N','O' };
	std::cout << name2 << std::endl;		// the print will be followed with random characters. 

	PrintTitel("const char array");
	const char name2_const[6] = { 'C','H','E','R','N','O' };
	// name2_const[2] = 'a';				// not OK.
	std::cout << name2_const << std::endl;  // the print will be followed with random characters. 

	PrintTitel("char array clean");
	char name2_clean[7] = { 'C','H','E','R','N','O','\0'};
	std::cout << name2_clean << std::endl;  // the print is clean. 

	PrintTitel("char array dynamic");
	char name1[] = "CHERNO";
	//name1 = "hello123456";				// this will NOT do.
	std::cout << name1 << std::endl;		// the print is clean. 

	PrintTitel("const char*");
	const char* name3 = "CHERNO";			// with "" means it is about char pointer 
	name3 = "hello123456";					// this will do
	std::cout << name3 << std::endl;		// the print is clean. 
	
	PrintTitel("std::string");
	std::string str_name2 = "CHERNO";
	str_name2 = "hello123456";
	std::cout << str_name2 << std::endl;	// the print is clean. 

	PrintTitel("Two ways how to combi two strings together");
	str_name2 = std::string("Cherno") + " Cpp";
	std::cout << str_name2 << std::endl;
	str_name2 += " Cpp";
	std::cout << str_name2 << std::endl;

	PrintTitel("std::string api functions...");
	std::cout << str_name2.size() << std::endl;

	std::cin.get();

}