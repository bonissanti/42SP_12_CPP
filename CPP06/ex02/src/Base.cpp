/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/10/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/10/2024                   */
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

#include "../include/Base.hpp"

static void	printDebug(const std::string& msg);

Base::~Base(){
}

Base	*generate(void)
{
	int index;

	srand(time(0));
	index = rand() % 3 + 1;
	switch (index)
	{
		case 1:
		std::cout << GREEN << "Instanting Base pointer with Class A object" << RESET << std::endl;
		return (new A);
		break;

		case 2:
		std::cout << GREEN << "Instanting Base pointer with Class B object" << RESET << std::endl;
		return (new B);
		break;
		
		case 3:
		std::cout << GREEN << "Instanting Base pointer with Class C object" << RESET << std::endl;
		return (new C);
		break;

		default:
		std::cout << RED << "This is not a valid object" << RESET << std::endl;
		break;
	}	
	return (NULL);
}

void	identity(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "Base pointer to object from Class A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "Base pointer to object from Class B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "Base pointer to object from Class C" << RESET << std::endl;
	else
		std::cout << RED << "Invalid pointer!" << RESET << std::endl;
}

void	identity(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
			std::cout << GREEN << "Base reference to object from Class A" << RESET << std::endl;
		return ;	
	}
	catch(const std::exception& e){
		printDebug("Invalid object A - std::bad_cast");
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << GREEN << "Base reference to object from Class B" << RESET << std::endl;
		return ;

	}
	catch(const std::exception& e){
		printDebug("Invalid object B - std::bad_cast");
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << GREEN << "Base reference to object from Class C" << RESET << std::endl;
		return ;
	}
	catch(const std::exception& e){
		std::cout << RED << "Invalid reference! Bro, stop trying to break my program :(" << RESET << std::endl;
	}	
}

static void	printDebug(const std::string& msg)
{
	#ifndef TEST
	(void)msg;
	#endif

	#ifdef TEST
	std::cout << RED << msg << RESET << std::endl;
	#endif
}