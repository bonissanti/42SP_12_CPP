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

#include "../include/AForm.hpp"

AForm::AForm() : name("Admissional doc"), sign(false), gradeToSign(5), gradeToExecute(10) {
	debugMode(0, "<AFORM> Default Constructor called");
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name),
	sign(false), gradeToSign(gradeToSign),	gradeToExecute(gradeToExecute)
{
	debugMode(0, "<AFORM> Parametrized constructor called");
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){
	debugMode(0, "<AFORM> Destructor called");
}

AForm::AForm(const AForm& toCopy) : name(toCopy.name), sign(toCopy.sign), 
	gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute){
	debugMode(0, "<AFORM> Copy constructor called");
}

AForm& AForm::operator=(const AForm& toCopy){
	debugMode(0, "<AFORM> Copy assignment operator called");
	if (this != &toCopy)
		this->sign = toCopy.sign;
	return (*this);
}


void	AForm::beSigned(Bureaucrat& personToSign)
{
	try
	{
		if (personToSign.getGrade() > this->gradeToSign)
			throw (AForm::GradeTooLowException());
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

const std::string& AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getBoolSign(void) const
{
	return (this->sign);
}

//FIXME: verificar se na 42 posso usar 'const int'
int	AForm::getToSign(void) const
{
	return (this->gradeToSign);
}

//FIXME: verificar se na 42 posso usar 'const int'
int	AForm::getExecute(void) const
{
	return (this->gradeToExecute);
}

char const* AForm::GradeTooHighException::what() const throw(){
	return (BRED "<AFORM> Grade too high." RESET);
}

char const* AForm::GradeTooLowException::what() const throw(){
	return (BRED "<AFORM> Grade too low." RESET);
}

char const* AForm::NotSigned::what() const throw(){
	return (BRED "<AFORM> Form needs to be signed before execute." RESET);
}


std::ostream&	operator<<(std::ostream& os, const AForm& toPrint)
{
	os << toPrint.getName();
	return (os);
}

void	debugMode(int level, const std::string& msg)
{
	#ifndef TEST
	(void)level;
	(void)msg;
	#endif

	#ifdef TEST
	if (level == 0) // AForm
		std::cout << msg << std::endl;
	else if (level == 1) // Bureaucrat
		std::cout << msg << std::endl;
	else if (level == 2) /// Shrubbery
		std::cout << msg << std::endl;
	else if (level == 3) 
		std::cout << msg << std::endl;
	#endif
}

