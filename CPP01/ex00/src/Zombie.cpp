#include "../include/Zombie.hpp"

Zombie::Zombie(std::string init) : name(init) {}

Zombie::~Zombie()
{
	std::cout << name << " : RIP" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
