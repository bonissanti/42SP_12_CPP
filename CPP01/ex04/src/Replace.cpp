#include "../include/Replace.hpp"

void	Modifier::ftReplace(const std::string& searchStr, const std::string& replaceStr)
{
	std::string		content, line;
	if (searchStr.empty())
	{
		std::cerr << "Error: Search string cannot be empty" << std::endl;
		return ;
	}

	std::ifstream	fileIn(fileName.c_str());
	if (!fileIn)
	{
		std::cerr << "Error: Unable to open input file" << std::endl;
		return ;
	}
	while (std::getline(fileIn, line))
		content += line + "\n";
	fileIn.close();

	size_t	pos = 0;
	while ((pos = content.find(searchStr, pos)) != std::string::npos)
	{
		content.erase(pos, searchStr.length());
		content.insert(pos, replaceStr);
		pos += replaceStr.length();
	}

	std::ofstream	fileOut(fileName.c_str());
	if(!fileOut)
	{
		std::cerr << "Error: Unable to open file" << std::endl;
		return ;
	}
	fileOut << content;
	fileOut.close();
}