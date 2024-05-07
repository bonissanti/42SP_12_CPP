#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string& stringREF = str;

	std::cout << "Memory address of the string variable: " << &str << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl << std::endl;

	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value held by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value held by stringREF: " << stringREF << std::endl;

	return (0);
}
