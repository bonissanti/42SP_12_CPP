#include "../include/Zombie.hpp"

Zombie *newZombie(int n, std::string name)
{
	if (n <= 0)
		std::cout << "Invalid number, please pass positive numbers." << std::endl;

	Zombie *horde = new Zombie[n];
	for (size_t i = 0; i < n; i++)
		horde[i] = 

	return (new Zombie(name));
}

