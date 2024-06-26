/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/10/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/10/2024                   */
/* ⠀⠀⣠⡾⠟⠁⠀⠀⠀⢸⣿⣸⣿⣿⣿⣆⠙⢿⣷⡀⠀⠀                                                       */
/* ⣰⡿⠋⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⣿⣿⣿⠀⠀⠉⠻⣿⡀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣿⣿⣿⣿⣆ ⠀       Email: brunrodr@student.42sp.org.br                 */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⣿⣿⡿⣿⣿⣿⣿⡄⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠿⠟⠀⠀⠻⣿⣿⡇⠀⠀⠀⠀   ███████╗██╗██╗██╗██╗██╗██╗██╗██╗██╗   ██╗██╗   ██╗  */
/* ⠀⠀⠀⠀⠀⠀⢀⣾⡿⠃⠀⠀⠀⠀⠀⠘⢿⣿⡀⠀⠀⠀   ██╔════╝██║██║██║██║██║██║██║██║██║   ██║██║   ██║  */
/* ⠀⠀⠀⠀⠀⣰⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡀⠀⠀   ███████╗██║██║██║██║██║██║██║██║██║   ██║██║   ██║  */
/* ⠀⠀⠀⠀⢠⣿⠟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠻⣿⣧⠀⠀   ╚════██║██║██║██║██║██║██║██║██║██║   ██║██║   ██║  */
/* ⠀⠀⠀⢀⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣆⠀   ███████║██║██║██║██║██║██║██║██║╚██████╔╝╚██████╔╝  */
/*  ⠀⠠⢾⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣷⡤  ╚══════╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝╚═╝ ╚═════╝  ╚═════╝   */
/*************************************************************************************/

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){
	debugMode("<SCALARCONVERTER> default constructor called");
}

ScalarConverter::~ScalarConverter(){
	debugMode("<SCALARCONVERTER> destructor called");
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy){
	debugMode("<SCALARCONVERTER> copy constructor called");
	*this = toCopy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& toCopy){
	debugMode("<SCALARCONVERTER> copy assignment operator called");
	(void)toCopy;
	return (*this);
}

bool	checkDigit(int mode, std::string& toCheck)
{
	if (toCheck[0] == '+' || toCheck[0] == '-')
			toCheck = toCheck.substr(1, toCheck.length());
	if (mode == 0)
	{
		for (size_t i = 0; i < toCheck.length(); i++)
		{
			if (toCheck[i] != '.' && !isdigit(toCheck[i]))
				return (false);
		}
	}
	else
	{
		int countF = 0;
		bool hasDot = false;
		for (size_t i = 0; i < toCheck.length(); i++)
		{
			if (toCheck[i] != 'f' && toCheck[i] != '.' && !isdigit(toCheck[i]))
				return (false);
			else if (toCheck[i] == '.' && hasDot)
				return(false);
			else if (toCheck[i] == 'f')
			{
				countF++;
				if (countF != 1)
					return (false);
			}
			else if (toCheck[i] == '.')
				hasDot = true;
		}
	}
	return (true);
}

static int	getFractional(std::string& str)
{
	int	index = str.find('.');
	int	fractional = 0;

	if (index == -1)
		return (1);
	for (size_t i = index + 1; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			break ;
		fractional++;
	}
	return (fractional);
}

static	int	getPseudoLiteral(const std::string& literal)
{
	std::string	doubleLiteral[3] = {"-inf", "+inf", "nan"};
	std::string	floatLiteral[3] = {"-inff", "+inff", "nanf"};
	for (int i = 0; i < 3; i++)
	{
		if (literal == doubleLiteral[i])
			return (DOUBLEL);
	}
	for (int i = 0; i < 3; i++)
	{
		if (literal == floatLiteral[i])
			return (FLOATL);
	}
	return (NONLITERAL);	
}

static void	handleLiterals(int type, std::string toConvert)
{

	std::cout << RED << "char: impossible" << RESET << std::endl;
	std::cout << RED << "int: impossible" << RESET << std::endl;

	switch (type)
	{
		case FLOATL:
		std::cout << YELLOW << "float: " << GREEN << toConvert << std::endl;
		std::cout << YELLOW << "double: " << GREEN << toConvert.substr(0, toConvert.length() -1) << std::endl;
		break;

		case DOUBLEL:
		std::cout << YELLOW << "float: " << GREEN << toConvert + 'f' << std::endl;
		std::cout << YELLOW << "double: " << GREEN << toConvert << std::endl;
		break ;

		default:
		return ;
	}
}

void	charConverter(std::string toConvert)
{
	int num;
	std::stringstream ss;

	ss << toConvert;
	ss >> num;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		char c = static_cast<char>(toConvert[0]);
		std::cout << YELLOW << "char: " << GREEN << "'" << c << "'" << RESET << std::endl;
	}
	else
	{
		char print = static_cast<char>(num);
		if (num < 32)
			std::cout << RED << "char: non displayable" << RESET << std::endl;
		else if (num > 126 || !checkDigit(0, toConvert))
			std::cout << RED << "char: impossible" << RESET << std::endl;
		else
			std::cout << YELLOW << "char: " << GREEN << "'" << print << "'" << RESET << std::endl;
	}
}

void	intConverter(std::string toConvert)
{
	long int num;
	std::stringstream ss;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		int num = static_cast<int>(toConvert[0]);
		std::cout << YELLOW << "int: " << GREEN << num << std::endl;
		return ;
	}
	ss << toConvert;
	ss >> num;
	if (num < -2147483647-1 || num > 2147483647 || !checkDigit(0, toConvert))
		std::cout << RED << "int: impossible" << RESET << std::endl;
	else
		std::cout << YELLOW << "int: " << GREEN << static_cast<int>(num) << RESET << std::endl;
}

void	floatConverter(std::string toConvert)
{
	float num;
	int	precision;
	double	temp;
	std::stringstream ss;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		float num = static_cast<float>(toConvert[0]);
		std::cout.precision(1);
		std::cout << YELLOW << "float: " << GREEN << std::fixed << num << 'f' << RESET << std::endl;
		return ;
	}
	precision = getFractional(toConvert);
	ss << toConvert;
	ss >> temp;
	num = static_cast<float>(temp);
	
	if (!checkDigit(1, toConvert))
		std::cout << RED << "float: impossible" << RESET << std::endl;
	else if (std::isinf(num))
		std::cout << YELLOW << "float: " << GREEN << ((num > 0) ? "+inff\n" : "-inff\n" RESET);
	else if(std::isnan(num))
		std::cout << YELLOW << "float: " << GREEN << "nanf"  << RESET << std::endl;
	else
	{
		std::cout.precision(precision);
		std::cout << YELLOW << "float: " << std::fixed << GREEN << static_cast<float>(num) << 'f' << RESET << std::endl;
	}
}

void	doubleConverter(std::string toConvert)
{
	double	num;
	int	precision;
	std::stringstream ss;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		double num = static_cast<double>(toConvert[0]);
		std::cout.precision(1);
		std::cout << YELLOW << "double: " << std::fixed << GREEN << num << RESET << std::endl;
		return ;
	}
	precision = getFractional(toConvert);
	ss << toConvert;
	ss >> num;

	if (!checkDigit(1, toConvert))
		std::cout << RED << "double: impossible" << RESET << std::endl;
	else if (std::isinf(num))
		std::cout << YELLOW << "double: " << GREEN << ((num > 0) ? "+inf\n" : "-inf\n" RESET);
	else if(std::isnan(num))
		std::cout << YELLOW << "double: " << GREEN << "nanf" << RESET << std::endl;
	else
	{
		std::cout.precision(precision);
		std::cout << YELLOW << "double: " << GREEN << std::fixed << static_cast<double>(num) << RESET << std::endl;
	}
}

void	ScalarConverter::converter(std::string toConvert)
{
	int type;
	std::stringstream ss;
	
	type = getPseudoLiteral(toConvert);
	if (type != NONLITERAL)
	{
		handleLiterals(type, toConvert);
		return ;
	}
	charConverter(toConvert);
	intConverter(toConvert);
	floatConverter(toConvert);
	doubleConverter(toConvert);	
}

void	debugMode(const std::string& msg)
{
	#ifndef TEST
	(void)msg;
	#endif

	#ifdef TEST
	std::cout << BBLUE << msg << RESET << std::endl;
	#endif
}