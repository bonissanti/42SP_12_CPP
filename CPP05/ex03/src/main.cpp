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
#include "../include/Intern.hpp"

int	main(void)
{
	{
		std::cout << BYELLOW << "*** SUBJECT TESTS ***" << RESET << std::endl;
		Intern	random;
		AForm	*rrf;

		rrf = random.makeForm("presidential pardon", "Blender");
		delete rrf;

		rrf = random.makeForm("robotomy request", "Blender");
		delete rrf;

		rrf = random.makeForm("shrubbery creation", "Blender");
		delete rrf;

		rrf = random.makeForm("non exists", "anyone");
		delete rrf;
	}

	std::cout << '\n';
	{
		std::cout << BYELLOW << "*** CREATE, SIGN and EXECUTE TESTS ***" << RESET << std::endl;
		Intern	carlitos;
		AForm *president;
		AForm *robotomy;
		AForm *shrubber;
		AForm *internPromotion;

		president = carlitos.makeForm("presidential pardon", "president");
		robotomy = carlitos.makeForm("robotomy request", "robot");
		shrubber = carlitos.makeForm("shrubbery creation", "shrub");
		internPromotion = carlitos.makeForm("intern promotion", "carlitos");

		Bureaucrat	ceo("ceo", 1);
		Bureaucrat	random("random", 26);
		Bureaucrat	bruh("bruh", 39);	
		Bureaucrat	intern("carlitos", 150);

		if (president)
			ceo.signForm(*president);	
		if (robotomy)
			random.signForm(*robotomy);
		if (shrubber)
			bruh.signForm(*shrubber);
		if (internPromotion)
		 	intern.signForm(*internPromotion);

		Bureaucrat	marvin("marvin", 30);
		Bureaucrat	garden("garden", 15);

		std::cout << '\n';
		if (president)
		{
			ceo.executeForm(*president);
			delete president;
		}

		std::cout << '\n';
		if (robotomy)
		{
			marvin.executeForm(*robotomy);
			delete robotomy;
		}

		std::cout << '\n';
		if (shrubber)
		{
			garden.executeForm(*shrubber);
			delete shrubber;
		}

		std::cout << '\n';
		if (internPromotion)
		{
			intern.executeForm(*internPromotion);
			delete internPromotion;
		}
	}
	return (0);
}