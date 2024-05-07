#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int	main(void)
{
	Weapon	Club = Weapon("crude spiked club");

	HumanA	bob("Bob", Club);
	return (0);
}
