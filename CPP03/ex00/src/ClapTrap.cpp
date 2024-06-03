/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/03/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/03/2024                   */
/* ⠀⠀⣠⡾⠟⠁⠀⠀⠀⢸⣿⣸⣿⣿⣿⣆⠙⢿⣷⡀⠀⠀                                                       */
/* ⣰⡿⠋⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠉⠻⣿⡀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆ ⠀       Email: brunrodr@student.42sp.org.br                 */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣿⣿⣿⣿⡄⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠿⠟⠀⠀⠻⣿⣿⡇⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⢀⣾⡿⠃⠀⠀⠀⠀⠀⠘⢿⣿⡀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡀⠀⠀   ⢽⣿⣿⠛⢻⣿⣿⣿⣿⠛⠛⠛⠛⢻⣿⣿⠿⠛⠛⠿⣿⡟⠛⠛⠛⠛⣿⡟⢿⣿⣿⣿⠛⢻⡟⠛⠛⠛⠻⣿⣿⣿ */
/* ⠀⠀⠀⠀⢠⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⠀⠀   ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢿⣿⣿⣿⡿⠁⣴⣶⣶⣾⣿⡇⠀⣿⣿⣿⣿⡏⢀⠙⢿⣿⠀⢸⡇⠀⣷⣷⣆⠈⢿⣿ */
/* ⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀   ⢸⣿⣿⠀⢸⣿⣿⣿⣿⠀⢤⣤⣴⣿⣧⠀⢿⣿⣤⠀⣿⡇⠀⣤⣤⣼⣿⡇⠀⣷⣄⠙⠀⢸⡇⠀⣿⣿⡟⠀⣸⣿ */
/*  ⠀⠠⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡤  ⢸⣿⣿⣀⣈⣉⣉⣉⣿⣀⣈⣉⣉⣹⣿⣷⣄⣈⣁⣤⣿⣇⣀⣉⣉⣉⣿⣇⣀⣿⣿⣷⣄⣸⣧⣀⣉⣉⣀⣴⣿⣿ */
/*************************************************************************************/

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(){
}

ClapTrap::ClapTrap(const std::string& name) : name(name), 
	hitPoints(10), energyPoints(10), attackDamage(0){
}

ClapTrap::~ClapTrap(){
}

ClapTrap::ClapTrap(const ClapTrap& toCopy){
	*this = toCopy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& toCopy){
	if (this != &toCopy)
	{
		this->name = toCopy.name;
		this->hitPoints = toCopy.hitPoints;
		this->energyPoints = toCopy.energyPoints;
		this->attackDamage = toCopy.attackDamage;
	}
	return (*this);
}

unsigned int	ClapTrap::getHitP(void) const
{
	return (this->hitPoints);
}

unsigned int	ClapTrap::getEnergyP(void) const
{
	return (this->energyPoints);
}

unsigned int	ClapTrap::getAttackD(void) const
{
	if (this->getHitP() > 0)
		return (this->attackDamage);
	return (0);
}

void	ClapTrap::setHitP(const unsigned int hitP)
{
	std::cout << "Configuring the HP of " << this->name << " to " << hitP << std::endl;
	this->hitPoints = hitP;
}

void	ClapTrap::setEnergyP(const unsigned int energyP)
{
	std::cout << "Configuring the Energy Point of " << this->name << " to " << energyP << std::endl;
	this->energyPoints = energyP;
}

void	ClapTrap::setAttackD(const unsigned int attackD)
{
	std::cout << "Configuring the Attack Damage of " << this->name << " to " << attackD << std::endl;
	this->attackDamage = attackD;
}

std::string	ClapTrap::getName(void) const
{
	return (this->name);
}

void	ClapTrap::setName(const std::string& name)
{
	this->name = name;
}

void	ClapTrap::attack(const std::string& target)
{
 	if (this->getHitP() == 0 || this->getEnergyP() == 0)
	{
 		std::cout << this->getName() << " is not able to attack because insufficient HP or energy | HP: "<< this->hitPoints << " Energy: " << this->energyPoints << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << this->name << " attacks " << target << " causing a damage of " << this->getAttackD() << std::endl;	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitP() == 0)
	{
		std::cout << this->getName() << " is already died. Rest in peace, bro" << std::endl;
		return ;
	}
	else if (this->hitPoints - amount > this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << this->name << " has been attacked, suffering a damage of " << amount
		 << ", his HP now is " << this->hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitP() == 0 || this->getEnergyP() == 0)
	{
		std::cout << this->name << " is unable to repaire because insufficient HP or energy | HP: " << this->hitPoints << " Energy: " << this->energyPoints << std::endl;
		return ;
	}
	this->energyPoints--;
	if (this->hitPoints + amount < this->hitPoints)
		this->hitPoints = 4294967295;
	else
		this->hitPoints += amount;
	std::cout << this->name << " repaired by " << amount << " amount, now his HP is " << this->hitPoints << std::endl;
}