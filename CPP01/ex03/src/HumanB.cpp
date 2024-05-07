#include "../include/HumanB.hpp"

void	HumanB::attack() const
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	else
		std::cout << name << " attacks with their fists " << std::endl;
}

void HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}
