#include "../include/Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error\nUsage: <File Name> <Search String> <Replace String>" << std::endl;
		return (1);
	}
	Modifier	toReplace(argv[1]);
	modifier.ftReplace(argv[2], argv[3]);
	return (0);
	
}

// int	main(void)
// {
// 	std::string	base = "this is a test string";
// 	std::string	str = base;

// 	str.replace(0, 0, "n example");
// 	std::cout << "Replace test: " << str << std::endl;

// 	str = base;
// 	std::size_t found = str.find("teste");
// 	std::cout << "Find test: " << found << std::endl;
// 	return (0);
// }
