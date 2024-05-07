#include "../include/Zombie.hpp"

Zombie::Zombie(std::string init) : name(init) {}

Zombie::~Zombie()
{
	static int	i = 0;
	std::cout << name << " " << ++i << " : RIP" << std::endl;
}

void	Zombie::announce(void)
{
	static int	i = 0;

	std::cout << name << " " << ++i << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(const std::string& zombieName)
{
	this->name = zombieName;
}
