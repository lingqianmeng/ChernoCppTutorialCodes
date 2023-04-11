#include <iostream>
#include "GLFW\glfw3.h"

int main()
{
	int i = glfwInit();
	std::cout << i << std::endl;
	std::cin.get();
}