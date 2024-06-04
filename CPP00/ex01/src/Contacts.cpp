#include "../include/PhoneBook.hpp"
#include "../include/Contacts.hpp"

Contacts::Contacts()
{
	firstName = "";
	lastName = "";
	nickName = "";
	phoneNumber = "";
	darkestSecret = "";
}

std::string	Contacts::getFirstName(void) const
{
	return (firstName);
}

std::string	Contacts::getLastName(void) const
{
	return (lastName);
}

std::string	Contacts::getPhoneNumber(void) const
{
	return (phoneNumber);
}

std::string	Contacts::getNickName(void) const
{
	return (nickName);
}

std::string	Contacts::getDarkestSecret(void) const
{
	return (darkestSecret);
}

void	Contacts::setFirstName(const std::string fName)
{
	this->firstName = fName;
}

void	Contacts::setLastName(const std::string lName)
{
	this->lastName = lName;
}

void	Contacts::setPhoneNumber(const std::string pNumber)
{
	this->phoneNumber = pNumber;
}

void	Contacts::setNickName(const std::string nName)
{
	this->nickName = nName;
}

void	Contacts::setDarkestSecret(const std::string dSecret)
{
	this->darkestSecret = dSecret;
}