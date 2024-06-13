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

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"

Bureaucrat::Bureaucrat() : name("Random"), grade(1){
	debugMode(1, "<BUREAUCRAT> Default Constructor called");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	debugMode(1, "<BUREAUCRAT> Parametrized constructor called");
	if (grade < 1){
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > 150){
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat(){
	debugMode(1, "<BUREAUCRAT> Destructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy){
	debugMode(1, "<BUREAUCRAT> Copy constructor called");
		*this = toCopy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy){
	debugMode(1, "<BUREAUCRAT> Copy assignment operator called");
	if (this != &toCopy)
	{
		(std::string&)this->name = toCopy.name;
		this->grade = toCopy.grade;
	}
	return (*this);
}

char const* Bureaucrat::GradeTooHighException::what() const throw(){
	return (BRED "<BUREAUCRAT> Grade too high. Max possible is 1" RESET);
}

char const* Bureaucrat::GradeTooLowException::what() const throw(){
	return (BRED "<BUREAUCRAT> Grade too low. Min possible is 150" RESET);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

Bureaucrat&	Bureaucrat::operator++(int)
{
	try
	{
		if (this->grade <= 1)
			throw Bureaucrat::GradeTooHighException();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (*this);
	}
	this->grade--;
	return (*this);
}

Bureaucrat& Bureaucrat::operator--(int)
{
	try
	{
		if (this->grade >= 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (*this);
	}
	this->grade++;
	return (*this);
}

void	Bureaucrat::signForm(const AForm& form)
{
	std::cout << *this << BGREEN << ", signed: " << RESET << form << std::endl;	
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	std::cout << *this << BGREEN << ", executed: " << RESET << form << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& toPrint)
{
	os << BGREEN << "Name: " << RESET << toPrint.getName() << BGREEN << ", Bureaucrat grade: " << RESET << toPrint.getGrade();
	return (os);
}
