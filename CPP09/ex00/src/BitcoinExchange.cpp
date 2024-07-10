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

bool	thisIsDigit(char const delim, std::string &str);
bool	validDate(char const delim, std::string &str);
static bool	emptyFile(std::ifstream& file);
static std::string	removeSpace(std::string str);

Bitcoin::Bitcoin(){
	debugMode("<Bitcoin> Default Constructor called");
}

Bitcoin::~Bitcoin(){
	debugMode("<Bitcoin> Destructor called");
}

Bitcoin::Bitcoin(const Bitcoin& toCopy){
	debugMode("<Bitcoin> Copy Constructor called");
	*this = toCopy;
}

Bitcoin& Bitcoin::operator=(const Bitcoin& toCopy){
	debugMode("<Bitcoin> Copy Assignment Operator called");
	if (this != &toCopy)
		this->db = toCopy.db;
	return (*this);
}

Bitcoin::exception::exception(const std::string& msg) : message(msg) {}
Bitcoin::exception::~exception() throw(){}

void	Bitcoin::multiplyExchange(const std::string date, const float exchange)
{
	std::map<std::string, const float>::iterator it;

	it = this->db.lower_bound(date);
	if (it == db.end() || it->first > date)
	{
		if (it != db.begin())
			--it;
	}
	std::cout << YELLOW << date << " => " << exchange << " = " << GREEN << it->second * exchange << RESET << std::endl;
}

void	Bitcoin::createDataBase(void)
{
	std::string line;
	std::string date;
	std::string exchangeRate;
	std::ifstream sheet("data.csv");
	if (sheet.fail())
		throw std::invalid_argument(RED "Failed to open the DataBase file" RESET);

	getline(sheet, line);
	while (getline(sheet, line))
	{
		size_t value = line.find(',');
		if (value == std::string::npos)
			throw std::runtime_error(RED "Error! Misformatted input file" RESET);
		try
		{
			validDate(DATABASE, line);
			thisIsDigit(DATABASE, line);
			date = removeSpace(line.substr(0, value));
			exchangeRate = removeSpace(line.substr(value + 1));
			this->db.insert(std::make_pair(date, std::atof(exchangeRate.c_str())));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue;
		}
	}
	sheet.close();
}

void	Bitcoin::openInputFile(std::string &arg)
{
	std::string	line;
	std::string	date;
	std::string	exchange;
	std::string	value;

	std::ifstream file(arg.c_str());
	if (file.fail() || emptyFile(file))
		throw std::invalid_argument(RED "Failed to open the input file" RESET);

	getline(file, line);
	while (std::getline(file, line))
	{
		try
		{
			size_t value =	line.find('|');	
			if (value == std::string::npos){
				std::cout << RED << "Error: bad input => " << YELLOW << line << RESET << std::endl;
				continue;
			}
			if (thisIsDigit(INPUT, line) && validDate(INPUT, line))
			{
				date = removeSpace(line.substr(0, value));
				exchange = removeSpace(line.substr(value + 1));
				multiplyExchange(date, std::atof(exchange.c_str()));
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue ;
		}
	}
	file.close();
}

//########################## UTILS FUNCTIONS #########################################

static std::string	removeSpace(std::string str)
{
	std::string result;

	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (!isspace(*it))
			result += *it;
	}
	return (result);
}

bool	thisIsDigit(char const delim, std::string &str)
{
	if (str.empty())
		return (false);
	std::set<char> validChars;

	validChars.insert(delim);
	validChars.insert('-');
	validChars.insert('.');
	validChars.insert(' ');

	std::string::iterator it;

	for (it = str.begin(); it != str.end(); ++it)
	{
		if (!isdigit(*it) && validChars.find(*it) == validChars.end())
		{
			throw Bitcoin::exception(RED "Error: this is not a digit" RESET);
			return (false);
		}
	}
	return (true);
}

static bool	emptyFile(std::ifstream& file)
{
	if (file.peek() == std::ifstream::traits_type::eof())
		return (true);
	return (false);
}

bool	Bitcoin::validDate(char const delim, std::string &str)
{
	if (str.empty())
		return (false);
	std::stringstream	ss(str);
	char delimiter;
	int	year = 0;
	int	month = 0;
	int	day = 0;
	float exchangeRate = MAXFLOAT;
	
	ss >> year >> delimiter >> month >> delimiter >> day >> delimiter >> exchangeRate;
	try
	{
		if (year < 2009 || year > 2022)
			throw Bitcoin::exception(RED "Error: invalid year. The year accept by database is: min = 2009 and max = 2022" RESET);
		else if (month < 1 || month > 12)
			throw Bitcoin::exception(RED "Error: invalid month" RESET);
		else if (day < 1 || day > 31)
			throw Bitcoin::exception(RED "Error: invalid day" RESET);
		else if (month == 2 && day > 29)
			throw Bitcoin::exception(RED "Error: february with 30 or more days doesn't exist" RESET);

		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
			throw Bitcoin::exception(RED "Error: month with extra days" RESET);
		else if (delim == INPUT && exchangeRate < 0)
			throw Bitcoin::exception(RED "Error: not a positive number" RESET);
		else if (delim == INPUT && exchangeRate > 1000 && exchangeRate != MAXFLOAT)
			throw Bitcoin::exception(RED "Error: too large a number" RESET);

		else if (exchangeRate == MAXFLOAT)
			throw Bitcoin::exception(RED "Error: exchange value not informed" RESET);
	}
	catch(const Bitcoin::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (false);
	}
	return (true);
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