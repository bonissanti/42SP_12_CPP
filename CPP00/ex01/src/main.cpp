#include "../include/Phonebook.hpp"
#include "../include/Contacts.hpp"

// int	main(void)
// {
// 	PhoneBook ph1;

// 	ph1.setFirstName("otario");
// 	std::cout << ph1.getFirstName() << std::endl;
// 	return (0);
// }


int	main(void)
{
	std::string	input;
	bool		promptAgain;
	PhoneBook	pBook;
	
	promptAgain = true;
	while (promptAgain)
	{
		std::cout << "Enter an option: [A]: ADD, [B]: SEARCH, [C]: EXIT" << std::endl;
		std::cin >> input;

		if (input.compare("A") == 0)
		{
				pBook.addContact();
				std::cout << "Contact added sucessfully! " << std::endl;
		}
		else if (input.compare("B") == 0)
				pBook.searchContact();
		else if (input.compare("C") == 0)
				promptAgain = false;
		else
				std::cout << "Invalid choice, please choose a valid option" << std::endl;
	}
}