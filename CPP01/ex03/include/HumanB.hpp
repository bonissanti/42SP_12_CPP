#ifndef	HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
	Weapon*	weapon;
	std::string	name;

	public:
	void	setWeapon(Weapon& newWeapon);
	HumanB(const std::string& name) : name(name), weapon(nullptr) {}
	void	attack(void) const;
};

#endif

