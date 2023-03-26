#include<iostream>
#include<string>

/*
* Demonstrate how +, *, ==, != and << being overloaeded ...
*/

// use struct because it would be public.
struct Vector2
{
	float x, y;

	Vector2(float x, float y)
		: x(x), y(y) {}

	Vector2 Add(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

	// define overload + 
	Vector2 operator+(const Vector2& other) const
	{
		return Add(other);
	}

	// define overload * 
	Vector2 operator*(const Vector2& other) const
	{
		return Multiply(other);
	}

	// define overload ==
	bool operator==(const Vector2& other) const
	{
		return x == other.x && y == other.y;
	}

	// define overload !=
	bool operator!=(const Vector2& other) const
	{
		return x != other.x || y != other.y;
		//oder ...
		//return !(*this == other);
	}

};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ", " << other.y;
	return stream;
}

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f); // speed times powerup
	Vector2 powerup2(1.2f, 1.3f); // speed times powerup
	Vector2 result = position.Add(speed.Multiply(powerup));

	/*
	* Demonstrate + and * overloading
	*/
	Vector2 result2 = position + speed * powerup;
	Vector2 result3 = position + speed * powerup2;

	/*
	* Demonstrate << overloading
	*/
	std::cout << result2 << std::endl;

	/*
	* Demonstrate == and != overloading
	*/
	if (result == result2)
	{
		std::cout << "result same" << std::endl;
	}

	if (result != result3)
	{
		std::cout << "result not same" << std::endl;
	}

	std::cin.get();
}