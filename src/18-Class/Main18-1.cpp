#include<iostream>

// demonstrates why we need class & object to hold data and methods

#define LOG(x) std::cout << x << std::endl

class Player
{
public:
	int x, y;
	int speed;
};

// the function need to be moved into class as method.
void Move(Player& player, int xa, int ya)
{
	player.x += xa * player.speed;
	player.y += ya * player.speed;
}

int main()
{
	Player player;

	// give the position and speed of player
	player.x = 5;
	player.y = 10;
	player.speed = 10;
	Move(player, 1, -1);

	// display the location of player now
	LOG(player.x);
	LOG(player.y);

	std::cin.get();

}