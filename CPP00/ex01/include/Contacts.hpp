#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <PhoneBook.hpp>

#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BRED "\e[1;31m"
#define BBLU "\e[1;34m" 
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWTH "\e[1;37m"
#define RESET "\e[0m"

class Contacts
{
	private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	public:
	Contacts();
	void		setFirstName(std::string firstName);
	void		setLastName(std::string lastName);
	void		setNickName(std::string nickName);
	void		setPhoneNumber(std::string phoneNumber);
	void		setDarkestSecret(std::string darkestSecret);
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
};

#endif