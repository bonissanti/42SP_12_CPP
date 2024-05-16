#include "../../include/Weapon.hpp"
#include "../../include/HumanA.hpp"
#include "../../include/HumanB.hpp"

int	main(void)
{
	std::cout << "TEST# 1 - from PDF" << std::endl;
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB	jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	std::cout << "\nTEST# 2 HumanB attacking without weapon" << std::endl;
	{
		Weapon	tool = Weapon("hammer");
		HumanA	bob("Bob", tool);
		bob.attack();
	}
	{
		Weapon	tool = Weapon("bazuka");
		HumanB	jim("Jim");
		jim.attack();
		tool.setType("bazuka");
		jim.attack();
	}
	return (0);
}