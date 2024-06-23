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

#include "../include/Span.hpp"

static	void	validTest(void)
{
	{
		Span<int>	add(5);
		std::cout << BWHITE << "*** ADD NUMBERS VALID TESTS ***" << RESET << std::endl;
		try
		{
			add.addNumber(20);
			add.addNumber(1);
			add.addNumber(-90);
			add.addNumber(40);
			add.addNumber(4);
		}
		catch (const std::exception &e){
			std::cout << e.what() << std::endl;
		}

		std::cout << BWHITE << "\n*** LONGEST/SHORTEST VALID TESTS ***" << RESET << std::endl;
		try
		{
			std::cout << add.longestSpan() << RESET << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		
		std::cout << '\n'; 
		try
		{
			std::cout << add.shortestSpan() << RESET << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << '\n';
}

static	void	invalidAddNumbersTests(void)
{
	{
		Span<int>	add(2);
		std::cout << BWHITE << "*** INVALID ADDNUMBERS TESTS #1***" << RESET << std::endl;
		try
		{
			add.addNumber(20);
			add.addNumber(50);
			add.addNumber(80); // RIP
		}
		catch (const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	
	std::cout << '\n'; 
	{
		Span<int>	add(0);
		std::cout << BWHITE << "*** INVALID ADDNUMBERS TESTS #2***" << RESET << std::endl;
		try
		{
			add.addNumber(2); // RIP
		}
		catch (const std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << '\n';
}

static	void	invalidLongestShortestTests(void)
{
	{
		Span<int>	add(1);
		std::cout << BWHITE << "*** INVALID LONGEST TESTS***" << RESET << std::endl;
		try
		{
			add.addNumber(20);
			std::cout << add.longestSpan() << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << '\n';
	{
		Span<int>	add(1);
		std::cout << BWHITE << "*** INVALID SHORTEST TESTS***" << RESET << std::endl;
		add.addNumber(20);
		try
		{
			std::cout << add.shortestSpan() << RESET << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << '\n';	
}

static	void	tenThousandElementsOrMore(void)
{
	#ifndef TEST
	return ;
	#endif

	#ifdef TEST
	Span<int>	hundreds(15000);
	try
	{
		srand(time(0));	
		for (int i = 0; i < 15000; i++)
			hundreds.addNumber(rand() % 10000000);
		std::cout << hundreds.longestSpan() << RESET << std::endl;
		std::cout << hundreds.shortestSpan() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	#endif
}

int	main(void)
{
	validTest();
	invalidAddNumbersTests();
	invalidLongestShortestTests();
	tenThousandElementsOrMore();
	return (0);
}
