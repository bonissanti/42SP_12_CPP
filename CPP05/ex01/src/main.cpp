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

int main(void)
{
	{
		try
		{
			std::cout << YELLOW << "**** TEST INITIALIZER CONSTRUCTORS (infos about them only in test mode) ****" << RESET << std::endl;
			Form	a;
			Form	b(a);
			Form 	c = b;
			a = Form("TEST", 150, 150);
			std::cout << YELLOW << "-----> Printing infos about forms <-----" << std::endl;
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << c << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		std::cout << YELLOW << "**** TEST INVALID GRADE ****" << RESET << std::endl;
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
			std::cout << YELLOW << "**** TEST BUREAUCRAT SIGNS FORM ****" << RESET << std::endl;
			Form a("War declaration", 30, 40);
			Bureaucrat	putin("Putin", 1);
			putin.signForm(a);

			Form b("Brazilian republic", 50, 70);
			Bureaucrat	fonseca("D.Fonseca", 45);
			fonseca.signForm(b);

			Form c("Resignation letter", 150, 50);
			Bureaucrat	hr("HR", 150);
			hr.signForm(c);
			std::cout << '\n';

			std::cout << YELLOW << "-----> Printing infos about Bureaucrats <-----" << RESET << std::endl;
			std::cout << putin << std::endl;
			std::cout << fonseca << std::endl;
			std::cout << hr << std::endl;

			std::cout << YELLOW << "-----> Printing infos about forms <-----" << RESET << std::endl;
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			std::cout << c << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}

	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "**** TEST INVALID SIGNS ****" << RESET << std::endl;
			Form a("Sell Company", 3, 3);
			Bureaucrat	intern("Carlitos the Intern", 150);
			intern.signForm(a);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}

		try
		{
			Form b("Buy a house", 149, 149);
			Bureaucrat	strangeGuy("Random guy", 2);
			strangeGuy++;
			strangeGuy++;
			strangeGuy.signForm(b);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	return (0);		
}