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

static	void	constructorTests()
{
	{
		std::cout << BWHITE << "*** DEEP COPY CONSTRUCTOR TEST ***" << RESET << std::endl;
		Array<int>	value(2);

		value[0] = 20; // original values
		value[1] = 42;

		Array<int>	copy(value);
		value[0] = 12; // changing value
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

		value[0] = 20; // original values
		value[1] = 42;

		Array<int>	copy(2);
		copy = value;
		value[0] = 102; // changing value
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
		std::cout << BWHITE << "*** EMPTY CONSTRUCTOR TEST ***" << RESET << std::endl;
		Array<int> empty;

		std::cout << YELLOW "Size of array is: " << GREEN << empty.size() << RESET << std::endl;
	}
}

static void	intTests(void)
{
	{
		std::cout << BWHITE << "*** INT TEST #1***" << RESET << std::endl;
		Array<int>	value(2);

		value[0] = 20;
		value[1] = 42;
		try
		{
			std::cout << YELLOW << "value[1]: " << GREEN << value[1] << RESET << std::endl;
			std::cout << YELLOW << "value[8]: " << GREEN << value[8] << RESET << std::endl; // accessing position invalid
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

		std::cout << YELLOW << "\n-----> Invalid test - accessing invalid position <-----" << std::endl;
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
}

static	void	charStringTests(void)
{
	std::cout << '\n';
	{
		std::cout << BWHITE << "*** CHAR TEST ***" << RESET << std::endl;
		Array<char>	value(2);

		value[0] = 'a';
		value[1] = 'b';

		try
		{
			std::cout << YELLOW << "value[0]: " << GREEN << value[0] << RESET << std::endl;
			std::cout << YELLOW << "value[1]: " << GREEN << value[1] << RESET << std::endl;
			std::cout << YELLOW << "value[8]: " << GREEN << value[8] << RESET << std::endl; // invalid position
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
}

static void floatTest(void)
{
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

		std::cout << YELLOW << "\n-----> Invalid test - accessing invalid position <-----" << std::endl;
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
}

static	void	constTypeTest(void)
{
	std::cout << BWHITE << "*** CONST INT #2***" << RESET << std::endl;
	Array<const int> value(10);
	std::cout << GREEN << value << RESET << std::endl;
}

int	main(void)
{
	constructorTests();
	std::cout << '\n';
	intTests();
	std::cout << '\n';
	charStringTests();
	std::cout << '\n';
	floatTest();
	std::cout << '\n';
	constTypeTest();
	return (0);
}
