#include "Account.hpp"
#include <iostream>
#include <string>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account()
{
}

void	Account::displayStatus(void) const
{
	Account person;

	std::cout << person.getNbAccounts() << std::endl;
	std::cout << person.getNbDeposits() << std::endl;
	std::cout << person.getNbWithdrawals() << std::endl;
	std::cout << person.getTotalAmount() << std::endl;	
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
