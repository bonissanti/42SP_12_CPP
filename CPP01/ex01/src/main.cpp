#include "../include/Zombie.hpp"

int	main(void)
{
	Zombie	*heapZombie = newZombie("heapZombie");
	heapZombie->announce();

	randomChump("stackZombie");
	delete heapZombie;
	return (0);
}
