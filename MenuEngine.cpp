#include <iostream>
#include <cmath>

#include "MenuEngine.h"
#include "Customer.h"

int MenuEngine::mainMenu()
{
	std::cout << "Welcome to 5 Star Banking(tm)! \n";
	std::cout << "Please select an option by typing the leading number: \n";
	std::cout << "1 - Create new customer account. \n";
	std::cout << "2 - Login to an existing customer account. \n";
	std::cout << "3 - Exit the program. \n";

	int returnValue = 0;
	std::cin >> returnValue;
	return returnValue;
	
}

int getProperPIN(const std::vector<int>& pinList)
{
	std::cout << "Please enter the four-digit PIN for the new account: ";
	int pin = 0;
	std:: cin >> pin;

	std::cin.ignore(32767, '\n'); // I know it should be something like "numeric limits streamsize max" but even I have limits on how far I'm willing to go
	if (pin == 0)
	{
		std::cout << "I'm sorry, but we could not understand your input. Please try again, making sure to only type four digits 0-9. \n";
		pin = getProperPIN(pinList);
	}
	if (static_cast<int>(log10(pin) + 1) != 4)
	{
		std::cout << "I'm sorry, but the PIN must be 4 digits long. Please try again, making sure to only enter 4 digits.";
		pin = getProperPIN(pinList);
	}

	for (int element : pinList)
	{
		if (element == pin)
		{
			std::cout << "I'm sorry, but that PIN is currently in use by another account. Please choose a different PIN. \n";
			pin = getProperPIN(pinList);
		}
	}

	return pin;
}

void MenuEngine::createNewCustomer()
{
	std::cout << "Please enter the name for the new account: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "\n";

	int pin = getProperPIN(pinList);
	pinList.push_back(pin);

	Customer tempCustomer;
	tempCustomer.name = name;
	tempCustomer.pin = pin;
	customerList.push_back(tempCustomer);
}

Customer* MenuEngine::loginMenu()
{
	std::cout << "Please select whether you would like to login with a name or PIN: \n";
	std::cout << "1 - Login via name \n";
	std::cout << "2 - Login via PIN \n";
	std::cout << "3 - Return to main menu \n";

	int selection = 0;
	std::cin >> selection;
	std::cin.ignore(32767, '\n');

	Customer* returnCustomer = nullptr;
	
	switch (selection)
	{
	case 1:
	{
		std::cout << "Please enter the customer name: ";
		std::string name;
		std::getline(std::cin, name);
		for (Customer customer : customerList)
		{
			if (customer.getName() == name)
				returnCustomer = &customer;
		}
		if (returnCustomer == nullptr)
		{
			std::cout << "I'm sorry, but no existing customer could be found with that name. Please try again. \n";
			returnCustomer = loginMenu();
		}
		break;
	}
	case 2:
	{
		std::cout << "Please enter the customer PIN: ";
		int pin;
		std::cin >> pin;
		std::cin.ignore(32767, '\n');
		if (static_cast<int>(log10(pin) + 1) != 4)
		{
			std::cout << "I'm sorry, but the PIN must be 4 digits long. Please try again.";
			returnCustomer = loginMenu(); // yep, we're making them start over again
		}
		for (Customer customer : customerList)
		{
			if (customer.checkPIN(pin) == true)
				returnCustomer = &customer;
		}
		if (returnCustomer == nullptr)
		{
			std::cout << "I'm sorry, but no existing customer could be found with that name. Please try again. \n";
			returnCustomer = loginMenu();
		}
		break;
	}
	case 3:
		break; // Leave returnCustomer as nullptr so that it gets caught in Banking.cpp
	default:
		std::cout << "I'm sorry, but we could not understand your input. Please type either a '1', '2', or '3'. \n";
		returnCustomer = loginMenu();
		break;
	}

	return returnCustomer;
}

double getMoneyInput(std::string amountName = "amount")
{
	std::cout << "Please enter " << amountName << " in the format \"DDDDD.CC\" using only digits 0-9 and the . character: ";
	int dollars = 0;
	int cents = 0;
	std::cin >> dollars;
	std::cin.ignore(32767,'.');
	std::cin >> cents;
	std::cin.ignore(32767, '\n');
	std::cout << "\n";
	double newBalance = dollars+(static_cast<double>(cents) / 10);
	std::cout << "Is " << newBalance << "the correct " << amountName << "? Y/n ";
	std::string answer;
	std::getline(std::cin, answer);
	if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes")
	{
		return newBalance;
	}
	else
	{
		std::cout << "We're sorry, we must have mis-interpreted your input. Please try again. \n";
		return getMoneyInput(amountName);
	}
}

void MenuEngine::customerMenu(Customer& customer)
{
	bool keepRunning = true;
	while (keepRunning == true)
	{
	std::cout << "Welcome " << customer.getName() << "! \n";
	std::cout << "What would you like to do today? \n";
	std::cout << "1 - Log out and return to main menu \n";
	std::cout << "2 - Print Customer Info \n";

	const bool isCheckingOpen = customer.isCheckingAccountOpen();
	const bool isSavingsOpen = customer.isSavingsAccountOpen();

	if (isCheckingOpen == true)
		std::cout << "3 - View checking account menu \n";

	if (isSavingsOpen == true)
		std::cout << "4 - View savings account menu \n";

	if (isCheckingOpen == true)
		std::cout << "5 - Close checking account \n";
	else
		std:: cout << "5 - Open checking account \n";

	if (isSavingsOpen == true)
		std::cout << "6 - Close savings account \n";
	else
		std::cout << "6 - Open savings account \n";

	int response = 0;
	std::cin >> response;
	std::cin.ignore(32767, '\n');

	switch (response)
	{
	case 1:
		keepRunning = false;
		break;
	case 2:
		customer.showCustomerInfo();
		break;
	case 3:
			if (isCheckingOpen == true)
				checkingAccountMenu(customer.checkingAccount);
			else
				std::cout << "We're sorry, but there is no open checking account to view.";
			break;
	case 4:
		if (isSavingsOpen == true)
			savingsAccountMenu(customer.savingsAccount);
		else
			std::cout << "We're sorry, but there is no open checking account to view.";
		break;
	case 5:
		if (isCheckingOpen == true)
		{
			std::cout << "Please confirm you would like to close your checking account. Y/n ";
			std::string answer;
			std::getline(std::cin, answer);
			std::cout << "\n";
			if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes")
			{
				customer.closeCheckingAccount();
				std::cout << "Checking account closed. \n";
			}
			else
				std::cout << "Your checking account has NOT been closed. \n";
		}
		else
		{
			double newBalance = getMoneyInput("starting balance for the new account");
			customer.openCheckingAccount(newBalance);
			std::cout << "Checking account opened.\n";
		}
		break;
	case 6:
		if (isSavingsOpen == true)
		{
			std::cout << "Please confirm you would like to close your savings account. Y/n ";
			std::string answer;
			std::getline(std::cin, answer);
			std::cout << "\n";
			if (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes")
			{
				customer.closeSavingsAccount();
				std::cout << "Savings account closed. \n";
			}
			else
				std::cout << "Your Savings account has NOT been closed. \n";
		}
		else
		{
			double newBalance = getMoneyInput("starting balance for the new account");
			customer.openSavingsAccount(newBalance);
			std::cout << "Savings account opened.\n";
		}
		break;
	default:
			std::cout << "I'm sorry, but we did not understand your input. Please try again.\n";
			break;
	}
	
	}
}

void MenuEngine::checkingAccountMenu(Checking& checkingAccount)
{
	bool keepRunning = true;
	while (keepRunning == true)
	{
		std::cout << "Please select what you would like to do: \n";
		std::cout << "1 - Deposit money into account \n";
		std::cout << "2 - Withdraw money from account \n";
		std::cout << "3 - Write a check \n";
		std::cout << "4 - Order additional checks \n";
		std::cout << "5 - View account info \n";
		std::cout << "6 - Return to customer menu \n";

		int response = 0;
		std::cin >> response;
		std::cin.ignore(32767, '\n');
		std::cout << "\n";
	
		switch (response)
		{
		case 1:
			{
				double newBalance = getMoneyInput("deposit amount");
				checkingAccount.depositMoney(newBalance);
				std::cout << newBalance << " has been deposited. \n";
				break;
			}
		case 2:
			{
				double newBalance = getMoneyInput("withdrawal amount");
				checkingAccount.withdrawMoney(newBalance);
				std::cout << newBalance << " has been withdrawn. \n";
				break;
			}
		case 3:
			{
				double newBalance = getMoneyInput("check amount");
				checkingAccount.writeCheck(newBalance);
				std::cout << "A check in the amount " << newBalance << " has been written. \n";
				break;
			}
		case 4:
			{
				std::cout << "How many checks would you like to order? ";
				int checkAmount = 0;
				std::cin >> checkAmount;
				std::cin.ignore(32767, '\n');
				std::cout << "\n";
				checkingAccount.orderChecks(checkAmount);
				std::cout << checkAmount << " checks have been ordered. \n";
				break;
			}
		case 5:
			checkingAccount.show();
			break;
		case 6:
			keepRunning = false;
			break;
		default:
			std::cout << "I'm sorry, but we did not understand your input. Please try again. \n";
			break;
		}
	}
}

void MenuEngine::savingsAccountMenu(Savings& savingsAccount)
{
	bool keepRunning = true;
	while (keepRunning == true)
	{
		std::cout << "What would you like to do? \n";
		std::cout << "1 - View account info \n";
		std::cout << "2 - Return to customer menu \n";

		int response = 0;
		std::cin >> response;
		std::cin.ignore(32767, '\n');
		std::cout << "\n";

		switch (response)
		{
		case 1:
			savingsAccount.show();
			break;
		case 2:
			keepRunning = false;
			break;
		default:
			break;
		}
	}
}
