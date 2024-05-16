#include "../include/Replace.hpp"

int	main(int argc, char **argv)
{
<<<<<<< Updated upstream
	if (argc != 4)
	{
		std::cerr << "Error\nUsage: <File Name> <Search String> <Replace String>" << std::endl;
		return (1);
	}
	Modifier mod(argv[1]);
	mod.ftReplace(argv[2], argv[3]);
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
=======
	if (argc != 2)
	{
		std::cerr << "Invalid number of arguments";
		return (1);
	}
	std::ofstream	testFile("file.txt\n");
	if (testFile.is_open())
		testFile << argv[1];
	else
		std::cerr << "Error in open file";
	return (0);
}
>>>>>>> Stashed changes
