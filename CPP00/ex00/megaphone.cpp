#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	
	std::string str = argv[1];
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	std::cout << str << std::endl;
}
