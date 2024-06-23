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
	debugMode("<BUREAUCRAT> Default Constructor called");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	debugMode("<BUREAUCRAT> Parametrized constructor called");
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
	debugMode("<BUREAUCRAT> Destructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& toCopy){
	debugMode("<BUREAUCRAT> Copy constructor called");
		*this = toCopy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& toCopy){
	debugMode("<BUREAUCRAT> Copy assignment operator called");
	if (this != &toCopy)
	{
		const_cast<std::string&>(this->name) = toCopy.name;
		this->grade = toCopy.grade;
	}
	return (*this);
}

char const* Bureaucrat::GradeTooHighException::what() const throw(){
	return (RED "<BUREAUCRAT> Grade too high. Max possible is 1" RESET);
}

char const* Bureaucrat::GradeTooLowException::what() const throw(){
	return (RED "<BUREAUCRAT> Grade too low. Min possible is 150" RESET);
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
		if (this->grade < 1)
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
		if (this->grade > 150)
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

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		if (this->grade < 1)
			throw	Bureaucrat::GradeTooHighException();
		else if (this->grade > 150)
			throw	Bureaucrat::GradeTooLowException();
		form.beSigned(*this);
		std::cout << GREEN << this->name << YELLOW << ", signed: " << GREEN << form.getName() << RESET << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cout << RED << this->name << " couldn't sign '" << form.getName() << "' because " 
			<< e.what() << RESET << std::endl;
		return ;
	}	
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try
	{
		if (this->grade < 1)
			throw	Bureaucrat::GradeTooHighException();
		else if (this->grade > 150)
			throw	Bureaucrat::GradeTooLowException();
		else if (!form.getBoolSign())
			throw	AForm::NotSigned();

		form.execute(*this);
		std::cout << *this << GREEN << ", executed: " << RESET << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << this->name << " couldn't execute '" << form.getName() << "' because " 
			<< e.what() << RESET << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& toPrint)
{
	os << GREEN << "Name: " << RESET << toPrint.getName() << GREEN << ", Bureaucrat grade: " << RESET << toPrint.getGrade() << std::endl;
	return (os);
}
