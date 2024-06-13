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

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

// static	void	printingInfos(const Form *a, const Form *b, const Form *c)
// {
// 	#ifndef TEST
// 	(void) a;
// 	(void) b;
// 	(void) c;
// 	#endif

// 	#ifdef TEST
// 	std::cout << "'a' name is: " << a->getName() << std::endl;
// 	std::cout << "'b' name is: " << b->getName() << std::endl;
// 	std::cout << "'c' name is: " << c->getName() << std::endl;

// 	std::cout << "'a' grade to sign: " << a->getToSign() << std::endl;
// 	std::cout << "'b' grade to sign: " << b->getToSign() << std::endl;
// 	std::cout << "'c' grade to sign: " << c->getToSign() << std::endl;

// 	std::cout << "'a' grade to execute: " << a->getExecute() << std::endl;
// 	std::cout << "'b' grade to execute: " << b->getExecute() << std::endl;
// 	std::cout << "'c' grade to execute: " << c->getExecute() << std::endl;
// 	#endif
// }

static void	testPresidential()
{
	std::cout << BYELLOW << "PRESIDENTIAL TEST ########################################" << RESET << std::endl;
	{
		try
		{
			std::cout << BLACK << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
			Presidential a;
			Presidential b(a);
			Presidential c = b;
			a = Presidential("College");
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** VALID TESTS ****" << RESET << std::endl;
			Presidential 	order("Amnesty Order");
			Bureaucrat	bob("Bob", 24); // need at least 25 to sign
			order.beSigned(bob);

			Bureaucrat	tim("Tim", 3); // needs at least 5 to execute
			order.execute(tim);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** INVALID SIGN/EXECUTE ****" << RESET << std::endl;
			Presidential 	order("Amnesty Order");
			Bureaucrat	bob("Bob", 50);  // need at least 25 to sign
			order.beSigned(bob);

			Bureaucrat	tim("Tim", 20); // needs at least 5 to execute
			order.execute(tim);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** DON'T SIGN BUT HAS GRADE TO EXECUTE (won't) ****" << RESET << std::endl;
			Presidential 	order("Order");
			Bureaucrat	random("Random", 39);  // need at least 25 to sign
			order.beSigned(random);

			Bureaucrat	gardener("Gardener", 4); // needs at least 5 to execute
			order.execute(gardener);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** INVALID EXECUTE ONLY ****" << RESET << std::endl;
			Presidential 	order("Order");
			Bureaucrat	random("Random", 20);  // need at least 25 to sign
			order.beSigned(random);

			Bureaucrat	senate("senate", 50); // needs at least 5 to execute
			order.execute(senate);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
}

static void	testRobotomy()
{
	std::cout << BYELLOW << "ROBOTOMY TEST ########################################" RESET << std::endl;
	{
		try
		{
			std::cout << BLACK << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
			Robotomy a;
			Robotomy b(a);
			Robotomy c = b;
			a = Robotomy("College");
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** VALID TESTS ****" << RESET << std::endl;
			Robotomy 	robotomy("Presidential");
			Bureaucrat	marvin("Marvin", 40); // need at least 70 to sign
			robotomy.beSigned(marvin);

			Bureaucrat	tim("Tim Man", 20); // needs at least 45 to execute
			robotomy.execute(tim);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** INVALID SIGN/EXECUTE ****" << RESET << std::endl;
			Robotomy 	robotomy("Robotomy");
			Bureaucrat	owner("", 73);  // need at least 70 to sign
			robotomy.beSigned(owner);

			Bureaucrat	gardener("Gardener", 20); // needs at least 45 to execute
			robotomy.execute(gardener);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** DON'T SIIGN BUT HAS GRADE TO EXECUTE (won't) ****" << RESET << std::endl;
			Robotomy 	robotomy("Robotomy");
			Bureaucrat	owner("", 53);  // need at least 70 to sign
			robotomy.beSigned(owner);

			Bureaucrat	gardener("Gardener", 60); // needs at least 45 to execute
			robotomy.execute(gardener);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** INVALID EXECUTE ONLY ****" << RESET << std::endl;
			Robotomy 	robotomy("Robotomy");
			Bureaucrat	random("Random", 30);  // need at least 70 to sign
			robotomy.beSigned(random);

			Bureaucrat	lazy("lazy", 50); // needs at least 45 to execute
			robotomy.execute(lazy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
}

static void	testShrubbery()
{
	std::cout << BYELLOW << "SHRUBBERY TEST ########################################" << RESET << std::endl;
	{
		try
		{
			std::cout << BLACK << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
			Shrubbery a;
			Shrubbery b(a);
			Shrubbery c = b;
			a = Shrubbery("College");
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** TEST BUREAUCRAT SIGNS FORM ****" << RESET << std::endl;
			Shrubbery 	a("Cut the garden");
			Bureaucrat	owner("Owner", 40);
			a.beSigned(owner);

			Bureaucrat	gardener("Gardener", 70);
			a.execute(gardener);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** INVALID SIGN AND EXECUTE TEST ****" << RESET << std::endl;
			Shrubbery 	a("Garden");
			Bureaucrat	owner("Owner", 150);
			a.beSigned(owner);

			Bureaucrat	gardener("Gardener", 70);
			a.execute(gardener);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** INVALID EXECUTE ONLY ****" << RESET << std::endl;
			Shrubbery 	a("Lazy-Gardener");
			Bureaucrat	owner("Owner", 30);
			a.beSigned(owner);

			Bureaucrat	lazy("lazy", 0);
			a.execute(lazy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
}

int	main(void)
{
	std::cout << '\n';
	testShrubbery();
	std::cout << '\n';
	testRobotomy();
	std::cout << '\n';
	testPresidential();
	std::cout << '\n';
	return (0);
}