#include "Account.hpp"
#include <iostream>
#include <time.h>
#include <string>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

void	Account::_displayTimestamp( void )
{
    time_t  tm;		//time_t 타입 변수 선언
    tm = time(NULL);	//time()함수를 통해 현재 시간 반환
    struct  tm *pLocal = localtime(&tm);
    std::cout << "[" << pLocal->tm_year + 1900;
	if (pLocal->tm_mon + 1 < 10)
		std::cout << '0' << pLocal->tm_mon + 1;
	else
		std::cout << pLocal->tm_mon + 1;
	if (pLocal->tm_mday < 10)
		std::cout << '0' << pLocal->tm_mday << "_";
	else
		std::cout << pLocal->tm_mday << "_";
	if (pLocal->tm_hour < 10)
		std::cout << '0' << pLocal->tm_hour;
	else
		std::cout << pLocal->tm_hour;
	if (pLocal->tm_min < 10)
		std::cout << '0' << pLocal->tm_min;
	else
		std::cout << pLocal->tm_min;
	if (pLocal->tm_sec < 10)
		std::cout << '0' << pLocal->tm_sec << "]";
	else
		std::cout << pLocal->tm_sec << "]";
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = _totalNbDeposits;
	_nbWithdrawals = _totalNbDeposits;
	_totalAmount = _totalAmount + _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
			  << ";amount:" << _amount \
			  << ";created" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts() \
			  << ";total:" << getTotalAmount() \
			  << ";deposits:" << getNbDeposits() \
			  << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
			  << ";amount:" << _amount \
			  << ";deposits:" << _nbDeposits \
			  << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	amount;

	amount = _amount + deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	_totalAmount = _totalAmount + deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
			  << ";p_amount:" << _amount \
			  << ";deposit:" << deposit \
			  << ";amount:" << amount \
			  << ";nb_deposits:" << _nbDeposits << std::endl;
	_amount = amount;
}

int	Account::checkAmount(void) const
{
	if (_amount >= 0)
		return (1);
	return (0);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex \
			  << ";p_amount:" << _amount;
	_amount = _amount - withdrawal;
	if (checkAmount() == 1)
	{
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount = _totalAmount - withdrawal;
		std::cout << ";withdrawal:" << withdrawal \
				  << ";amount:" << _amount \
				  << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return (1);
	}
	else
	{
		_amount = _amount + withdrawal;
		std::cout << ";withdrawal:refused" << std::endl;
		return (0);
	}
	return (1);
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount = _totalAmount - _amount;
	_totalNbDeposits = _totalNbDeposits - _nbDeposits;
	_totalNbWithdrawals = _totalNbWithdrawals - _nbWithdrawals;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex \
				<< ";amount:" << _amount \
				<< ";closed" << std::endl;
}