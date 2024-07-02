/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 06/20/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 06/20/2024                   */
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

#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "../include/Array.hpp"

template <class T>
Array<T>::Array() : array(NULL)
{
	debugMode("<ARRAY> Default Constructor called");
	this->array = new T[0];
	this->n = 0;
}

template <class T>
Array<T>::Array(unsigned int n) : n(n), array(NULL)
{
	debugMode("<ARRAY> Parametrized constructor called");
	this->array = new T[n]();
}

template <class T>
Array<T>::~Array(){
	debugMode("<ARRAY> Destructor called");
	delete[] array;
}

template <class T>
Array<T>::Array(const Array& toCopy)
{
	debugMode("<ARRAY> Copy constructor called");
	this->n = toCopy.n;
	this->array = new T[toCopy.n];
	std::copy(toCopy.array, toCopy.array + toCopy.n, this->array); //begin, end, begin from other array
}

// template <class T>
// Array<T>& Array<T>::operator=(const Array& toCopy)
// {
// 	debugMode("<ARRAY> Copy assignment operator called");
// 	if (this != &toCopy)
// 	{
// 		if (this->array)
// 			delete[] this->array;
// 		this->n = toCopy.n;
// 		this->array = new T[this->n];

// 		for (unsigned int i = 0; i < this->n; i++)
// 			this->array[i] = toCopy.array[i];
// 	}
// 	return (*this);
// }

template <class T>
Array<T>& Array<T>::operator=(const Array& toCopy)
{
	debugMode("<ARRAY> Copy assignment operator called");
	if (this != &toCopy)
	{
		Array temp(toCopy);
		this->swap(temp);
	}
	return (*this);
}

template <class T>
void Array<T>::swap(Array& toCopy)
{
	using std::swap;

	swap(this->n, toCopy.n);
	swap(this->array, toCopy.array);
}

template <class T>
unsigned int	Array<T>::size(void) const
{
	return (this->n);
}

template <class T>
T&	Array<T>::operator[](unsigned int index)
{
	debugMode("<ARRAY> operator[] - read/write called");
	if (index > this->size() - 1)
		throw std::out_of_range(RED "Index out of bounds" RESET);
	return (this->array[index]);
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const
{
	debugMode("<ARRAY> operator[] - read called");
	if (index > this->size() - 1)
		throw std::out_of_range(RED "Index out of bounds" RESET);
	return (this->array[index]);
}

std::ostream& operator<<(std::ostream &os, const Array<const int>& values)
{
	for (size_t i = 0; i < values.size(); i++)
		os << values[i] << " ";
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

#endif