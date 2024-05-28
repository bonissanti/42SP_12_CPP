#ifndef PHONEBOOK_HPP 
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class	PhoneBook
{
	private:
	Contacts	contacts[8];
	int			numContacts;

	public:
	PhoneBook();
	void	addContact(void);
	void	searchContact(void);
	void	displayingContacts(void);
	void	getContact(const std::string& toSearch);
	void	printingContact(int num);
};

#endif