#include "../include/Harl.hpp"

Harl::Harl()
{
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
}

void	Harl::warning(void)
{
	std::cout << BGREEN << "[ WARNING ]" << RESET << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
		"I've been coming for years whereas you started working here since last month" << std::endl;
}

void	Harl::debug(void)
{
	std::cout << BGREEN << "[ DEBUG ]" << RESET << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << BGREEN << "[ INFO ]" << RESET << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
		"You didn't put enough bacon in my burger! If you did, I woundn't be asking for more!" << std::endl;
}

void	Harl::error(void)
{
	std::cout << BGREEN << "[ ERROR ]" << RESET << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complaining(void)
{
	std::cout << BRED << "[ Probably complaining about insignificant problems ]" << std::endl;
}