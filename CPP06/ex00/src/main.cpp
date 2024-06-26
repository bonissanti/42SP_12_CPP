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

#include "../include/ScalarConverter.hpp"

static	void	myTests(void)
{
	{
		std::cout << BWHITE << "\n*** ALPHABET TESTS ***" << RESET << std::endl;

		std::cout << BWHITE << "Testing: *" << RESET << std::endl;
		ScalarConverter::converter("*");
		endl(std::cout);

		std::cout << BWHITE << "Testing: 50" << RESET << std::endl;
		ScalarConverter::converter("50");
		endl(std::cout);

		std::cout << BWHITE << "Testing: a" << RESET << std::endl;
		ScalarConverter::converter("a");
		endl(std::cout);

		std::cout << BWHITE << "Testing: !" << RESET << std::endl;
		ScalarConverter::converter("!");
		endl(std::cout);
	}

	{
		std::cout << BWHITE << "\n*** NUMERICAL tests ***" << RESET << std::endl;

		std::cout << BWHITE << "Testing: 3" << RESET << std::endl;
		ScalarConverter::converter("3");
		endl(std::cout);

		std::cout << BWHITE << "Testing: 0" << RESET << std::endl;
		ScalarConverter::converter("0");
		endl(std::cout);

		std::cout << BWHITE << "Testing: -42" << RESET << std::endl;
		ScalarConverter::converter("-42");
		endl(std::cout);

		std::cout << BWHITE << "Testing: -1.2345675f" << RESET << std::endl;
		ScalarConverter::converter("-1.23457f");
		endl(std::cout);

		std::cout << BWHITE << "Testing: -1.2345675" << RESET << std::endl;
		ScalarConverter::converter("-1.2345675");
		endl(std::cout);

		std::cout << BWHITE << "Testing: 2147483647" << RESET << std::endl;
		ScalarConverter::converter("2147483647");
		endl(std::cout);	

		std::cout << BWHITE << "Testing: -2147483648" << RESET << std::endl;
		ScalarConverter::converter("-2147483648");
		endl(std::cout);	

		std::cout << BWHITE << "Testing: +inf" << RESET << std::endl;
		ScalarConverter::converter("+inf");
		endl(std::cout);	

		std::cout << BWHITE << "Testing: -inf" << RESET << std::endl;
		ScalarConverter::converter("-inf");
		endl(std::cout);	

		std::cout << BWHITE << "Testing: nan" << RESET << std::endl;
		ScalarConverter::converter("nan");
		endl(std::cout);	
	}

	{
		std::cout << BWHITE << "\n*** OTHER tests ***" << RESET << std::endl;

		std::cout << BWHITE << "Testing: 3.0" << RESET << std::endl;
		ScalarConverter::converter("3.0");
		endl(std::cout);

		std::cout << BWHITE << "Testing: +50.1f" << RESET << std::endl;
		ScalarConverter::converter("+50.1f");
		endl(std::cout);

		std::cout << BWHITE << "Testing: +50.1" << RESET << std::endl;
		ScalarConverter::converter("+50.1");
		endl(std::cout);

		std::cout << BWHITE << "Testing: -100" << RESET << std::endl;
		ScalarConverter::converter("-100");
		endl(std::cout);

		std::cout << BWHITE << "Testing: abc" << RESET << std::endl;
		ScalarConverter::converter("abc");
		endl(std::cout);

		std::cout << BWHITE << "Testing: bruh" << RESET << std::endl;
		ScalarConverter::converter("bruh");
	}
}

int	main(int argc, char **argv)
{
	std::string	charToString;
	std::string line;

	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return (1);
	}
	charToString = argv[1];
	ScalarConverter::converter(charToString);


	std::cout << BWHITE << "\nWould you like to run my tests? [y]/[n]" << RESET << std::endl;
	std::cin >> line;
	if (line == "y")
		myTests();
	return (0);
}
