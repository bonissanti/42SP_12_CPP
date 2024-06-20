/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/20/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/20/2024                   */
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

#include "../include/Array.hpp"

int	main(void)
{
	{
		std::cout << BWHITE << "*** DEEP COPY CONSTRUCTOR TEST ***" << RESET << std::endl;
		Array<int>	value(2);

		value[0] = 20;
		value[1] = 42;

		Array<int>	copy(value);
		value[0] = 12;
		try
		{
			std::cout << YELLOW << "copy[0]: " << GREEN << copy[0] << RESET << std::endl;
			std::cout << YELLOW << "copy[1]: " << GREEN << copy[1] << RESET << std::endl;
			std::cout << YELLOW << "value[0]: " << GREEN << value[0] << RESET << " // new value after deep copy" << std::endl;
			std::cout << YELLOW << "copy[0]: " << GREEN << copy[0] << RESET " // don't change"<< std::endl;

		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		std::cout << BWHITE << "*** DEEP COPY ASSIGNMENT OPERATOR TEST ***" << RESET << std::endl;
		Array<int>	value(2);

		value[0] = 20;
		value[1] = 42;

		Array<int>	copy(2);
		copy = value;
		value[0] = 102;
		try
		{
			std::cout << YELLOW << "copy[0]: " << GREEN << copy[0] << RESET << std::endl;
			std::cout << YELLOW << "copy[1]: " << GREEN << copy[1] << RESET << std::endl;
			std::cout << YELLOW << "value[0]: " << GREEN << value[0] << RESET << " // new value after deep copy" << std::endl;
			std::cout << YELLOW << "copy[0]: " << GREEN << copy[0] << RESET " // don't change"<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n' << std::endl;
	{
		std::cout << BWHITE << "*** INT TEST #1***" << RESET << std::endl;
		Array<int>	value(2);

		value[0] = 20;
		value[1] = 42;
		try
		{
			std::cout << YELLOW << "value[1]: " << GREEN << value[1] << RESET << std::endl;
			std::cout << YELLOW << "value[8]: " << GREEN << value[8] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	
	std::cout << '\n';
	{
		std::cout << BWHITE << "*** INT TEST #2***" << RESET << std::endl;
		Array<int>	value(10);

		srand(time(0));
		for (int i = 0; i < 10; i++)
			value[i] = rand() % 100;

		try
		{
			for (int i = 0; i < 10; i++)
				std::cout << YELLOW << "value[" << i << "]: " << GREEN << value[i] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << BWHITE << "\n-----> Invalid test <-----" << std::endl;
		try
		{
			for (int i = 10; i < 20; i++)
				std::cout << YELLOW << "value[" << i << "]: " GREEN << value[i] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
		
	std::cout << '\n';
	{
		std::cout << BWHITE << "*** CONST CHAR* TEST ***" << RESET << std::endl;
		Array<const char *>	value(2);

		value[0] = "bruh";
		value[1] = "kachow";

		try
		{
			std::cout << YELLOW << "value[0]: " << GREEN << value[0] << RESET << std::endl;
			std::cout << YELLOW << "value[1]: " << GREEN << value[1] << RESET << std::endl;
			std::cout << YELLOW << "value[8]: " << GREEN << value[8] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		std::cout << BWHITE << "*** STRING TEST ***" << RESET << std::endl;
		Array<std::string>	value(2);

		value[0] = "MACHINIMA PARTY";
		value[1] = "YouTube Prime";

		try
		{
			std::cout << YELLOW << "value[0]: " << GREEN << value[0] << RESET << std::endl;
			std::cout << YELLOW << "value[1]: " << GREEN << value[1] << RESET << std::endl;
			std::cout << YELLOW << "value[8]: " << GREEN << value[8] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		std::cout << BWHITE << "*** FLOAT TEST #2***" << RESET << std::endl;
		Array<float>	value(10);

		srand(time(0));
		for (int i = 0; i < 10; i++)
			value[i] = rand() % 100;

		try
		{
			std::cout.precision(2);
			for (int i = 0; i < 10; i++)
				std::cout << YELLOW << "value[" << i << "]: " << GREEN << std::fixed << value[i] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		std::cout << BWHITE << "\n-----> Invalid test <-----" << std::endl;
		try
		{
			for (int i = 10; i < 20; i++)
				std::cout << YELLOW << "value[" << i << "]: " GREEN << value[i] << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}return (0);
}
