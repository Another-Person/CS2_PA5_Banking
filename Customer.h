#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include "Checking.h"
#include "Savings.h"

class Customer
{
public:
	Customer() : name(""), pin(0), checkingAccount(), savingsAccount() {}

	bool isCheckingAccountOpen();
	bool isSavingsAccountOpen();

	void showCustomerInfo();

	friend Customer& createNewCustomer(const std::vector<int>& pinList);

protected:
	std::string name;
	int pin;
	Checking checkingAccount;
	Savings savingsAccount;
	
};

#endif