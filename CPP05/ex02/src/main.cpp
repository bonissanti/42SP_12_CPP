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

static void	testPresidential()
{
	std::cout << BWHITE << "PRESIDENTIAL TEST ########################################" << RESET << std::endl;
	{
		try
		{
			std::cout << YELLOW << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
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
			std::cout << YELLOW << "**** VALID TESTS ****" << RESET << std::endl;
			Presidential 	order("Amnesty Order");
			Bureaucrat	bob("Bob", 24); // need at least 25 to sign
			bob.signForm(order);

			Bureaucrat	tim("Tim", 3); // needs at least 5 to execute
			tim.executeForm(order);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** INVALID SIGN/EXECUTE ****" << RESET << std::endl;
			Presidential 	order("Amnesty Order");
			Bureaucrat	bob("Bob", 50);  // need at least 25 to sign
			bob.signForm(order);

			Bureaucrat	tim("Tim", 20); // needs at least 5 to execute
			tim.executeForm(order);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** DON'T SIGN BUT HAS GRADE TO EXECUTE (won't) ****" << RESET << std::endl;
			Presidential 	donation("Donation");
			Bureaucrat	carlitos("Carlitos", 35);  // need at least 25 to sign
			carlitos.signForm(donation);

			Bureaucrat	rob("Rob", 4); // needs at least 5 to execute
			rob.executeForm(donation);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** INVALID EXECUTE ONLY ****" << RESET << std::endl;
			Presidential 	order("Order");
			Bureaucrat	random("Random", 20);  // need at least 25 to sign
			random.signForm(order);

			Bureaucrat	senate("senate", 50); // needs at least 5 to execute
			senate.executeForm(order);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
}

static void	testRobotomy()
{
	std::cout << BWHITE << "ROBOTOMY TEST ########################################" RESET << std::endl;
	{
		try
		{
			std::cout << YELLOW << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
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
			std::cout << YELLOW << "**** VALID TESTS ****" << RESET << std::endl;
			Robotomy 	robotomy("Robotomy");
			Bureaucrat	marvin("Marvin", 40); // need at least 70 to sign
			marvin.signForm(robotomy);

			Bureaucrat	tim("Tim Man", 20); // needs at least 45 to execute
			tim.executeForm(robotomy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** INVALID SIGN/EXECUTE ****" << RESET << std::endl;
			Robotomy 	robotomy("Robotomy2");
			Bureaucrat	random("Random", 73);  // need at least 70 to sign
			random.signForm(robotomy);

			Bureaucrat	aGuy("A guy", 80); // needs at least 45 to execute
			aGuy.executeForm(robotomy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** DON'T SIGN BUT HAS GRADE TO EXECUTE (won't) ****" << RESET << std::endl;
			Robotomy 	robotomy("Robotomy3");
			Bureaucrat	buzz("Buzz", 90);  // need at least 70 to sign
			buzz.signForm(robotomy);

			Bureaucrat	bruh("Bruh", 60); // needs at least 45 to execute
			bruh.executeForm(robotomy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** INVALID EXECUTE ONLY ****" << RESET << std::endl;
			Robotomy 	robotomy("More Robotomy");
			Bureaucrat	randomAgain("RandomAgain", 30);  // need at least 70 to sign
			randomAgain.signForm(robotomy);

			Bureaucrat	lazy("lazy", 50); // needs at least 45 to execute
			lazy.executeForm(robotomy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
}

static void	testShrubbery()
{
	std::cout << BWHITE << "SHRUBBERY TEST ########################################" << RESET << std::endl;
	{
		try
		{
			std::cout << YELLOW << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
			Shrubbery a;
			Shrubbery b(a);
			Shrubbery c = b;
			a = Shrubbery("test");
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** TEST BUREAUCRAT SIGNS FORM ****" << RESET << std::endl;
			Shrubbery 	a("Plant new shrubs");
			Bureaucrat	owner("Owner", 40);
			owner.signForm(a);

			Bureaucrat	gardener("Gardener", 70);
			gardener.executeForm(a);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** INVALID SIGN AND EXECUTE TEST ****" << RESET << std::endl;
			Shrubbery 	a("Put fire");
			Bureaucrat	crazy("Crazy", 150);
			crazy.signForm(a);

			Bureaucrat	gardener("Gardener", 70);
			gardener.executeForm(a);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** INVALID EXECUTE ONLY ****" << RESET << std::endl;
			Shrubbery 	a("Lazy-Gardener");
			Bureaucrat	bruh("bruh", 30);
			bruh.signForm(a);

			Bureaucrat	idk("IDK", 0);
			idk.executeForm(a);
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