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

#include "../include/RobotomyRequestForm.hpp"

Robotomy::Robotomy() : AForm("Robotomy form", 72, 45), target("House") {
	debugMode("<ROBOTOMY> Default Constructor called"); 
}

Robotomy::Robotomy(const std::string& target) : AForm("Robotomy form", 72, 45), target(target)
{
	debugMode("<ROBOTOMY> Parametrized constructor called");
	if (this->getToSign() < 1 || this->getExecute() < 1)
		throw Robotomy::GradeTooHighException();
	
	else if (this->getToSign() > 72 || this->getExecute() > 45)
		throw Robotomy::GradeTooLowException();
}

Robotomy::~Robotomy(){
	debugMode("<ROBOTOMY> Destructor called");
}

Robotomy::Robotomy(const Robotomy& toCopy) : AForm("Robotomy form", 72, 45), target(toCopy.target){
	debugMode("<ROBOTOMY> Copy constructor called");
	if (this != &toCopy)
		*this = toCopy;
}

Robotomy& Robotomy::operator=(const Robotomy& toCopy){
	debugMode("<ROBOTOMY> Copy assignment operator called");
	if (this != &toCopy)
		this->target = toCopy.target;
	return (*this);
}

void	Robotomy::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getExecute())
		throw Robotomy::GradeTooLowException();
	else if (!this->getBoolSign())
		throw Robotomy::NotSigned();

	std::cout << BBLUE << "*** Driling Noises ***" << std::endl;
	std::cout << this->target << " has been robotomized sucessfully " << RESET << std::endl;
}

