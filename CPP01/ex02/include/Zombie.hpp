#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
	std::string	name;

	public:
	Zombie() {}
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	void	setName(const std::string& zombieName);
};
	
Zombie *zombieHorde(int n, std::string name);
void	randomChump(std::string name);

#endif

