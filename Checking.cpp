#include <iostream>

#include "Checking.h"

void Checking::writeCheck(double checkBalance)
{
	numberChecks--;
	balance -= checkBalance;
}

void Checking::show()
{
	std::cout << "Account number: " << acctNumber << "\n";
	std::cout << "Account balance: " << balance << "\n";
	if (status == Account::Status::Open)
		std::cout << "Account status: open\n";
	else
		std::cout << "Account status: closed\n";
	std::cout << "Remaining checks: " << numberChecks << "\n";
}
