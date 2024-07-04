/*************************************************************************************/
/*   ⠀⠀  ⠀⠀⠀⠀ ⣴⣿⣦ ⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⠂⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀                                                       */
/* ⠀⠀⠀⠀⠀⠀⠀⢠⣾⣿⣿⣿⣿⣿⣿⣦          ⠀                                                   */
/* ⠀⠀⠀⠀⠀⠀⣴⣿⢿⣷⠒⠲⣾⣾⣿⣿⠂         Created by: brunrodr - 07/01/2024                   */
/* ⠀⠀⠀⠀⣴⣿⠟⠁⠀⢿⣿⠁⣿⣿⣿⠻⣿⣄⠀⠀⠀⠀   Updated by: brunrodr - 07/01/2024                   */
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

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char **argv){
	debugMode("<PmergeMe> Default Constructor called");
	if (!validDigits(argc, argv))
		throw std::invalid_argument(RED "Error: arguments are not digits" RESET);
	this->vec = convertVector(argc, argv);
}

PmergeMe::~PmergeMe(){
	debugMode("<PmergeMe> Destructor called");
}

//FIXME: ajustar
PmergeMe::PmergeMe(const PmergeMe& toCopy){
	debugMode("<PmergeMe> Copy Constructor called");
		*this = toCopy;
}

//FIXME: ajustar
PmergeMe& PmergeMe::operator=(const PmergeMe& toCopy){
	debugMode("<PmergeMe> Copy Assignment Operator called");
	(void)toCopy;
	return (*this);
}

std::vector<int> PmergeMe::convertVector(int argc, char **argv)
{
	unsigned int value;
	std::vector<int> vector;

	for (int i = 0; i < argc; i++)
	{
		std::stringstream	ss(argv[i]);
		ss >> value;	

	if (ss.fail())
		std::cout << RED << "Error at converting " << argv[i] << " to int" << RESET << std::endl;
	else
		vector.push_back(value);
	}
	return (vector);
}

void	PmergeMe::printContainer(void)
{
	std::vector<int>::iterator it;
	for (it = this->vec.begin(); it != this->vec.end(); ++it)
		std::cout << *it << std::endl;
}

void	PmergeMe::makePair(void)
{	
	std::string lastElem;

	if (this->vec.size() % 2 != 0)
	{
		lastElem = this->vec.back();
		this->vec.pop_back();
	}

	std::vector<std::pair<int, int> > toSort;
	for (size_t i = 0; i < this->vec.size(); i += 2)
	{
		if (this->vec[i] > this->vec[i + 1])
			toSort.push_back(std::make_pair(this->vec[i], this->vec[i + 1]));
		else
			toSort.push_back(std::make_pair(this->vec[i + 1], this->vec[i]));
	}
	toSort = mergeSort(toSort);
}

template <typename T>
T PmergeMe::mergeSort(T& container)
{
	if (container.size() <= 1)
		return (container);

	typename T::iterator middle = container.begin() + (std::distance(container.begin(), container.end())) / 2; 
	T	left(container.begin(), middle);
	T	right(middle, container.end());

	left = mergeSort(left);
	right = mergeSort(right);
	return (merge(left, right));
}

template <typename T>
T PmergeMe::merge(T& leftContainer, T& rightContainer)
{
	T result;
	typename T::iterator left = leftContainer.begin();
	typename T::iterator right = rightContainer.begin();

	while (left != leftContainer.end() && right != rightContainer.end())
	{
		if (*left <= *right)
		{
			result.push_back(*left);
			++left;
		}
		else
		{
			result.push_back(*right);
			++right;
		}
	}
	while (left != leftContainer.end())
	{
		result.push_back(*left);
		++left;
	}
	while (right != rightContainer.end())
	{
		result.push_back(*right);
		++right;
	}
	return (result);
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

