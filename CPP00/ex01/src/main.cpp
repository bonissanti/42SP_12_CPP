#include "../include/PhoneBook.hpp"
#include "../include/Contacts.hpp"

int	main(void)
{
	std::string	input;
	bool		promptAgain;
	PhoneBook	pBook;
	
	promptAgain = true;
	while (promptAgain)
	{
		std::cout << BYEL << "Enter an option: [A]: ADD, [B]: SEARCH, [C]: EXIT" << RESET << std::endl;
		std:: cout <<  "• ";
		std::cin >> input;
		if (input.compare("A") == 0)
		{
				pBook.addContact();
				std::cout << BGRN << "Contact added sucessfully! " << RESET << std::endl;
		}
		else if (input.compare("B") == 0)
				pBook.searchContact();
		else if (input.compare("C") == 0)
				promptAgain = false;
		else
				std::cout << BRED << "Invalid choIce. Please choose a valid option" << RESET << std::endl << "• ";
	}
}