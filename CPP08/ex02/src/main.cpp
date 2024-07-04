/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/25/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/25/2024                   */
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

#include "../include/MutantStack.hpp"

static	void	iteratorTest(void)
{
	{
		std::cout << BWHITE << "*** List Container - iterator TEST ***" << RESET << std::endl;
		std::list<int>	list;

		list.push_back(5); // adding value: 5
		list.push_back(17); // adding value: 17
		std::cout << YELLOW << "Printing the topmost element of list: "	<< GREEN << list.front() << RESET << std::endl;

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << YELLOW << "value of List: " << GREEN << *it << RESET << std::endl;
			++it;
		}	

	}

	std::cout << '\n';
	{
		std::cout << BWHITE << "*** Mutant stack - iterator TEST ***" << RESET << std::endl; 
		MutantStack<int>	mstack;
		
		mstack.push(5); // adding value 5
		mstack.push(17); // adding value 17
		std::cout << YELLOW << "Printing the topmost element of Mutant Stack: " << GREEN << mstack.top() << std::endl;

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite)
		{
			std::cout << YELLOW << "value of MutantStack: " << GREEN << *it << RESET << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
}

static	void	pushPopSizeTest(void)
{
	std::cout << '\n';
	{
		std::cout << BWHITE << "*** List Container - push/pop/size TEST ***" << RESET << std::endl;
		std::list<int>	list;

		list.push_back(-30); // element #0 at list
		list.push_back(600); // element #1 at list
		std::cout << YELLOW << "Printing the topmost element of list: "	<< GREEN << list.front() << RESET << std::endl;

		list.pop_back(); // deleting element #1 - 600
		
		std::cout << YELLOW << "Size of list is: " << GREEN << list.size() << std::endl;

		list.push_back(20332);
		list.push_back(101);
		list.push_back(737);
		list.push_back(2);
		list.push_back(-21);
		list.push_back(0);
		list.pop_back(); // deleting last element - 0

		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << YELLOW << "value of List: " << GREEN << *it << RESET << std::endl;
			++it;
		}	
	}

	std::cout << '\n';
	{
		std::cout << BWHITE << "*** Mutant stack - push/pop/size TEST ***" << RESET << std::endl; 
		MutantStack<int>	mstack;
		
		mstack.push(-30); // element #1 at stack
		mstack.push(600); // element #0 at stack
		std::cout << YELLOW << "Printing the topmost element of Mutant Stack: " << GREEN << mstack.top() << std::endl;

		mstack.pop(); // deleting element #0 at stack

		std::cout << YELLOW << "Size of MutantStack is: " << GREEN << mstack.size() << RESET << std::endl;
		mstack.push(20332);
		mstack.push(101);
		mstack.push(737);
		mstack.push(2);
		mstack.push(-21);
		mstack.push(0);
		mstack.pop(); // deleting the newest element at stack #0

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		while (it != ite)
		{
			std::cout << YELLOW << "value of MutantStack: " << GREEN << *it << RESET << std::endl;
			++it;
		}
		std::cout << '\n';
		std::cout << YELLOW << "Size of mstack is: " << GREEN << mstack.size() << RESET << std::endl;
	}
}

static	void	reverseIteratorTest(void)
{
	MutantStack<int>	mstack;

	srand(time(0));
	for (int i = 0; i < 10; i++)
		mstack.push(rand() % 100);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	MutantStack<int>::reverseIterator rit = mstack.rbegin();
	MutantStack<int>::reverseIterator rite = mstack.rend();

	std::cout << BWHITE << "Comparation between iterator vs reverseIterator: " << RESET << std::endl;
	while (it != ite && rit != rite)
	{
		std::cout << YELLOW << "Value of iterator: " << GREEN << *it << YELLOW << " | " 
			<< YELLOW << "Value of reverseIterator: " << GREEN << *rit << RESET << std::endl;
		++it;
		++rit;
	}
}

static void		constIteratorsTest(void)
{
	MutantStack<std::string> mstack;

	mstack.push("bruh");
	mstack.push("random");
	mstack.push("hello");

	MutantStack<std::string>::const_iterator it = mstack.begin();
	MutantStack<std::string>::const_iterator ite = mstack.end();
	MutantStack<std::string>::const_reverseIterator rit = mstack.rbegin();
	MutantStack<std::string>::const_reverseIterator rite = mstack.rend();

	std::cout << BWHITE << "Comparation between const_iterator vs const_reverseIterator" << RESET << std::endl;
	while (it != ite && rit != rite)
	{
		std::cout << YELLOW << "Value of iterator: " << GREEN << *it << YELLOW << " | " 
			<< YELLOW << "Value of reverseIterator: " << GREEN << *rit << RESET << std::endl;
		++it;
		++rit;
	}
}

static	void	deepCopyTest(void)
{
	MutantStack<float> a;

	MutantStack<float> b(a);
	MutantStack<float> c = b;

	std::cout << BWHITE << "-----> adding elements on MutantStack 'a' <-----" << RESET << std::endl;
	a.push(0.0f);
	a.push(1.0f);
	std::cout << BWHITE << "-----> verifying size of MutantStacks, 'b' and 'c' must be 0 <-----" << RESET << std::endl;
	std::cout << YELLOW << "MutantStack 'a' size is: " << GREEN << a.size() << std::endl;
	std::cout << YELLOW << "MutantStack 'b' size is: " << GREEN << b.size() << std::endl;
	std::cout << YELLOW << "MutantStack 'c' size is: " << GREEN << c.size() << std::endl;

	MutantStack<float> e = a;
	std::cout << YELLOW << "MutantStack 'e' size is: " << GREEN << e.size() << std::endl;
}

int main(void)
{
	iteratorTest();
	std::cout << '\n';

	pushPopSizeTest();
	std::cout << '\n';

	reverseIteratorTest();
	std::cout << '\n';

	constIteratorsTest();
	std::cout << '\n';

	deepCopyTest();
	return (0);
}
	