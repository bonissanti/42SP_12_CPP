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

int	main(void)
{
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
			std::cout << BLACK << "**** INVALID EXECUTE TEST ****" << RESET << std::endl;
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
	return (0);
}

// int main(void)
// {
// 	{
// 		std::cout << BLACK << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
// 		Form	a;
// 		Form	b(a);
// 		Form 	c = b;
// 		a = Form("TEST", 150, 150);
// 		printingInfos(&a, &b, &c);
// 	}

// 	std::cout << '\n';
// 	{
// 		std::cout << BLACK << "**** TEST INVALID GRADE ****" << RESET << std::endl;
// 		Form	a("Lower grade to sign", 151, 50);
// 		Form	b("Higher grade to sign", 0, 50);
// 		Form	c("Lower grade to execute", 50, 151);
// 		Form	d("Higher grade to execute", 50, 0);
// 	}

// 	std::cout << '\n';
// 	{
// 		std::cout << BLACK << "**** TEST BUREAUCRAT SIGNS FORM ****" << RESET << std::endl;
// 		Form a("Declaração de guerra", 30, 40);
// 		Bureaucrat	Putin("Putin", 15);
// 		a.beSigned(Putin);

// 		Form b("Brazilian republic", 50, 70);
// 		Bureaucrat	Fonseca("D.Fonseca", 45);
// 		b.beSigned(Fonseca);

// 		Form c("Demissional doc", 150, 50);
// 		Bureaucrat	hr("HR", 150);
// 		c.beSigned(hr);
// 	}

// 	std::cout << '\n';
// 	{
// 		std::cout << BLACK << "**** TEST INVALID SIGNS ****" << RESET << std::endl;
// 		Form a("Sell Company", 3, 3);
// 		Bureaucrat	intern("Carlitos the Intern", 150);
// 		a.beSigned(intern);	

// 		Form b("Buy a house", 149, 149);
// 		Bureaucrat	strangeGuy("Random guy", 148);
// 		strangeGuy--;
// 		strangeGuy--;
// 		b.beSigned(strangeGuy);
// 	}
// 	return (0);		
// }