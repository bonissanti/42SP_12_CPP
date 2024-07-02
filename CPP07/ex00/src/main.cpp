/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/19/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/19/2024                   */
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

#include "../include/whatever.hpp"

int	main(void)
{
	{
		std::cout << BWHITE << "*** SUBJECT TEST - INT ***\n" << RESET << std::endl;
		int	a = 2;
		int	b = 3;

		std::cout << YELLOW << "original a = " << GREEN << a << YELLOW << ", original b is: " << GREEN << b << std::endl;
		::swap(a, b);
		std::cout << YELLOW << "swapped a = " << GREEN << a << YELLOW << ", swapped b is: " << GREEN << b << std::endl;
		std::cout << YELLOW << "min(a, b) = " << GREEN << ::min(a, b) << std::endl;
		std::cout << YELLOW << "max(a, b) = " << GREEN << ::max(a, b) << std::endl;
	}

	std::cout << std::endl;
	{
		std::cout << BWHITE << "*** SUBJECT TEST - STRING ***\n" << RESET << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";

		std::cout << YELLOW << "original c = " << GREEN << c << YELLOW << ", original d is: " << GREEN << d << std::endl;
		::swap(c, d);
		std::cout << YELLOW << "swapped c = " << GREEN << c << YELLOW << ", swapped d is: " << GREEN << d << std::endl;
		std::cout << YELLOW << "min(c, d) = " << GREEN << ::min(c, d) << std::endl;
		std::cout << YELLOW << "max(c, d) = " << GREEN << ::max(c, d) << std::endl;
	}

	std::cout << std::endl;
	{
		std::cout << BWHITE << "*** TEST - FLOAT ***\n" << RESET << std::endl;
		float e = 89.0f;
		float f = 89.1f;

		std::cout << YELLOW << "original e = " << GREEN << e << YELLOW << ", original f is: " << GREEN << f << std::endl;
		::swap(e, f);
		std::cout << YELLOW << "swapped e = " << GREEN << e << YELLOW << ", swapped f is: " << GREEN << f << std::endl;
		std::cout << YELLOW << "min(e, f) = " << GREEN << ::min(e, f) << std::endl;
		std::cout << YELLOW << "max(e, f) = " << GREEN << ::max(e, f) << std::endl;
	}	

	std::cout << std::endl;
	{
		std::cout << BWHITE << "*** TEST - CHAR ***\n" << RESET << std::endl;
		char g = 'g';
		char h = 'h';

		std::cout << YELLOW << "original g = " << GREEN << g << YELLOW << ", original h is: " << GREEN << h << std::endl;
		::swap(g, h);
		std::cout << YELLOW << "swapped g = " << GREEN << g << YELLOW << ", swapped h is: " << GREEN << h << std::endl;
		std::cout << YELLOW << "min(g, h) = " << GREEN << ::min(g, h) << std::endl;
		std::cout << YELLOW << "max(g, h) = " << GREEN << ::max(g, h) << std::endl;
	}	
	return (0);
}
