#include "../include/PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook() : numContacts(0)
{
}

void	PhoneBook::addContact(const Contact& newContact)
{
	contact[numContacts] = newContact;
	numContacts = (numContacts + 1) % 8;
}

std::string	truncateString(const std::string& input)
{
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	return (input);
}

void PhoneBook::displayContact(void) const
{
	int			index;
	bool		isDigityOnly;
	std::string	input;

	std::cout << "\nEnter the index of the contact to display" << std::endl;
	while (true)
	{
		std::cout << "• ";
		std::getline(std::cin, input);
		isDigityOnly = true;
		for (size_t i = 0; i < input.length(); i++)
		{
			if (!isdigit(input[i]))
			{
				isDigityOnly = false;
				break;
			}
		}
		if (!isDigityOnly || input.empty())
		{
			std::cout << "Invalid input. Please enter a valid integer index or type 'exit' to quit: ";
			if (input == "exit"){
				return;
			}
			continue;
		}
		index = atoi(input.c_str());
		if (index < 1 || index > numContacts)
		{
			std::cout << "Invalid index: No contact displayed. Try again or type 'exit' to quit: " << std::endl;
			continue;
		}
		break;
	}
	const Contact& to_print = contact[index - 1];
	std::cout << BYELLOW << "First name: " << RESET << to_print.getFirstName() << std::endl;
	std::cout << BYELLOW << "Last name: " << RESET<< to_print.getLastName() << std::endl;
	std::cout << BYELLOW << "Nick name: " << RESET << to_print.getnickName() << std::endl;
	std::cout << BYELLOW << "Phone number: " << RESET << to_print.getPhoneNumber() << std::endl;
	std::cout << BYELLOW << "Darkest secret: " << RESET << to_print.getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact(void) const
{
	std::cout << std::right << std::setfill(' ');

	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	
	for (int i = 0; i < numContacts; i++)
	{
		std::cout << std::setw(10) << (i + 1) << "|"
			<< std::setw(10) << truncateString(contact[i].getFirstName()) << "|"
			<< std::setw(10) << truncateString(contact[i].getLastName()) << "|"
			<< std::setw(10) << truncateString(contact[i].getnickName()) << std::endl;
	}
	displayContact();
}
