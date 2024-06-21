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

#include "../include/easyfind.hpp"

int	main(void)
{
	std::cout << BWHITE << "*** BASIC TESTS ***" << RESET << std::endl;
	try
	{
		std::vector<int> myVector;
		std::cout << BBLUE << "Vector container" << RESET << std::endl;
		myVector.push_back(2);
		myVector.push_back(7);
		myVector.push_back(15);
		myVector.push_back(200);
		myVector.push_back(0);
		::easyfind(myVector, 0);

		std::list<int> myList;
		std::cout << BBLUE << "\nList container" << RESET << std::endl;
		myList.push_back(5);
		myList.push_back(3);
		myList.push_back(39);
		myList.push_back(509);
		myList.push_back(7);
		::easyfind(myList, 509);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << BWHITE << "\n*** INT RANDOM TESTS ***" << RESET << std::endl;
	try
	{
		srand(time(0));
		std::vector<int> myVector;
		std::cout << BBLUE << "Vector container" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		{
			int random = rand() % 100;
			myVector.push_back(random);
			::easyfind(myVector, random);
		}
		
		std::cout << "\n*** Generating more random tests ***" << RESET << std::endl;
		sleep(1);
		std::cout << '\n';
		std::list<int> myList;
		std::cout << BBLUE << "List container" << RESET << std::endl;
		for (int i = 0; i < 10; i++)
		{
			int random = rand() % 100;
			myList.push_back(random);
			::easyfind(myList, random);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << BWHITE << "\n*** INVALID TESTS ***" << RESET << std::endl;
	try
	{
		std::vector<int> myVector;
		std::cout << BBLUE << "Vector container" << RESET << std::endl;
		myVector.push_back(1);
		myVector.push_back(7);
		myVector.push_back(200);
		::easyfind(myVector, 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::list<int> myList;
		std::cout << BBLUE << "\nList container" << RESET << std::endl;
		::easyfind(myList, 509);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}