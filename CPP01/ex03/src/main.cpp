#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"
#include "../include/HumanB.hpp"

int	main(void)
{
	Weapon	club = Weapon("crude spiked club");

	HumanA	bob("Bob", club);
	bob.attack();
	club.setType("Some other type of club");
	bob.attack();

	return (0);
}
