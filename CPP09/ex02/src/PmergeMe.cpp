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

static int	jacobsthal(int n);
template <typename T>
static int binarySearch(T& container, int low, int high, int target);
template <typename T>
static bool isSorted(T& container);

PmergeMe::PmergeMe(int argc, char **argv)
{
	debugMode("<PmergeMe> Default Constructor called");
	if (!validDigits(argc, argv))
		throw PmergeMe::invalidDigitsException(RED "Error: arguments are not digits" RESET);

	this->vec = convertVector(argc, argv);
	this->dqe = convertDeque(argc, argv); 

	if (isSorted(this->vec))
		throw PmergeMe::isSortedException(RED "Error: arguments are sorted already" RESET);

	printContainer(this->vec, "Before: ", BBLUE);
	this->start = clock();
}

PmergeMe::~PmergeMe(){
	debugMode("<PmergeMe> Destructor called");
}

PmergeMe::PmergeMe(const PmergeMe& toCopy){
	debugMode("<PmergeMe> Copy Constructor called");
	*this = toCopy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& toCopy){
	debugMode("<PmergeMe> Copy Assignment Operator called");
	PmergeMe temp(toCopy);
	std::swap(*this, temp);
	return (*this);
}

// ############## EXCEPTIONS ################

PmergeMe::isSortedException::isSortedException(const std::string& msg) : msg(msg){}
PmergeMe::isSortedException::~isSortedException() throw(){}
PmergeMe::invalidDigitsException::invalidDigitsException(const std::string& msg) : msg(msg){}
PmergeMe::invalidDigitsException::~invalidDigitsException() throw(){}

const char* PmergeMe::isSortedException::what() const throw()
{
	return (msg.c_str());
}

const char* PmergeMe::invalidDigitsException::what() const throw()
{
	return (msg.c_str());
}

// ############## UTILS ####################

template <typename T>
static bool isSorted(T& container)
{
	size_t count = 0;

	for (size_t i = 1; i < container.size(); i++)
		if (container[i - 1] < container[i])
			count++;
	if (count == container.size() - 1)
		return (true);
	else
		return (false);
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

std::deque<int> PmergeMe::convertDeque(int argc, char **argv)
{
	unsigned int value;
	std::deque<int> deque;

	for (int i = 0; i < argc; i++)
	{
		std::stringstream ss(argv[i]);
		ss >> value;

	if (ss.fail())
		std::cout << RED << "Error at converting " << argv[i] << " to int" << RESET << std::endl;
	else
		deque.push_back(value);
	}
	return (deque);
}

template <typename T>
void	PmergeMe::printContainer(T& container, const std::string& msg, const std::string& color)
{
	typename T::iterator it;
	std::cout << BWHITE << "\n" << msg << RESET << std::endl;

	for (it = container.begin(); it != container.end(); ++it)
		std::cout << color << *it << " ";
	std::cout << RESET << '\n' << '\n';
}

template <typename T>
void	PmergeMe::printTime(T&container, const std::string& msg)
{
	this->end = clock();

	std::cout << YELLOW << "Time to process a range of " << container.size() << " elements with " << msg << " : " 
		<< BBLUE << double(this->end - this->start)/CLOCKS_PER_SEC * 1000 << " microseconds"<< std::endl; 
}

// ################## SORT ########################

void	PmergeMe::runDeque(void)
{
	int lastElem = -1;

	// save lastElem
	if (this->dqe.size() % 2 != 0)
	{
		lastElem = this->dqe.back();
		this->dqe.pop_back();
	}

	// Create pairs and sort them
	std::deque<std::pair<int, int> > toSort;
	for (size_t i = 0; i < this->dqe.size(); i += 2)
	{
		if (this->dqe[i] > this->dqe[i + 1])
			toSort.push_back(std::make_pair(this->dqe[i], this->dqe[i + 1]));
		else
			toSort.push_back(std::make_pair(this->dqe[i + 1], this->dqe[i]));
	}
	toSort = mergeSort(toSort);
	
	std::deque<int> mainChain;
	std::deque<int> pend;

	for (size_t i = 0; i < toSort.size(); i++)
		mainChain.push_back(toSort[i].first);

	for (size_t i = 0; i < toSort.size(); i++)
		pend.push_back(toSort[i].second);

	mainChain.insert(mainChain.begin(), pend[0]);

	// generating jacobsthal + insertion
	generateinsertOrder(pend);
	insertionSort(mainChain, pend);

	if (lastElem != -1)
	{
		int pos = binarySearch(mainChain, 0, mainChain.size(), lastElem);
		mainChain.insert(mainChain.begin() + pos, lastElem);
	}
	printTime(mainChain, "std::deque");
}

void	PmergeMe::runVector(void)
{	
	int lastElem = -1;

	// save lastElem
	if (this->vec.size() % 2 != 0)
	{
		lastElem = this->vec.back();
		this->vec.pop_back();
	}

	// Create pairs and sort them
	std::vector<std::pair<int, int> > toSort;
	for (size_t i = 0; i < this->vec.size(); i += 2)
	{
		if (this->vec[i] > this->vec[i + 1])
			toSort.push_back(std::make_pair(this->vec[i], this->vec[i + 1]));
		else
			toSort.push_back(std::make_pair(this->vec[i + 1], this->vec[i]));
	}
	toSort = mergeSort(toSort);

	//create mainChain and pend
	std::vector<int> mainChain;
	std::vector<int> pend;

	for (size_t i = 0; i < toSort.size(); i++)
		mainChain.push_back(toSort[i].first);

	for (size_t i = 0; i < toSort.size(); i++)
		pend.push_back(toSort[i].second);

	mainChain.insert(mainChain.begin(), pend[0]);

	// generating jacobsthal + insertion
	generateinsertOrder(pend);
	insertionSort(mainChain, pend);

	// add lastElem
	if (lastElem != -1)
	{
		int pos = binarySearch(mainChain, 0, mainChain.size(), lastElem);
		mainChain.insert(mainChain.begin() + pos, lastElem);
	}
	printContainer(mainChain, "After: ", GREEN);
	printTime(mainChain, "std::vector");
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

template <typename T>
static int binarySearch(T& container, int low, int high, int target)
{
	int mid = low;
	
	while (low <= high)
	{
		if (container[mid] == target)
			return (mid);
		else if (container[mid] < target)
			low = mid + 1; 
		else if (mid != 0)
			high = mid - 1;
		else
			return (mid);
		mid = low + (high - low) / 2;
	}
	return (mid);
}

template <typename T>
void PmergeMe::insertionSort(T& mainChain, T& pend)
{
	int pos;
	for (size_t i = 0; i < pend.size() - 1; i++)
	{
		pos = binarySearch(mainChain, 0, mainChain.size() - 1, pend[i + 1]);
		mainChain.insert(mainChain.begin() + pos, pend[i + 1]);
	}
}

//################ SORT UTILS ################

template <typename T>
void	PmergeMe::generateinsertOrder(T& pend)
{
	int	jacobIndex = 2;
	size_t size = pend.size();

	this->insertOrder.push_back(jacobsthal(jacobIndex));

	while (this->insertOrder.size() < size)
	{
		int value = jacobsthal(jacobIndex++);
		if (value >= static_cast<int>(size))
			value = size;
		while (this->insertOrder.size() < size && value > 0)
		{
			this->insertOrder.push_back(value);
			if (std::find(this->insertOrder.begin(), this->insertOrder.end(), value - 1) != this->insertOrder.end())
				break ;
			value--;
		}
	}
}

static int	jacobsthal(int n)
{
	int dp[n + 1];

	dp[0] = 0;
	dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + 2 * dp[i - 2];
	return (dp[n]);
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