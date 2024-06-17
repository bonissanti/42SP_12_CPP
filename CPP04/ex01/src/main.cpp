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

#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

int	main(void)
{
	{
		std::cout << BWHITE << "*** SUBJECT TEST ***" << RESET << std::endl;
		Animal	*myDog = new Dog();
		Animal	*myCat = new Cat();

		delete myDog;
		delete myCat;
	}

	std::cout << "\n";
	{
		std::cout << BWHITE << "*** BRAIN TEST ***" << RESET << std::endl;
		Cat *myCat = new Cat();
		Dog *myDog = new Dog();

		std::cout << "\n";
		std::cout << YELLOW << "- Setting idea to 'myCat' and 'myDog' -" << GREEN << std::endl;
		myCat->setBrain(7, "Bro, where's my toy?");
		myDog->setBrain(5, "Let's go for a walk, human");

		std::cout << YELLOW << "Cat says: " << GREEN << myCat->getBrain(5) << RESET << std::endl;
		std::cout << YELLOW << "Dog says: " << GREEN << myDog->getBrain(4) << RESET << std::endl;
		std::cout << "\n";

		delete myCat;
		delete myDog;
	}

	std::cout << "\n";
	{
		std::cout << BWHITE << "*** SUBJECT TEST ***" << RESET << std::endl;

		Animal *animal[100];

		std::cout << YELLOW << "- Creating an array of 100 animals (50 cats/50 dogs) -" << GREEN << std::endl;
		for (int i = 0; i < 50; i++)
			animal[i] = new Cat();

		for (int i = 50; i < 100; i++)
			animal[i] = new Dog();

		std::cout << "\n--------------------> Printing type of each animal <--------------------\n";

		for (int i = 0; i < 100; i++)
				std::cout << animal[i]->getType() << std::endl;

		std::cout << "\n--------------------> Destructors calls (to see, run 'make test') <--------------------\n";

		for (int i = 0; i < 100; i++)
			delete animal[i];
	}

	{
		std::cout << BWHITE << "\nDEEP COPY TEST" << RESET << std::endl;

		Dog *myDog1 = new Dog();
		Dog *myDog2 = new Dog();

		std::cout << YELLOW << "- Setting idea to 'myDog1' -" << GREEN << std::endl;
		myDog1->setBrain(2, "I hate cats");

		*myDog2 = *myDog1;
		std::cout << YELLOW << "- Copying 'myDog1' to 'myDog2' -" << GREEN << std::endl;
		std::cout << YELLOW << "myDog1 says: " << GREEN << myDog1->getBrain(1) << std::endl;
		std::cout << YELLOW << "myDog2 says: " << GREEN << myDog2->getBrain(1) << std::endl;

		std::cout << "\n";
		std::cout << YELLOW << "- Setting new idea to 'myDog1' -" << GREEN << std::endl;
		myDog1->setBrain(2, "I love cats");
		std::cout << YELLOW << "myDog1 says: " << GREEN << myDog1->getBrain(1) << std::endl; //At shallow copy, this will print "Vou arrancar sua perna"
		std::cout << YELLOW << "myDog2 says: " << GREEN << myDog2->getBrain(1) << RESET << " // at shallow copy, this will be 'I love cats' as well" << std::endl; //At shallow copy, this will print "Vou arrancar sua perna"
		
		delete myDog1;
		delete myDog2;
	}


	
	return (0);
}
