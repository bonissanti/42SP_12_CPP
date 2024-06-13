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
#include "../include/Form.hpp"

static	void	printingInfos(const Form *a, const Form *b, const Form *c)
{
	#ifndef TEST
	(void) a;
	(void) b;
	(void) c;
	#endif

	#ifdef TEST
	std::cout << "'a' name is: " << a->getName() << std::endl;
	std::cout << "'b' name is: " << b->getName() << std::endl;
	std::cout << "'c' name is: " << c->getName() << std::endl;

	std::cout << "'a' grade to sign: " << a->getToSign() << std::endl;
	std::cout << "'b' grade to sign: " << b->getToSign() << std::endl;
	std::cout << "'c' grade to sign: " << c->getToSign() << std::endl;

	std::cout << "'a' grade to execute: " << a->getExecute() << std::endl;
	std::cout << "'b' grade to execute: " << b->getExecute() << std::endl;
	std::cout << "'c' grade to execute: " << c->getExecute() << std::endl;
	#endif
}

int main(void)
{
	{
		try
		{
			std::cout << BLACK << "**** TEST INITIALIZER CONSTRUCTORS (only in test mode) ****" << RESET << std::endl;
			Form	a;
			Form	b(a);
			Form 	c = b;
			a = Form("TEST", 150, 150);
			printingInfos(&a, &b, &c);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		std::cout << BLACK << "**** TEST INVALID GRADE ****" << RESET << std::endl;
		try{
			Form	a("Lower grade to sign", 151, 50);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}

		try{
			Form	b("Higher grade to sign", 0, 50);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}

		try{
			Form	c("Lower grade to execute", 50, 151);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		
		try{
			Form	d("Higher grade to execute", 50, 0);
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
			Form a("War declaration", 30, 40);
			Bureaucrat	Putin("Putin", 15);
			a.beSigned(Putin);

			Form b("Brazilian republic", 50, 70);
			Bureaucrat	Fonseca("D.Fonseca", 45);
			b.beSigned(Fonseca);

			Form c("Resignation letter", 150, 50);
			Bureaucrat	hr("HR", 150);
			c.beSigned(hr);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << BLACK << "**** TEST INVALID SIGNS ****" << RESET << std::endl;
			Form a("Sell Company", 3, 3);
			Bureaucrat	intern("Carlitos the Intern", 150);
			a.beSigned(intern);	

		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}

		try
		{
			Form b("Buy a house", 149, 149);
			Bureaucrat	strangeGuy("Random guy", 148);
			strangeGuy--;
			strangeGuy--;
			b.beSigned(strangeGuy);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	return (0);		
}