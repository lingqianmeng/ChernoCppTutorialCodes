#include<iostream>
#include<string>

/*
* [Overload 1]Demonstrate how + being overloaeded ...
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

	// now overload + 
	Vector2 operator+(const Vector2& other) const 
	{
		return Add(other);
	}

	// or ...
	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const
	{
		return Vector2(x * other.x, y * other.y);
	}

};

int main()
{
	Vector2 position(4.0f, 4.0f);
	Vector2 speed(0.5f, 1.5f);
	Vector2 powerup(1.1f, 1.1f); // speed times powerup

	Vector2 result = position.Add(speed.Multiply(powerup)); // position + speed * powerup
	// In java, there are no other options but to write like this.

	Vector2 resutl = position + speed; // the operator + is now overloaded. 
	std::cin.get();
}