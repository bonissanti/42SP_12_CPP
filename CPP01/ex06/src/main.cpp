#include "../include/Harl.hpp"

int	main(void)
{
	Harl	harl;
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("random");
	harl.complain("124 456 789 0");
	return (0);
}
