#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

#include "Checking.h"
#include "Savings.h"

class Customer
{
public:
	Customer() : name(""), pin(0), checkingAccount(), savingsAccount() {}

	bool isCheckingAccountOpen();
	bool isSavingsAccountOpen();

	void showCustomerInfo();

protected:
	std::string name;
	int pin;
	Checking checkingAccount;
	Savings savingsAccount;
	
};

#endif