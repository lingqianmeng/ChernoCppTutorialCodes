#include<iostream>
#include<string>
#include<vector>

/**
* Demonstrate how many times the object being copied when being pushed back to a vector. Thus actually how unefficient.
* Demonstrate how to avoid unefficient copy aroud vector with using vector.reserve()
* Demonstrate how to avoid unefficient copy aroud vector with using vector.emplace_back() -> proved to be the most efficient way!
*/

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x), y(y), z(z)
	{

	}

	// constructor for copy purpose. It will shoe copied! once the object got copied.
	Vertex(const Vertex& vertex)
		:x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
	return stream;
}

/*
*  By passing into function -> Always use reference not copy!
*/
void Function(const std::vector<Vertex>& vertices)
{

}

int main()
{
	std::cout << "-----Demonstrate vector push back causing copy on its element!-----" << std::endl;
	std::vector<Vertex> vertices;
	vertices.push_back(Vertex(1, 2, 3)); // get copied once, {1,2,3} got copied into vector.
	vertices.push_back(Vertex(4, 5, 6)); // get copied twice, {1,2,3} and {4,5,6} got copied into vector. Because the vector got resized, from 1 to 2. 
	vertices.push_back(Vertex(7, 8, 9)); // get copied three times. 
	Function(vertices);

	vertices.clear();
	std::cout << "-----Demonstrate vector push back with reserve on memory causing copy on its element!-----" << std::endl;
	vertices.reserve(3);				 // reserve the memory 
	vertices.push_back(Vertex(1, 2, 3)); // get copied once, {1,2,3} got copied into vector.
	vertices.push_back(Vertex(4, 5, 6)); // get copied once, {4,5,6} got copied into vector.   
	vertices.push_back(Vertex(7, 8, 9)); // get copied once, {7,8,9} got copied into vector.
	Function(vertices);

	vertices.clear();
	std::cout << "-----Demonstrate vector emplace back with  causing copy on its element!-----" << std::endl;
	vertices.reserve(3);				// No copied with or without reserve()
	vertices.emplace_back(1, 2, 3);		// No copied 
	vertices.emplace_back(4, 5, 6);		// No copied 
	vertices.emplace_back(7, 8, 9);		// No copied 
	Function(vertices);

	vertices.clear();

	std::cin.get();
}