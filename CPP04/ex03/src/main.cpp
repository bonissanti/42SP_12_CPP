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

#include "../include/Master.hpp"

int	main(void)
{
	std::cout << BWHITE << "********** SUBJECT TEST **********\n" << RESET;
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice()); // add types allowed of materials
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me"); // creating the character to use this materials

		std::cout << MAGENTA << "\n----------> Verify material <----------\n" << RESET << std::endl;
		AMateria *tmp;
		tmp = src->createMateria("batata"); // invalid material, doesn't have to add
		me->equip(tmp);	// invalid
		tmp = src->createMateria("Cure"); // ok
		me->equip(tmp); // ok
		tmp = src->createMateria("Ice");
		me->equip(tmp);
		tmp = src->createMateria("Cure");
		me->equip(tmp);
		tmp = src->createMateria("Ice");
		me->equip(tmp);

		std::cout << MAGENTA << "\n----------> Character + use <----------\n" << RESET << std::endl;
		ICharacter *bob = new Character("Bob"); // target
		me->use(0, *bob);	
		me->use(1, *bob);	

		delete bob;
		delete me; 
		delete src;
	}

	std::cout << "\n";
	{
		std::cout << BWHITE << "********** DEEP COPY TEST **********\n" << RESET << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		
		Character *original = new Character("Original");

		std::cout << MAGENTA << "----------> Verify material <----------\n" << RESET << std::endl;
		AMateria *tmp;
		tmp = src->createMateria("Ice");
		original->equip(tmp);

		std::cout << MAGENTA << "\n----------> Original vs Copy <----------\n" << RESET << std::endl;
		Character *copy = new Character(*original);
		std::cout << YELLOW << "Original name: " << GREEN << original->getName() << std::endl;
		std::cout << YELLOW << "Copy name: " << GREEN << copy->getName() << std::endl;
		Character target("target");

		std::cout << MAGENTA << "\n----------> Equal prints <----------\n" << RESET << std::endl;
		original->use(0, target);	
		copy->use(0, target);	

		std::cout << MAGENTA << "\n----------> Different prints <----------\n" << RESET << std::endl;
		src->learnMateria(new Cure());
		tmp = src->createMateria("Cure");
		original->equip(tmp);
		original->use(1, target);
		copy->use(1, target);

		delete copy;
		delete original; 
		delete src;
	}
	return (0);
}