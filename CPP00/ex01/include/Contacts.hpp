#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <Phonebook.hpp>

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
	std::string fName;
	std::string	lName;
	std::string	nName;
	std::string	pNumber;
	std::string	dSecret;
	void		setFirstName(std::string fName);
	void		setLastName(std::string lName);
	void		setNickName(std::string nName);
	void		setPhoneNumber(std::string pNumber);
	void		setDarkestSecret(std::string dSecret);
	std::string	getFirstName(void) const;
	std::string	getLastName(void) const;
	std::string	getNickName(void) const;
	std::string	getPhoneNumber(void) const;
	std::string	getDarkestSecret(void) const;
};

#endif