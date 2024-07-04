/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/19/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/19/2024                   */
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

#include "../include/MutantStack.hpp"

template <typename T, class container>
MutantStack<T, container>::MutantStack(){
	debugMode("<MUTANTSTACK> Default Constructor called");
}

template <typename T, class container>
MutantStack<T, container>::~MutantStack(){
	debugMode("<MUTANTSTACK> Destructor called");
}

template <typename T, class container>
MutantStack<T, container>::MutantStack(const MutantStack& toCopy) : std::stack<T, container>(toCopy){
	debugMode("<MUTANTSTACK> Copy Constructor called");
}

template <typename T, class container>
MutantStack<T, container>& MutantStack<T, container>::operator=(const MutantStack& toCopy){
	debugMode("<MUTANTSTACK> Copy Assignment Operator called");
	this->swap(toCopy);	
	return (*this);
}

template <typename T, class container>
void	MutantStack<T, container>::swap(MutantStack& toCopy)
{
	std::swap(this->c, toCopy.c);
}

// Iterator -----------------------
template <typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::begin()
{
	return (this->c.begin());
}

template <typename T, class container>
typename MutantStack<T, container>::iterator MutantStack<T, container>::end()
{
	return (this->c.end());
}

// Const iterator -----------------------
template <typename T, class container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::begin() const
{
	return (this->c.begin());
}

template <typename T, class container>
typename MutantStack<T, container>::const_iterator MutantStack<T, container>::end() const
{
	return (this->c.end());
}

// Reverse iterator -----------------------
template <typename T, class container>
typename MutantStack<T, container>::reverseIterator MutantStack<T, container>::rbegin()
{
	return (this->c.rbegin());
}

template <typename T, class container>
typename MutantStack<T, container>::reverseIterator MutantStack<T, container>::rend()
{
	return (this->c.rend());
}

// Const reverse iterator -----------------------
template <typename T, class container>
typename MutantStack<T, container>::const_reverseIterator MutantStack<T, container>::rbegin() const
{
	return (this->c.rbegin());
}

template <typename T, class container>
typename MutantStack<T, container>::const_reverseIterator MutantStack<T, container>::rend() const
{
	return (this->c.rend());
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