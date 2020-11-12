#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

#include "Checking.h"
#include "MenuEngine.h"
#include "Savings.h"

class Customer
{
public:
	Customer() : name(""), pin(), checkingAccount(), savingsAccount() {}

	bool isCheckingAccountOpen();
	bool isSavingsAccountOpen();

	void showCustomerInfo();

	std::string getName() { return name; }
	bool checkPIN(std::string pinToCheck) { return (pin == pinToCheck); }

	void openCheckingAccount(double balance) { checkingAccount.openAccount(balance); }
	void closeCheckingAccount() { checkingAccount.closeAccount(); }
	void openSavingsAccount(double balance) { savingsAccount.openAccount(balance); }
	void closeSavingsAccount() { savingsAccount.closeAccount(); }

	friend class MenuEngine;

protected:
	std::string name;
	std::string pin;
	Checking checkingAccount;
	Savings savingsAccount;
	
};

#endif