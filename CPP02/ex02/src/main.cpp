/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/06/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/06/2024                   */
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

#include "../include/Fixed.hpp"

int	main(void)
{
	{
		std::cout << "Test #1 - pre and post increment" << std::endl;
		Fixed a;
		Fixed const	b(Fixed(5.05f) * Fixed(2));

		std::cout << "a now: " << a << std::endl;
		std::cout << "a pre increment: " << ++a << std::endl; //a 
		std::cout << "a now: " << a << std::endl;
		std::cout << "a post increment: " << a++ << std::endl;
		std::cout << "a now: " << a << std::endl;
		std::cout << "b now: " << b << std::endl;
		std::cout << "a pre decrement: " << --a << std::endl;
		std::cout << "a post decrement: " << a-- << std::endl;
		std::cout << "a now: " << a << std::endl;
		std::cout << "max between a and b: " << Fixed::max(a, b) << std::endl;
	}

	{
		std::cout << "\nTest #2 - max/min: const vs. non const" << std::endl;
		Fixed 	a(2);
		Fixed 	b(3);

		Fixed	min1 = Fixed::min(a, b);
		std::cout << "Return min1: " << min1 << std::endl;
		std::cout << "After pre-increment min1: " << ++min1 << std::endl;
		std::cout << "Min1 now: " << min1 << std::endl;

		Fixed const min2 = Fixed::min(a, b);
		std::cout << "Return const min2: " << min2 << std::endl;
	}

	std::cout << "\n";
	{
		std::cout << "\nTest #3 - conditional operators" << std::endl;
		Fixed	a(6);
		Fixed	b(Fixed(4) + Fixed(2));

		if (a != b)
			std::cout << "Different | a: " << a << " and b: " << b << std::endl;
		else if (a == b)
			std::cout << "Equals | a: " << a << " and b: " << b << std::endl;

		a = (Fixed(a) * Fixed(10));
		if (a > b)
			std::cout << "A is greater than B | a: " << a << " and b: " << b << std::endl;
		else if (a < b)
			std::cout << "B is greater than A | a: " << a << " and b: " << b << std::endl;
	}
	return (0);
}