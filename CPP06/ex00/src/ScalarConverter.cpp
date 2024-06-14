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
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& toCopy){
		*this = toCopy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& toCopy){
	(void)toCopy;
	return (*this);
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

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	switch (type)
	{
		case FLOATL:
		std::cout << "float: " << toConvert << std::endl;
		std::cout << "double: " << toConvert.substr(0, toConvert.length() -1) << std::endl;
		break;

		case DOUBLEL:
		std::cout << "float: " << toConvert + 'f' << std::endl;
		std::cout << "double: " << toConvert << std::endl;
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
		std::cout << "char: '" << c << "'" << std::endl;
	}
	else
	{
		char print = static_cast<char>(num);
		if (num < 32)
			std::cout << "char: non displayable" << std::endl;
		else if (num > 126)
			std::cout << "char: impossible" << std::endl;
		else
			std::cout << print << std::endl;
	}
}

void	intConverter(std::string toConvert)
{
	long int num;
	std::stringstream ss;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		int num = static_cast<int>(toConvert[0]);
		std::cout << "int: " << num << std::endl;
		return ;
	}
	ss << toConvert;
	ss >> num;

	if (num < -2147483647-1 || num > 2147483647)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(num) << std::endl;
}

void	floatConverter(std::string toConvert)
{
	float num;
	double	temp;
	std::stringstream ss;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		float num = static_cast<float>(toConvert[0]);
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << num << 'f' << std::endl;
		return ;
	}
	ss << toConvert;
	ss >> temp;
	num = static_cast<float>(temp);
	
	if (std::isinf(num))
		std::cout << "float: " << ((num > 0) ? "+inff\n" : "-inff\n");
	else if(std::isnan(num))
		std::cout << "float: nanf" << std::endl;
	else
	{
		std::cout.precision(1);
		std::cout << "float: " << std::fixed << static_cast<float>(num) << 'f' << std::endl;
	}
}

void	doubleConverter(std::string toConvert)
{
	double	num;
	std::stringstream ss;

	if (toConvert.length() == 1 && !isdigit(toConvert[0]))
	{
		double num = static_cast<double>(toConvert[0]);
		std::cout.precision(1);
		std::cout << "double: " << std::fixed << num << std::endl;
		return ;
	}
	ss << toConvert;
	ss >> num;

	if (std::isinf(num))
		std::cout << "double: " << ((num > 0) ? "+inf\n" : "-inf\n");
	else if(std::isnan(num))
		std::cout << "double: nanf" << std::endl;
	else
	{
		std::cout.precision(1);
		std::cout << "double: " << std::fixed << static_cast<double>(num) << std::endl;
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