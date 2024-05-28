#include "../include/Phonebook.hpp"
#include "../include/Contacts.hpp"

PhoneBook::PhoneBook() : numContacts(0){}

bool	validation(const std::string& str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string	validNumber(void)
{
	bool		isValid;
	std::string	validNumber;

	isValid = false;
	while (!isValid)
	{
		getline(std::cin, validNumber);
		if (validNumber.length() < 8 || validNumber.length() > 14)
			std::cout << "Invalid phone number size. Try again." << std::endl;
		else if (validation(validNumber))
			isValid = true;
		else
			std::cout << "Invalid phone number. Please enter only digits." << std::endl;
	}
	return (validNumber);
}

std::string	getLinePlus(std::string& str)
{
	do
	{
		getline(std::cin, str);
		if (str == "")
			std::cout << "This field cannot be empty, enter a valid string." << std::endl;
	} while (str == "");
	return (str);
}

void	PhoneBook::addContact(void)
{
	Contacts	current;
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;


	std::cin.ignore();
	std::cout << "Enter the First Name: " << std::endl;
	current.setFirstName(getLinePlus(firstName));
	
	std::cout << "Enter the Last Name: " << std::endl;
	current.setLastName(getLinePlus(lastName));
	
	std::cout << "Enter the Nickname: " << std::endl;
	current.setNickName(getLinePlus(nickName));
	
	std::cout << "Enter the Phone Number: " << std::endl;
	phoneNumber = validNumber();
	current.setPhoneNumber(phoneNumber);

	std::cout << "Enter the Darkest Secret: " << std::endl;
	getline(std::cin, darkestSecret);
	current.setDarkestSecret(darkestSecret);
	this->contacts[this->numContacts % 8] = current;
	this->numContacts++;
}

std::string	truncate(const std::string& str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	return (str); 
}

void	PhoneBook::displayingContacts(void)
{
	if (this->numContacts == 0)
		std::cout << "No contacts to display." << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First Name" << " | ";
	std::cout << std::right << std::setw(10) << "Last Name" << " | ";
	std::cout << std::right << std::setw(10) << "Nick Name" << " | " << std::endl;
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::right << std::setw(10) << i << " | ";
		std::cout << std::right << std::setw(10) << truncate(contacts[i].getFirstName()) << " | ";
		std::cout << std::right << std::setw(10) << truncate(this->contacts[i].getLastName()) << " | ";
		std::cout << std::right << std::setw(10) << truncate(this->contacts[i].getNickName()) << std::endl;
	}
}

void	PhoneBook::printingContact(int num)
{
	std::cout << "Index: " << num << std::endl;
	std::cout << "First Name: " << this->contacts[num].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->contacts[num].getLastName() << std::endl;
	std::cout << "Nick Name: " << this->contacts[num].getNickName() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[num].getDarkestSecret() << std::endl;
}

void	PhoneBook::searchContact(void)
{
	int			num;
	bool		validIndex;
	std::string	toSearch;	
	std::string	exit;


	std::cin.ignore();
	displayingContacts();
	std::cout << "Entry an index to search a contact:" << std::endl;
	validIndex = false;
	while (!validIndex)
	{
		getline(std::cin, toSearch);
		num = atoi(toSearch.c_str());
		if (num < 0 || num >= std::min(numContacts, 8))
			std::cout << "Invalid index or empty contact: Please try a valid number or push [C] to exit" << std::endl;
		else if (toSearch == "C")
			return ;	
		else
			validIndex = true;
	}
	printingContact(num);
}