#include "../include/PhoneBook.hpp"

/**
 * Constructor: Contact
 * -------------------
 * This is a Parametrized constructor, one of the three types of use Constructors,
 * that receive as parameters the members 'fName', 'lName', 'nName', 'pNumber' and
 * 'dSecret'. This means that always one object Contact is created, this values
 * can be specified. 
 *
 * After the ':' is the Initizialize Constructor List, an efficient way to initizialize
 * and fill the objects members with the values given, instead of initizialize first
 * and fill after.
 *
 */

Contact::Contact(const std::string& fName, const std::string& lName, const std::string& nName, 
				 const std::string& pNumber, const std::string& dSecret)
		: firstName(fName), lastName(lName), nickName(nName), phoneNumber(pNumber), darkestSecret(dSecret)
{
}

/**
 * Set: Setter Contacts
 * -------------------
 *
 * Setter is a public member function that sets or modifies the value of a private data member.
 * This function allows controlled modification of internal data.
 */

void	Contact::setFirstName(const std::string& fName)
{
	firstName = fName;
}

void	Contact::setLastName(const std::string& lName)
{
	lastName = lName;
}

void	Contact::setNickName(const std::string& nName)
{
	nickName = nName;
}

void	Contact::setDarkestSecret(const std::string& dSecret)
{
	darkestSecret = dSecret;
}

void	Contact::setPhoneNumber(const std::string& pNumber)
{
	phoneNumber = pNumber;
}

/**
 * Get: Getter Contacts
 * -------------------
 *
 * Getter is a public member function that helps in retrieving the value of a private data
 * member without modifying it. The function typically returns the value of a private variable
 * and doesn't alter any member data.
 */

std::string	Contact::getFirstName() const
{
	return (firstName);
}

std::string	Contact::getLastName(void) const
{
	return (lastName);
}

std::string	Contact::getnickName(void) const
{
	return (nickName);
}

std::string	Contact::getDarkestSecret(void) const
{
	return (darkestSecret);
}

std::string	Contact::getPhoneNumber(void) const
{
	return (phoneNumber);
}

/**
 * function: Add contacts
 * -------------------
 *
 * Getter is a public member function that helps in retrieving the value of a private data
 */


