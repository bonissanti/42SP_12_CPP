/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/05/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/05/2024                   */
/* ⠀⠀⣠⡾⠟⠁⠀⠀⠀⢸⣿⣸⣿⣿⣿⣆⠙⢿⣷⡀⠀⠀                                                       */
/* ⣰⡿⠋⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠉⠻⣿⡀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆ ⠀       Email: brunrodr@student.42sp.org.br                 */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣿⣿⣿⣿⡄⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠿⠟⠀⠀⠻⣿⣿⡇⠀⠀⠀⠀   ███████╗██╗██╗██╗██╗██╗██╗██╗██╗██╗   ██╗██╗   ██╗  */
/* ⠀⠀⠀⠀⠀⠀⢀⣾⡿⠃⠀⠀⠀⠀⠀⠘⢿⣿⡀⠀⠀⠀   ██╔════╝██║██║██║██║██║██║██║██║██║   ██║██║   ██║  */
/* ⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡀⠀⠀   ███████╗██║██║██║██║██║██║██║██║██║   ██║██║   ██║  */
/* ⠀⠀⠀⠀⢠⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⠀⠀   ╚════██║██║██║██║██║██║██║██║██║██║   ██║██║   ██║  */
/* ⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀   ███████║██║██║██║██║██║██║██║██║╚██████╔╝╚██████╔╝  */
/*  ⠀⠠⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡤  ╚══════╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝ ╚═════╝  ╚═════╝   */
/*************************************************************************************/


#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0){
		std::cout << "<ClapTrap> default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name),
	hitPoints(10), energyPoints(10), attackDamage(0){
		std::cout << BBLUE << "<ClapTrap> Parametrized constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << BBLUE << "<ClapTrap> " << this->name << " destructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& toCopy){
	std::cout << BBLUE << "<ClapTrap> Copy constructor called" << RESET << std::endl;
	*this = toCopy;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& toCopy){
	std::cout << BBLUE << "<ClapTrap> Copy assignment operator called" << RESET << std::endl;
	if (this != &toCopy)
	{
		this->name = toCopy.name;
		this->type = toCopy.type;
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
	this->hitPoints = hitP;
}

void	ClapTrap::setEnergyP(const unsigned int energyP)
{
	this->energyPoints = energyP;
}

void	ClapTrap::setAttackD(const unsigned int attackD)
{
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

std::string	ClapTrap::getType(void) const
{
	return (this->type);
}

void	ClapTrap::setType(const std::string& type)
{
	this->type = type;
}

void	ClapTrap::attack(const std::string& target)
{
 	if (this->getHitP() == 0 || this->getEnergyP() == 0)
	{
 		std::cout << GREEN << this->getType() << this->getName() << RED << "  is not able to attack because HP or energy points are insufficient. HP: " 
   << GREEN << this->hitPoints << RED << " | Energy: " << GREEN << this->energyPoints << std::endl;
		return ;
	}
	this->energyPoints--;
	std::cout << GREEN << this->getType() << RED << " " << GREEN << this->getName() 
		<< RED << " attacks " << GREEN << target << RED << " causing a damage of " << GREEN << this->getAttackD() << RESET << std::endl;	
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHitP() == 0)
	{
		std::cout << RED << "<ClapTrap> " << GREEN << this->getName() << RED << " is already dead. Rest in peace, bro" << RESET << std::endl;
		return ;
	}
	else if (this->hitPoints - amount > this->hitPoints)
		this->hitPoints = 0;
	else
		this->hitPoints -= amount;
	std::cout << RED << "<ClapTrap> " << GREEN << this->name << RED << " has been attacked, suffering a damage of " << GREEN << amount
	<< RED << ", his HP now is " << GREEN << this->hitPoints << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getHitP() == 0 || this->getEnergyP() == 0)
	{
		std::cout << RED << "<ClapTrap> " << GREEN << this->name << RED << " is unable to repaire because insufficient HP or energy | HP: " 
			<< GREEN << this->hitPoints << RED << " Energy: " << GREEN << this->energyPoints << RESET << std::endl;
		return ;
	}
	this->energyPoints--;
	if (this->hitPoints + amount < this->hitPoints)
		this->hitPoints = 4294967295;
	else
		this->hitPoints += amount;
	std::cout << GREEN << this->name << RED << " repaired by " << GREEN << amount << RED << " amount, now his HP is " << GREEN << this->hitPoints << RESET << std::endl;
}