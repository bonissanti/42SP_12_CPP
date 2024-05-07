#include "../include/Weapon.hpp"

void	Weapon::setType(const std::string& type)
{
	this->type = type;
}

const	std::string& Weapon::getType(void) const
{
	return (type);
}
