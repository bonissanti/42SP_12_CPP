#include "../include/Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	deadAlive(name);
	deadAlive.announce();
}

