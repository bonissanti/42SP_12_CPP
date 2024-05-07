#ifndef	HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
	Weapon&	weapon;
	std::string	name;

	public:
	HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon) {}
	void	attack(void) const;
};

#endif
