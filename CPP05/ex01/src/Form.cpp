/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/12/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/12/2024                   */
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

#include "../include/Form.hpp"

Form::Form() : name("Admissional doc"), sign(false), gradeToSign(5), gradeToExecute(10) {
	debugMode("<FORM> Default Constructor called");
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name),
	sign(false), gradeToSign(gradeToSign),	gradeToExecute(gradeToExecute)
{
	debugMode("<FORM> Parametrized constructor called");
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){
	debugMode("<FORM> Destructor called");
}

Form::Form(const Form& toCopy) : name(toCopy.name), sign(toCopy.sign), 
	gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute){
	debugMode("<FORM> Copy constructor called");
}

Form& Form::operator=(const Form& toCopy){
	debugMode("<FORM> Copy assignment operator called");
	if (this != &toCopy)
	{
		const_cast<std::string&>(this->name) = toCopy.name;
		this->sign = toCopy.sign;
		const_cast<int&>(this->gradeToSign) = toCopy.gradeToSign;
		const_cast<int&>(this->gradeToExecute) = toCopy.gradeToExecute;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat& personToSign)
{
	if (personToSign.getGrade() > this->gradeToSign)
		throw (Form::GradeTooLowException());
	this->sign = true;
}

const std::string& Form::getName(void) const
{
	return (this->name);
}

bool	Form::getBoolSign(void) const
{
	return (this->sign);
}

//FIXME: verificar se na 42 posso usar 'const int'
int	Form::getToSign(void) const
{
	return (this->gradeToSign);
}

//FIXME: verificar se na 42 posso usar 'const int'
int	Form::getExecute(void) const
{
	return (this->gradeToExecute);
}

char const* Form::GradeTooHighException::what() const throw(){
	return (RED "<FORM> Grade too high." RESET);
}

char const* Form::GradeTooLowException::what() const throw(){
	return (RED "<FORM> Grade too low." RESET);
}

std::ostream&	operator<<(std::ostream& os, const Form& toPrint)
{
	os << GREEN << "Name: " << RESET << toPrint.getName() 
		<< GREEN << " | grade to sign: " << RESET << toPrint.getToSign()
		<< GREEN << " | grade to execute: " << RESET << toPrint.getExecute()
		<< GREEN << " | signed? " << RESET << toPrint.getBoolSign() << std::endl;
	return (os);
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