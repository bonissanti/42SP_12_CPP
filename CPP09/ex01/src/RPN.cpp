/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/30/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/30/2024                   */
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

#include "../include/RPN.hpp"

RPN::RPN(std::string& arg){
	debugMode("<RPN> Default Constructor called");

	std::string::iterator it;
	for (it = arg.begin(); it != arg.end(); ++it)
	{
		if (validation(*it))
			throw std::invalid_argument("Error: argument is not a digit and arithmetic operator");
		//TODO: adicionar se falta numero e/ou operador
	}
	this->arg = arg;
}

RPN::~RPN(){
	debugMode("<RPN> Destructor called");
}

RPN::RPN(const RPN& toCopy){
	debugMode("<RPN> Copy Constructor called");
		*this = toCopy;
}

RPN& RPN::operator=(const RPN& toCopy){
	debugMode("<RPN> Copy Assignment Operator called");
	if (this != &toCopy)
		this->stack = toCopy.stack;
	return (*this);
}

bool	RPN::validation(char c)
{
	return !((c >= '0' && c <= '9') || c == '+' || c == '-' || c == '/' || c == '*' || c == ' ');
}

bool	isOperator(char op)
{
	return (op == '+' || op == '-' || op == '/' || op == '*');
}

int	calculateRPN(int a, int b, char op)
{
	switch (op)
	{
		case '+':
		return (a + b);
		break;

		case '-':
		return (a - b);
		break;

		case '*':
		return (a * b);
		break;

		case '/':
		return (a / b);
		break;

		default:
		return (0);
		break;
	}
}

int	RPN::postfixAnalyze(std::string& arg)
{
	int a;
	int b;
	int	result;
	std::string::iterator it;

	for (it = arg.begin(); it != arg.end(); ++it)
	{
		if (isdigit(*it))
		{
			std::cout << "adding values to stack" << std::endl;
			this->stack.push(*it - '0');
		}

		if (isOperator(*it))
		{
			b = this->stack.top();
			this->stack.pop();
			a = this->stack.top();
			this->stack.pop();
			result = calculateRPN(a, b, *it);
			this->stack.push(result);
		}
	}
	return (result);
}

void	debugMode(const std::string &msg)
{
	#ifndef TEST
	(void)msg;
	#endif

	#ifdef TEST
	std::cout << BBLUE << msg << std::endl;
	#endif
}