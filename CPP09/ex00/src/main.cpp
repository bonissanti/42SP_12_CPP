/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/19/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/19/2024                   */
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

#include "../include/BitcoinExchange.hpp"

bool	thisIsDigit(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]) && str[i] != '|' && str[i] != '-' && str[i] != ' ' && str[i] != '.')
		{
			std::cout << "The line: " << str << " is not a digit" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	validExchangeRate(float exchangeRate)
{
	if (exchangeRate < 0.1 || exchangeRate > 1000)
		return (false);
	return (true);
}

bool	validDate(std::string &str)
{
		std::stringstream	ss(str);
		char delimiter;
		int	year;
		int	month;
		int	day;
		float exchangeRate;
		
		ss >> year >> delimiter >> month >> delimiter >> day >> delimiter >> exchangeRate;
		if (year < 2009 || year > 2024)
		{
			std::cout << "Error: Year is not a valid number" << std::endl;
			return (false);
		}
		else if (month < 1 || month > 12)
		{
			std::cout << "Error: Month is not a valid number" << std::endl;
			return (false);
		}
		else if (day < 1 || day > 31)
		{
			std::cout << "Error: Day is not a valid number" << std::endl;
			return (false);
		}
		else if (!validExchangeRate(exchangeRate))
		{
			std::cout << "Error: ExchangeRate is not a valid number" << std::endl;
			return (false);
		}
		// std::cout << year << std::endl;
		// std::cout << month << std::endl;
		// std::cout << day << std::endl;
		// std::cout << exchangeRate << std::endl;
		return (true);
}


int main(int argc, char **argv)
{
	(void)argc;
	// if (argc != 2)
	// {
	// 	std::cout << RED << "Error: could not open file" << RESET << std::endl;
	// 	return (1);
	// }
	// lendo da planilha

	// // function of open .csv and storage data
	// std::string line;
	// std::string date;
	// std::string exchangeRate;
	// std::ifstream sheet("src/data.csv");
	// if (sheet.fail())
	// {
	// 	std::cout << "RIP" << std::endl;
	// 	return (1);
	// }

	// std::map<std::string, std::string> infos;
	// while (getline(sheet, line))
	// {
	// 	std::istringstream	ss(line);
	// 	if (getline(ss, date, ',') && getline(ss, exchangeRate))
	// 	{
	// 		std::cout << date << " | " << exchangeRate << std::endl; 
	// 		infos[date] = exchangeRate;
	// 	}
	// }

	// function to open input.txt
	std::string	line;
	std::string	value;

	std::ifstream file(argv[1]);
	if (file.fail())
	{
		std::cout << "RIP2" << std::endl;
		return (1);
	} 
	// parsing input.txt
	std::map<std::string, std::string> infos;
	getline(file, line);
	while (getline(file, line))
	{
		size_t value =	line.find('|');	
		if (value == std::string::npos)
		{
			std::cout << "Error!" << std::endl;
			return (1);
		}
		if (!validDate(line) || !thisIsDigit(line))
			return (1);
		std::string date = line.substr(0, value);
		std::string exchange = line.substr(value + 2, line.length());

		infos[date] = exchange;
		std::cout << infos[date] << std::endl;
		// std::cout << exchange << std::endl;
	}

	std::map<std::string, std::string>::iterator it = infos.begin();
	while (it != infos.end())
	{
		std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
		++it;
	}
	return (0);
}