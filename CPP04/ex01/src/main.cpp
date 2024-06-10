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

#include "../include/CatDog.hpp"
#include "../include/WrongCat.hpp"

int	main(void)
{
	{
		std::cout << "CONSTRUCT/DESTRUCT TEST" << std::endl;
		Animal	*myDog = new Dog();

		delete myDog;
	}

	std::cout << "\n";
	{
		std::cout << "BRAIN TEST" << std::endl;
		Cat *frederico = new Cat();
		std::cout << "\n";
		Dog *preto = new Dog();

		std::cout << "\n";
		frederico->setBrain(7, "Bro, where's my toy?");
		preto->setBrain(5, "Me deixa sair para a rua, humano");

		std::cout << "Cat says: " << frederico->getBrain(5) << std::endl;
		std::cout << "Dog says: " << preto->getBrain(4) << std::endl;
		std::cout << "\n";

		delete frederico;
		std::cout << "\n";
		delete preto;
	}

	std::cout << "\n";
	{
		std::cout << "SUBJECT TEST" << std::endl;

		Animal *animal[100];

		for (int i = 0; i < 50; i++)
			animal[i] = new Cat();

		for (int i = 50; i < 100; i++)
			animal[i] = new Dog();

		std::cout << "\n--------------------> Printing type <--------------------\n";

		for (int i = 0; i < 100; i++)
				std::cout << animal[i]->getType() << std::endl;

		std::cout << "\n--------------------> Destructors calls <--------------------\n";

		for (int i = 0; i < 100; i++)
			delete animal[i];
	}

	std::cout << "\n";
	{
		std::cout << "DEEP COPY TEST" << std::endl;

		Cat *myCat1 = new Cat();
		Cat *myCat2 = new Cat();


		myCat1->setBrain(2, "Eu odeio aquele myCat2"); 
		myCat2->setBrain(2, "O myCat1 é muito parça"); 

		std::cout << myCat1->getBrain(1) << std::endl;
		std::cout << myCat2->getBrain(1) << std::endl;

		 

		std::cout << "\nSHALLOW COPY TEST" << std::endl;

		Dog *myDog1 = new Dog();
		Dog *myDog2 = new Dog();

		myDog1->setBrain(2, "Humano pulguento");

		*myDog2 = *myDog1;
		std::cout << myDog1->getBrain(1) << std::endl;
		std::cout << myDog2->getBrain(1) << std::endl;

		myDog1->setBrain(2, "Vou arrancar sua perna");
		std::cout << myDog2->getBrain(1) << std::endl; //At shallow copy, this will print "Vou arrancar sua perna"

		delete myCat1;
		delete myCat2;
		delete myDog1;
		delete myDog2;
	}


	
	return (0);
}