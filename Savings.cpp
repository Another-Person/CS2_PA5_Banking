#include "Savings.h"
#include <iostream>

void Savings::openAccount(double balance)
{
	Account::openAccount(balance);
	matureBalance = balance * interestRate;
}

void Savings::show()
{
	std::cout << "Account number: " << acctNumber << "\n";
	std::cout << "Account balance: " << balance << "\n";
	if (status == Account::Status::Open)
		std::cout << "Account status: open\n";
	else
		std::cout << "Account status: closed\n";
	std::cout << "Mature balance: " << matureBalance << "\n";
}
