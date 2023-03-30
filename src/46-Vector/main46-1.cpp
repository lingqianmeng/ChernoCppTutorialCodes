#include<iostream>
#include<string>
#include<vector>

/**
* Demonstrate how to create a vector variable. push_back; clear; erase; for loop; pass in function;
*/

struct Vertex
{
	float x, y, z;
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

	std::vector<Vertex> vertices;

	/*
	* How to add element into vector
	*/
	vertices.push_back({ 1,2,3 }); // in other languages called add
	vertices.push_back({ 4,5,6 });

	/*
	* Normal for loop
	*/
	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl;
	/*
	*  Range based for loop
	*/
	for (Vertex v : vertices)
		std::cout << v << std::endl;

	for (Vertex& v : vertices)
		std::cout << v << std::endl;

	for (const Vertex& v : vertices)
		std::cout << v << std::endl;

	/*
	* How to erase element from vector
	*/
	vertices.erase(vertices.begin() + 1); // the second element was erased.

	for (Vertex v : vertices)
		std::cout << v << std::endl;

	/*
	* How to clear the whole vector. Size back to zero.
	*/
	vertices.clear();

	/*
	* Pass reference into it. Not copy vector.
	*/
	Function(vertices);

	std::cin.get();
}