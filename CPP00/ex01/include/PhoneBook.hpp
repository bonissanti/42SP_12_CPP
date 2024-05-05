#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

#define BRED	"\033[1;31m"
#define BGREEN	"\033[1;32m"
#define BYELLOW	"\033[1;33m"
#define BBLUE	"\033[1;34m"
#define RESET	"\033[0m"

class	PhoneBook
{
	private:
	Contact contact[8];
	int	numContacts;

	public:
	PhoneBook();
	void	addContact(const Contact& newContact);
	void	searchContact(void) const;
	void	displayContact(void) const;
	void	printContact(void) const;
};

#endif
