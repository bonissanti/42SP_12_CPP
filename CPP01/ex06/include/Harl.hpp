#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <fstream>
#define BRED	"\033[1;31m"
#define BGREEN	"\033[1;32m"
#define BYELLOW	"\033[1;33m"
#define BBLUE	"\033[1;34m"
#define RESET	"\033[0m"

class Harl
{
	private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	typedef	void(Harl::*functionPtr)(void);
	functionPtr functions[4];
	std::string	levels[4];

	public:
	Harl();
	void	complain(std::string level);
};

#endif