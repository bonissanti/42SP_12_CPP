#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <iomanip>
#include <cctype>
#include <cstdlib>

class Contact
{
	private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	public:
	Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret(""){}
	Contact(const std::string& fName, const std::string& lName, const std::string& nName,
		 const std::string& pNumber, const std::string& dSecret);

	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string getnickName() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	void	setFirstName(const std::string& fName);
	void	setLastName(const std::string& fName);
	void	setNickName(const std::string& fName);
	void	setPhoneNumber(const std::string& fName);
	void	setDarkestSecret(const std::string& fName);
};

#endif
