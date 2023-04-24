#include<iostream>

/*
*	Unions: If you want to address the same data with different ways.
*/

struct Vector2
{
	float x, y;
};

/*
struct Vector4
{
	float x, y, z, w;
};
*/

struct Vector4
{
	union
	{
		struct
		{
			float x, y, z, w;
		};

		struct
		{
			Vector2 a, b; // a = x,y; b = z,w
		};
	};
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << ", " << vector.y << std::endl;
}

int main()
{
	Vector4 vector = { 1.0f, 2.0f, 3.0f, 4.0f };

	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cout << "------------------" << std::endl;

	vector.z = 500.0f;
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	std::cin.get();
}