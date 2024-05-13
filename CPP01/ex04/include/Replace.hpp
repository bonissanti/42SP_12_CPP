#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>

class Modifier
{ 
	public:
	Modifier(const std::string& fileToOpen) : fileName(fileToOpen) {};
	void	ftReplace(const std::string& searchStr, const std::string& replaceStr);

	private:
	std::string	fileName;
};

#endif
