#include "../include/PhoneBook.hpp"

void	displayMenu()
{
	std::cout << "----------------------------------------------------------\n";
	std::cout << "Phone Book Application\n";
	std::cout << "----------------------------------------------------------\n";
	std::cout << "A) Add Contact\n";
	std::cout << "B) Search Contact\n";
	std::cout << "C) Exit\n";
	std::cout << "Enter your choice: ";
}

int	main(void)
{
	char		choice;
	/* PhoneBook	phonebook; */
	std::string	input;
	
	while (true)
	{
		displayMenu();
		std::getline(std::cin, input);
		if (input.length() == 1)
			choice = input[0];
		else{
		 	std::cout << "Invalid output. Please enter a single character (A, B or C).\n";
			continue;
		}

		if (choice == 'C' || choice == 'c'){
			std::cout << "Exiting Phonebook Application";
			break;
		}

		switch (choice){
			case 'A':
			case 'a':{
				std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
				std::cout << "Enter first name: \n";
				std::cout << "> ";
				std::getline(std::cin, firstName);
				std::cout << "Enter last name: \n";
				std::cout << "> ";
				std::getline(std::cin, lastName);
				std::cout << "Enter nickName: \n";
				std::cout << "> ";
				std::getline(std::cin, nickName);
				std::cout << "Enter phone number: \n";
				std::cout << "> ";
				std::getline(std::cin, phoneNumber);
				std::cout << "Enter darkest secret: \n";
				std::cout << "> ";
				std::getline(std::cin, darkestSecret);
				std::cout << "Adicionando contato: \n";
				/* phonebook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret); */
				break;
			}

			case 'B':
			case 'b':{
				std::cout << "Enter search query (first name, last name, nickName or index)\n";
				std::cout << "> ";
				std::string query;
				std::getline(std::cin, query);
				std::cout << "Realizando a procura\n";
				break ;
			}
		}
	}
	return (0);
}
