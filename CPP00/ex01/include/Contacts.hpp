#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>

class Contact
{
	private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	public:
	Contact(const std::string& fName, const std::string& lName, const std::string& nName,
		 const std::string& pNumber, const std::string& dSecret);

	std::string	getFirstName();
	std::string	getLastName();
	std::string getnickName();
	std::string	getPhoneNumber;
	std::string	getDarkestSecret;

	void	setFirstName(const std::string& fName);
	void	setLastName(const std::string& fName);
	void	setNickName(const std::string& fName);
	void	setPhoneNumber(const std::string& fName);
	void	setDarkestSecret(const std::string& fName);
};

#endif
