#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contacts.hpp"

class	PhoneBook
{
	private:
	Contact contact[8];
	int	numContacts;

	public:
	PhoneBook();
	void	addContact();
};

#endif
