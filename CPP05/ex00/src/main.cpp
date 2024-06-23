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

int	main(void)
{
	{
		try
		{
			std::cout << YELLOW << "*** TEST INSTANTIATE WRONG HIGH VALUE ***" << RESET << std::endl;
			Bureaucrat carlitos("Carlitos", 0);
			std::cout << carlitos << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "*** TEST INSTANTIATE WRONG LOW VALUE ***" << RESET << std::endl;
			Bureaucrat bob("Bob", 151);
			std::cout << bob << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "*** TEST HIGH GRADE ***" << RESET << std::endl;
			Bureaucrat random("Random", 11);
			std::cout << random << std::endl;
			random++;

			std::cout << random << std::endl;
			random++;

			std::cout << random << std::endl;
			random--;

			std::cout << random << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "*** TEST LOW GRADE ***" << RESET << std::endl;
			Bureaucrat steven("Steven", 140);
			std::cout << steven << std::endl;
			steven--;

			std::cout << steven << std::endl;
			steven--;

			std::cout << steven << std::endl;
			steven++;

			std::cout << steven << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "*** TEST INVALID DECREMENT GRADE ***" << RESET << std::endl;
			Bureaucrat carlitos("Carlitos", 150);
			std::cout << carlitos << std::endl;
			carlitos--;
			std::cout << carlitos << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		
	}

	std::cout << '\n';
	{
		try
		{
			std::cout << YELLOW << "*** TEST INVALID INCREMENT GRADE ***" << RESET << std::endl;
			Bureaucrat bob("Bob", 1);
			std::cout << bob << std::endl;
			bob++;
			std::cout << bob << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}