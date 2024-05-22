#include "../include/Harl.hpp"

void	Harl::printMessage(levelCode code)
{
	switch (code)
	{
		case DEBUG:
			this->debug();
		case INFO:
			this->info();
		case WARNING:
			this->warning();
		case ERROR:
			this->error();
			break ;
		default:
			return (this->complaining());
	}
}

int	Harl::getIndex(std::string level)
{
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl		harl;
	int			numLevel;
	std::string	level;
	
	if (argc != 2)
	{
		std::cerr << "Invalid numbers of arguments: use -> ./harlFilter <level>" << std::endl;
		return (1);
	}
	level = argv[1];
	numLevel = harl.getIndex(level);
	harl.printMessage(static_cast<Harl::levelCode>(numLevel));
	return (0);
}