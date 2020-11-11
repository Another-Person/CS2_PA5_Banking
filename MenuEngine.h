#ifndef MENUENGINE_H
#define MENUENGINE_H

#include <vector>

#include "Customer.h"
#include "Checking.h"
#include "Savings.h"



int mainMenu();

Customer& createNewCustomer(const std::vector<int>& pinList);
Customer& loginMenu(std::vector<Customer>& customerList);

int customerMenu(Customer& customer);
int checkingAccountMenu(Checking& checkingAccount);
int savingsAccountMenu(Savings& savingsAccount);


#endif