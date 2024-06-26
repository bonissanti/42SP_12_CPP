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

#include "../include/Span.hpp"

template <class T>
Span<T>::Span(unsigned int n) : capacity(n){
	debugMode("<SPAN> Default Constructor called");
}

template <class T>
Span<T>::~Span(){
	debugMode("<SPAN> Destructor called");
}

template <class T>
Span<T>::Span(const Span& toCopy){
	debugMode("<SPAN> Copy Constructor called");
		*this = toCopy;
}

template <class T>
Span<T>& Span<T>::operator=(const Span& toCopy){
	debugMode("<SPAN> Copy Assignment Operator called");
	if (this != &toCopy)
	{
		this->myVec = toCopy.myVec;
		this->capacity = toCopy.capacity;
	}
	return (*this);
}

template <class T>
int Span<T>::shortestSpan(void) const
{
	int	min;
	int	tempDiff;

	if (this->myVec.size() < 2)
		throw std::out_of_range(RED "<ShortestSpan> don't have at least 2 elements" RESET);

	std::vector<int> sorted(this->myVec);

	std::sort(sorted.begin(), sorted.end());
	min = std::abs(sorted[0] - sorted[1]);

	for (unsigned int i = 0; i < sorted.size() - 1; i++)
	{
		tempDiff = std::abs(sorted[i + 1] - sorted[i]);
		if (tempDiff <  min)	
			min = tempDiff;
	}
	std::cout << YELLOW << "The shortest difference is: " << GREEN << std::endl;
	return (min);
}

template <class T>
int	Span<T>::longestSpan(void) const
{
	if (this->myVec.size() < 2)
		throw std::out_of_range(RED "<LongestSpan> don't have at least 2 elements" RESET);

	std::vector<int>::const_iterator max = std::max_element(this->myVec.begin(), this->myVec.end());
	std::vector<int>::const_iterator min = std::min_element(this->myVec.begin(), this->myVec.end());

	std::cout << YELLOW << "The longest difference is: " << GREEN << std::endl;
	return (*max - *min);
}

template <class T>
void	Span<T>::addNumber(int num)
{
	if (num < -2147483647-1 || num > 2147483647)
		throw std::out_of_range(RED "Invalid value" RESET);
	else if (this->myVec.size() >= this->capacity)
		throw std::out_of_range(RED "Error: Number not added because 'capacity' is full" RESET);
	this->myVec.push_back(num);
	std::cout << YELLOW << "Num " << GREEN << num << YELLOW << " added sucessfully" << RESET << std::endl;
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