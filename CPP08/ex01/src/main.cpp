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

static	void	subjectTest(void)
{
	std::cout << BWHITE << "*** SUBJECT TEST ***" << RESET << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << '\n';

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	std::cout << '\n';
}

static	void	validTest(void)
{
	{
		Span	add(5);
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
		Span	add(2);
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
		Span	add(0);
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
		Span	add(1);
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
		Span	add(1);
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
	std::list<int> thousand;
	Span	sp(15000);
	try
	{
		srand(time(0));	
		for (int i = 0; i < 15000; i++)
			thousand.push_back(rand() % 10000000);
		sp.addRange(thousand.begin(), thousand.end());
		std::cout << '\n';
		std::cout << sp.longestSpan() << RESET << std::endl;
		std::cout << sp.shortestSpan() << RESET << std::endl;
		std::cout << YELLOW << "The actual size is: " GREEN << sp.getCapacity() << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	#endif
}

int	main(void)
{
	subjectTest();
	validTest();
	invalidAddNumbersTests();
	invalidLongestShortestTests();
	tenThousandElementsOrMore();
	return (0);
}
