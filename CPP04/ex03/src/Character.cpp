/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/06/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/06/2024                   */
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

#include "../include/Character.hpp"

Character::Character(){
	debugMode("<CHARACTER> Default constructor called");
	this->name = "Random";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	
}

Character::Character(const std::string& name) : name(name)
{
	debugMode("<CHARACTER> Parametrized constructor called");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::~Character()
{
	debugMode("<CHARACTER> destructor called");
	for (int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
}

Character::Character(const Character& toCopy)
{
	debugMode("<CHARACTER> Copy constructor called");
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = toCopy;
}

Character& Character::operator=(const Character& toCopy)
{
	debugMode("<CHARACTER> Copy assignment operator called");
	if (this != &toCopy)
	{
		this->name = toCopy.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			if (toCopy.inventory[i])
				this->inventory[i] = toCopy.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const &	Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << RED << "<Character> Material not recognized" << RESET << std::endl;
		return ; 
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i] == NULL)
		{
			this->inventory[i] = m->clone();
			std::cout << YELLOW << "<Character> '" << GREEN << m->getType() << "'" << YELLOW << " added succesfully to the inventory" << RESET << std::endl;
			return ;
		}
	}
	std::cout << RED << "<Character> Inventory is full" << RESET << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << RED << "Invalid idx. Please, try a valid index" << RESET << std::endl;
		return ;
	}
	else if (this->inventory[idx] == NULL)
	{
		std::cout << RED << "Inventory already empty" << RESET << std::endl;
		return ;
	}
	std::cout << YELLOW << "Unequiping inventory at idx '" << idx << "' | " << GREEN << this->inventory[idx] << std::endl;
	this->inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 4)
	{
		std::cout << RED << "<Chracter> Invalid idx. Please, try a valid index" << RESET << std::endl;
		return ;
	}	
	if (this->inventory[idx])
		this->inventory[idx]->use(target);
	else
		std::cout << RED << "<Character> Empty index" << RESET << std::endl;
}