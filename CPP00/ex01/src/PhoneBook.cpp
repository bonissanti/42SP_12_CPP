#include "../include/PhoneBook.hpp"
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
			std::cout << BRED << "Invalid phone number size. Please try again." << RESET << std::endl <<  "• ";
		else if (!validation(validNumber))
			std::cout << BRED << "Invalid phone number. Please enter digits only." << RESET << std::endl << "• ";
		else
			isValid = true;
	}
	return (validNumber);
}

std::string	getLinePlus(std::string& str)
{
	do
	{
		getline(std::cin, str);
		if (str == "")
			std::cout << BRED << "This field cannot be empty. Please enter a valid string." << RESET << std::endl << "• ";
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
	std::cout << BGRN << "Enter the First Name: " << RESET << std::endl;
	std:: cout <<  "• ";
	current.setFirstName(getLinePlus(firstName));
	
	std::cout << BGRN << "Enter the Last Name: " << RESET << std::endl;
	std:: cout <<  "• ";
	current.setLastName(getLinePlus(lastName));
	
	std::cout << BGRN << "Enter the Nickname: " << RESET << std::endl;
	std:: cout <<  "• ";
	current.setNickName(getLinePlus(nickName));
	
	std::cout << BGRN << "Enter the Phone Number: " << RESET << std::endl;
	std:: cout <<  "• ";
	phoneNumber = validNumber();
	current.setPhoneNumber(phoneNumber);

	std::cout << BGRN << "Enter the Darkest Secret: " << RESET << std::endl;
	std:: cout <<  "• ";
	getline(std::cin, darkestSecret);
	current.setDarkestSecret(darkestSecret);
	this->contacts[this->numContacts % 8] = current;
	this->numContacts++;
}

std::string	trunCate(const std::string& str)
{
	if (str.length() >= 10)
		return (str.substr(0, 9) + ".");
	return (str); 
}

void	PhoneBook::displayingContacts(void)
{
	if (this->numContacts == 0)
		std::cout << BRED << "No contacts to display." << RESET << std::endl;
	std::cout << std::right << std::setw(10) << "Index" << " | ";
	std::cout << std::right << std::setw(10) << "First Name" << " | ";
	std::cout << std::right << std::setw(10) << "Last Name" << " | ";
	std::cout << std::right << std::setw(10) << "Nick Name" << " | " << std::endl;
	
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::right << std::setw(10) << i << " | ";
		std::cout << std::right << std::setw(10) << trunCate(contacts[i].getFirstName()) << " | ";
		std::cout << std::right << std::setw(10) << trunCate(this->contacts[i].getLastName()) << " | ";
		std::cout << std::right << std::setw(10) << trunCate(this->contacts[i].getNickName()) << std::endl;
	}
}

void	PhoneBook::printingContact(int num)
{
	std::cout << BWTH << "Index: " << RESET << num << std::endl;
	std::cout << BWTH << "First Name: " << RESET << this->contacts[num].getFirstName() << std::endl;
	std::cout << BWTH << "Last Name: " << RESET << this->contacts[num].getLastName() << std::endl;
	std::cout << BWTH << "Nick Name: " << RESET << this->contacts[num].getNickName() << std::endl;
	std::cout << BWTH << "Darkest Secret: " << RESET << this->contacts[num].getDarkestSecret() << std::endl;
}

static int	min(int num_a, int num_b)
{
	if (num_a < num_b)
		return (num_a);
	return (num_b);
}

void	PhoneBook::searchContact(void)
{
	int			num;
	bool		validIndex;
	std::string	toSearch;	
	std::string	exit;

	std::cin.ignore();
	displayingContacts();
	std::cout << BYEL << "Enter an index to search for a contact:" << RESET << std::endl;
	std:: cout <<  "• ";
	validIndex = false;
	while (!validIndex)
	{
		getline(std::cin, toSearch);
		num = atoi(toSearch.c_str());
		if (num < 0 || num >= min(numContacts, 8))
			std::cout << BRED << "Invalid index or empty contact: Please try a valid number or press [C] to exit" << RESET << std::endl << "• ";
		else if (toSearch == "C")
			return ;	
		else
			validIndex = true;
	}
	printingContact(num);
}