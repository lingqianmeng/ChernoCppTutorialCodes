#include<iostream>

// Now Player class holds both data and methods

#define LOG(x) std::cout << x << std::endl

class Player
{
public:
	int x, y;
	int speed;
	// Now the function intergrated into the class. 
	void Move( int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}
};

int main()
{
	Player player;

	// give the position and speed of player
	player.x = 5;
	player.y = 10;
	player.speed = 10;
	// call 'move' as a method of player not as function any more.
	player.Move(1, -1);

	// display the location of player now
	LOG(player.x);
	LOG(player.y);

	std::cin.get();

}