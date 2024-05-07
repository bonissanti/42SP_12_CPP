#include "../include/Zombie.hpp"

int	main(void)
{
	int	n = 14;
	Zombie	*heapZombie = zombieHorde(n, "foo");

	for (int i = 0; i < n; i++)
		heapZombie[i].announce();

	if (heapZombie)
		delete[] heapZombie;
	return (0);
}
