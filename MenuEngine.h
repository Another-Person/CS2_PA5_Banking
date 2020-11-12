#ifndef MENUENGINE_H
#define MENUENGINE_H

#include <vector>

#include "Customer.h"
#include "Checking.h"
#include "Savings.h"


class MenuEngine
{
public:
	static int mainMenu();

	static void createNewCustomer();
	static Customer* loginMenu();

	static void customerMenu(Customer& customer);
	static void checkingAccountMenu(Checking& checkingAccount);
	static void savingsAccountMenu(Savings& savingsAccount);

private:
	static std::vector<Customer> customerList;
	static std::vector<std::string> pinList;

};

#endif