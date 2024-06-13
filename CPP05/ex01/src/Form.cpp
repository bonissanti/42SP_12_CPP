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
	debugMode(this, NULL, "<FORM> Default Constructor called");
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name),
	sign(false), gradeToSign(gradeToSign),	gradeToExecute(gradeToExecute)
{
	debugMode(this, NULL, "<FORM> Parametrized constructor called");
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(){
	debugMode(this, NULL, "<FORM> Destructor called");
}

Form::Form(const Form& toCopy) : name(toCopy.name), sign(toCopy.sign), 
	gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute){
	debugMode(this, NULL, "<FORM> Copy constructor called");
}

Form& Form::operator=(const Form& toCopy){
	debugMode(this, NULL, "<FORM> Copy assignment operator called");
	if (this != &toCopy)
		new (this) Form(toCopy); // Placement new
	return (*this);
}


void	Form::beSigned(Bureaucrat& personToSign)
{
	try
	{
		if (personToSign.getGrade() > this->gradeToSign)
			throw (Form::GradeTooLowException());
	}
	catch(const std::exception& e)
	{
		std::cout << BRED << personToSign.getName() << " couldn't sign '" << this->name << "' because " 
			<< e.what() << RESET << std::endl;
		return ;
	}
	this->sign = true;
	personToSign.signForm(*this);
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
	return (BRED "<FORM> Grade too high." RESET);
}

char const* Form::GradeTooLowException::what() const throw(){
	return (BRED "<FORM> Grade too low." RESET);
}

std::ostream&	operator<<(std::ostream& os, const Form& toPrint)
{
	os << toPrint.getName();
	return (os);
}

void	debugMode(const Form *toPrint, const Bureaucrat *toPrint2, const std::string& msg)
{
	#ifndef TEST
	(void)toPrint;
	(void)toPrint2;
	(void)msg;
	#endif

	#ifdef TEST
	if (toPrint)
		std::cout << msg << std::endl;
	else if (toPrint2)
		std::cout << msg << std::endl;
	#endif
}