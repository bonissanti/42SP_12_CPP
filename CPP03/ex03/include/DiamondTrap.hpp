/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/04/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/04/2024                   */
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

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

#define suffix "_clap_name"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
	std::string	_name;

	public:
	DiamondTrap();
	DiamondTrap(const std::string& name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& toCopy);
	DiamondTrap& operator=(const DiamondTrap& toCopy);
	void	attack(const std::string& target);
	void	whoAmI(void);
};

#endif