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
	debugMode("<AFORM> Default Constructor called");
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name(name),
	sign(false), gradeToSign(gradeToSign),	gradeToExecute(gradeToExecute)
{
	debugMode("<AFORM> Parametrized constructor called");
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm(){
	debugMode("<AFORM> Destructor called");
}

AForm::AForm(const AForm& toCopy) : name(toCopy.name), sign(toCopy.sign), 
	gradeToSign(toCopy.gradeToSign), gradeToExecute(toCopy.gradeToExecute){
	debugMode("<AFORM> Copy constructor called");
}

AForm& AForm::operator=(const AForm& toCopy){
	debugMode("<AFORM> Copy assignment operator called");
	if (this != &toCopy)
	{
		const_cast<std::string&>(this->name) = toCopy.name;
		this->sign = toCopy.sign;
		const_cast<int&>(this->gradeToSign) = toCopy.gradeToSign;
		const_cast<int&>(this->gradeToExecute) = toCopy.gradeToExecute;
	}
	return (*this);
}

void	AForm::beSigned(Bureaucrat& personToSign)
{
	if (personToSign.getGrade() > this->gradeToSign)
		throw (AForm::GradeTooLowException());
	this->sign = true;
}

const std::string& AForm::getName(void) const
{
	return (this->name);
}

bool	AForm::getBoolSign(void) const
{
	return (this->sign);
}

int	AForm::getToSign(void) const
{
	return (this->gradeToSign);
}

int	AForm::getExecute(void) const
{
	return (this->gradeToExecute);
}

char const* AForm::GradeTooHighException::what() const throw(){
	return (RED "<AFORM> Grade too high." RESET);
}

char const* AForm::GradeTooLowException::what() const throw(){
	return (RED "<AFORM> Grade too low." RESET);
}

char const* AForm::NotSigned::what() const throw(){
	return (RED "<AFORM> Form needs to be signed before execute." RESET);
}


std::ostream&	operator<<(std::ostream& os, const AForm& toPrint)
{
	os << toPrint.getName();
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

