#include  <iostream>

#include "Account.h"
#include "Customer.h"
#include "Checking.h"
#include "Savings.h"

bool Customer::isCheckingAccountOpen()
{
	if (checkingAccount.status == Account::Status::Open)
		return true;
	else
		return false;
}

bool Customer::isSavingsAccountOpen()
{
	if (savingsAccount.status == Account::Status::Open)
		return true;
	else
		return false;
}

void Customer::showCustomerInfo()
{
	std::cout << "Customer name: " << name << "\n";
	std::cout << "Customer PIN: " << pin << "\n";

	std::cout << "Checking account info: \n";
	if (isCheckingAccountOpen() == true)
		checkingAccount.show();
	else
		std::cout << "No open checking account to show. \n";

	std::cout << "Savings account info: \n";
	if (isSavingsAccountOpen() == true)
		savingsAccount.show();
	else
		std::cout << "No open savings account to show. \n";
}
