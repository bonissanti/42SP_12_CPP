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
#include "../include/WrongCat.hpp"

int	main(void)
{
	{
		std::cout << BWHITE << "*** Constructors tests - Animal***" << RESET << std::endl;
		Animal a;
		Animal b(a);
		Animal c = b;
		Dog	dog;
		Cat cat;

		std::cout << YELLOW << "Default type of animal 'a' is: " << GREEN << a.getType() << RESET << std::endl;
		std::cout << YELLOW << "Default type of animal 'b' is: " << GREEN << b.getType() << RESET << std::endl;
		std::cout << YELLOW << "Default type of animal 'c' is: " << GREEN << c.getType() << RESET << std::endl;
		a = Animal(dog);

		std::cout << YELLOW << "New type of animal 'a' after instantiate with Dog Constructor is: " << GREEN << a.getType() << RESET << std::endl;
		std::cout << YELLOW << "Sound of animal 'a' is: ";
		a.makeSound();

		a = cat;
		std::cout << YELLOW << "New type of animal 'a' after instantiate with Cat constructor is: " << GREEN << a.getType() << RESET << std::endl;
		std::cout << YELLOW << "Sound of animal 'a' is: ";
		a.makeSound();

		std::cout << '\n';

		std::cout << BWHITE << "*** Constructors tests - Cat***" << RESET << std::endl;
		Cat	cat1;
		Cat catCopy = cat1;
		Dog random;

		std::cout << YELLOW << "Default type of 'cat1' is: " << GREEN << cat1.getType() << RESET << std::endl;
		std::cout << YELLOW << "Default type of 'catCopy' is: " << GREEN << catCopy.getType() << RESET << std::endl;
		std::cout << YELLOW << "Sound of 'catCopy' is: ";
		catCopy.makeSound();
		std::cout << '\n';

		std::cout << BWHITE << "*** Constructors tests - Dog***" << RESET << std::endl;
		Dog	dog1;
		Dog dogCopy(dog1);

		std::cout << YELLOW << "Default type of 'dog1' is: " << GREEN << dog1.getType() << RESET << std::endl;
		std::cout << YELLOW << "Default type of 'dogCopy' is: " << GREEN << dogCopy.getType() << RESET << std::endl;
		std::cout << YELLOW << "Sound of 'dogCopy' is: ";
		dogCopy.makeSound();
		std::cout << '\n';


	}

	std::cout << BWHITE << "*** SUBJECT - TEST ***\n" << RESET;
	{
		Animal *myCat = new Cat();
		Animal *myDog = new Dog();
		Animal *meta = new Animal();

		std::cout << YELLOW << "type of myCat: " << GREEN << myCat->getType() << RESET << std::endl;
		std::cout << YELLOW << "type of myDog: " << GREEN << myDog->getType() << RESET << std::endl;
		std::cout << YELLOW << "type of meta: " << GREEN << meta->getType() << RESET << std::endl;

		std::cout << "\n";
		std::cout << YELLOW << "Sound of myCat is: ";
		myCat->makeSound();
		std::cout << YELLOW << "Sound of myDog is: ";
		myDog->makeSound();
		std::cout << YELLOW << "Sound of mmeta is: ";
		meta->makeSound();

		std::cout << "\n";
		delete meta;
		delete myDog;
		delete myCat;
	}
		std::cout << BWHITE << "*** WRONGCLASS - TESTS ***\n" << RESET;
	{
		WrongAnimal *bruh = new WrongAnimal();
		WrongAnimal *randomCat = new WrongCat();

		std::cout << YELLOW << "type of bruh: " << GREEN << bruh->getType() << RESET << std::endl;
		std::cout << YELLOW << "type of randomCat: " << GREEN << randomCat->getType() << RESET << std::endl;

		std::cout << "\n";
		std::cout << YELLOW << "Sound of bruh is: ";
		bruh->makeSound();
		std::cout << YELLOW << "Sound of randomCat is: ";
		randomCat->makeSound();

		std::cout << "\n";
		delete bruh;
		delete randomCat;
	}
	return (0);
}