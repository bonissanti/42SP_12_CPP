#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BRED "\e[1;31m"
#define BBLU "\e[1;34m" 
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define RESET "\e[0m"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << BBLU << " index:" << Account::_accountIndex << ";amount:" << _amount << ";created" << RESET << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << BBLU << " index:" << Account::_accountIndex << ";amount:" << _amount << ";closed" << RESET << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << BYEL << " index:" << Account::_accountIndex << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits << ";withdraws:" << _nbWithdrawals << RESET << std::endl;
}

void	Account::_displayTimestamp(void)
{
	std::time_t		capture = std::time(0);
	char		buffer[50];

	strftime(buffer, 50, "[%Y%m%d_%H%M%S]", localtime(&capture));
	std::cout << buffer;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << BGRN << " accounts:" << Account::_nbAccounts << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << RESET << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

void	Account::makeDeposit(int deposit)
{
	if (deposit > 0)
	{
		_displayTimestamp();
		std::cout << BMAG << " index:" << _accountIndex << ";p_amount:" << _amount;
		this->_amount += deposit;
		this->_totalAmount += deposit;
		this->_nbDeposits += 1;
		this-> _totalNbDeposits += 1;
		std::cout << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << RESET << std::endl; 
		return ;
	}
	std::cout << BMAG << " index:" << _accountIndex << ";p_amount:" << _amount;
	std::cout << ";deposit:invalid" << RESET << std::endl;
	return ;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (withdrawal > this->_amount)
	{
		std::cout << BCYN << " index:" << _accountIndex << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused" << RESET << std::endl;
		return (false);
	}
	std::cout << BCYN << " index:" << _accountIndex << ";p_amount:" << _amount;
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals += 1;
	this->_totalNbWithdrawals += 1;
	std::cout << ";withdrawal:" << withdrawal << ";amount:"  << _amount << ";nb_withdrawals:" << _nbWithdrawals << RESET << std::endl;
	return (true);
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}