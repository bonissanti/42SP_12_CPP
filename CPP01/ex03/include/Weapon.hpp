#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
	std::string	type;

	public:
	Weapon(const std::string& initType) : type(initType) {}
	const	std::string& getType(void) const;
	void	setType(const std::string& type);
};
	
#endif
