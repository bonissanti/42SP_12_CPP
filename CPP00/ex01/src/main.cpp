#include "../include/PhoneBook.hpp"

void	displayMenu()
{
	std::cout << "----------------------------------------------------------\n";
	std::cout << "Phone Book Application\n";
	std::cout << "----------------------------------------------------------\n";
	std::cout << "A) Add Contact\n";
	std::cout << "B) Search Contact\n";
	std::cout << "C) Exit\n";
	std::cout << "Enter your choice: ";
}

static bool	isValidNumber(const std::string& input)
{
	for (size_t i = 0; i < input.length(); i++)
	{
		if (!isdigit(input[i]) && input[i] != ' ' && input[i] != '-' && input[i] != '+')
			return (false);
	}
	return (true);
}

void	enterNumber(std::string& phoneNumber)
{
	std::cout << BYELLOW << "Enter 'Phone Number': \n" << RESET;
	while (true)
	{
		std::cout << "• ";
		std::getline(std::cin, phoneNumber);
		if (isValidNumber(phoneNumber))
			break;
		else
			std::cout << "Invalid phone number entered: please enter a valid number\n";
	}
}

int	main(void)
{
	char		choice;
	PhoneBook	phonebook;
	std::string	input;
	
	while (true)
	{
		displayMenu();
		std::getline(std::cin, input);
		if (input.length() == 1)
		{
			choice = std::tolower(input[0]);
			if (choice != 'a' && choice != 'b' && choice != 'c')
			{
				std::cout << BRED << "Invalid output. Please enter a single character (A, B or C).\n" << RESET;
				continue;
			}
		}
		else{
			std::cout << BRED << "Invalid output. Please enter a single character (A, B or C).\n" << RESET;
			continue;
		}
		if (choice == 'C' || choice == 'c'){
			std::cout << BGREEN << "Exiting Phonebook Application\n" << RESET;
			break;
		}

		switch (choice){
			case 'A':
			case 'a':{
				std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
				std::cout << BYELLOW << "Enter 'First Name': \n" << RESET;
				std::cout << "• ";
				std::getline(std::cin, firstName);
				std::cout << BYELLOW << "Enter 'Last Name': \n" << RESET;
				std::cout << "• ";
				std::getline(std::cin, lastName);
				std::cout << BYELLOW << "Enter 'NickName': \n" << RESET;
				std::cout << "• ";
				std::getline(std::cin, nickName);
				enterNumber(phoneNumber);
				std::cout << BYELLOW << "Enter 'Darkest Secret': \n" << RESET;
				std::cout << "• ";
				std::getline(std::cin, darkestSecret);
				Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
				phonebook.addContact(newContact);
				std::cout << BGREEN << "Successful! Contact added. \n" << RESET;
				break;
			}
			case 'B':
			case 'b':{
				std::cout << BYELLOW << "Check the list below and choose the index of the contact\n" << RESET;
				phonebook.searchContact();
				break ;
			}
		}
	}
	return (0);
}
