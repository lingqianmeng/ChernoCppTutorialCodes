#include<iostream>

/*Show how public inheretance works*/

class Entity
{
private:
	float X, Y;
public:
	void InitCoordinate(float x, float y)
	{
		this->X = x;
		this->Y = y;
	}

	void PrintCoordinate()
	{
		std::cout << "X: " << this->X << " Y: " << this->Y << std::endl;
	}
	
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

// Public inheritance
class Player : public Entity
{
public:
	const char* Name;

	void GiveName(const char* Name )
	{
		this->Name = Name;
	}

	void PrintName()
	{
		std::cout << "Name of Player: " << Name << std::endl;
	}
};

int main()
{
	Player player;
	// Init
	player.GiveName("Lingqian");
	player.InitCoordinate(0.0,0.0);
	// Operations
	player.Move(10.0, 5.0);
	player.PrintCoordinate();
	player.PrintName();
	// this is not working...
	// player.X
	std::cin.get();
}