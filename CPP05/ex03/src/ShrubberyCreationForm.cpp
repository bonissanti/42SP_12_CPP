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

#include "../include/ShrubberyCreationForm.hpp"

Shrubbery::Shrubbery() : AForm("Shrubbery form", 145, 137), target("House") {
	debugMode(2, "<SHRUBBERY> Default Constructor called");
}

Shrubbery::Shrubbery(const std::string& target) : AForm("Shrubbery form", 145, 137), target(target)
{
	debugMode(2, "<SHRUBBERY> Parametrized constructor called");
	if (this->getToSign() < 1 || this->getExecute() < 1)
		throw Shrubbery::GradeTooHighException();
	
	else if (this->getToSign() > 145 || this->getExecute() > 137)
		throw Shrubbery::GradeTooLowException();
}

Shrubbery::~Shrubbery(){
	debugMode(2, "<SHRUBBERY> Destructor called");
}

Shrubbery::Shrubbery(const Shrubbery& toCopy) : AForm("Shrubbery form", 145, 137), target(toCopy.target){
	debugMode(2, "<SHRUBBERY> Copy constructor called");
	if (this != &toCopy)
		*this = toCopy;
}

Shrubbery& Shrubbery::operator=(const Shrubbery& toCopy){
	debugMode(2, "<SHRUBBERY> Copy assignment operator called");
	if (this != &toCopy)
		this->target = toCopy.target;
	return (*this);
}

void	Shrubbery::execute(Bureaucrat const& executor) const
{
	std::string	file = this->target + "_shrubbery";
	std::ofstream out;
	try
	{
		if (executor.getGrade() > this->getExecute())
			throw Shrubbery::GradeTooLowException();

		else if (!this->getBoolSign())
			throw Shrubbery::NotSigned();
	}
	catch(const std::exception& e)
	{
		std::cout << BRED << executor.getName() << " couldn't execute '" << this->getName() << "' because " 
			<< e.what() << RESET << std::endl;
		return ;
	}
	executor.executeForm(*this);
	out.open(file.c_str());
	out << "          .     .  .      +     .      .          ." << std::endl;
	out << "     .       .      .     #       .           . " << std::endl;
	out << "        .      .         ###            .      .      ." << std::endl;
	out << "      .      .   *#:. .:##*##:. .:#  .      ." << std::endl;
	out << "          .      . *####*###*####*  ." << std::endl;
	out << "       .     *#:.    .:#*###*#:.    .:#*  .        .       ." << std::endl;
	out << "  .             *#########*#########        .        ." << std::endl;
	out << "        .    *#:.  *####*###*####*  .:#*   .       ." << std::endl;
	out << "     .     .  *#######*###*##*########                  ." << std::endl;
	out << "                .*##*#####*#####*##*           .      ." << std::endl;
	out << "    .   *#:. ...  .:##*###*###*##:.  ... .:#*     ." << std::endl;
	out << "      .     *#######*##*#####*##*#######*      .     ." << std::endl;
	out << "    .    .     *#####*########*######*    .      ." << std::endl;
	out << "            .     *      000      *    .     ." << std::endl;
	out << "       .         .   .   000     .        .       ." << std::endl;
	out << ".. .. ..................O000O........................ ...... ..." << std::endl;
	out.close();		
}

