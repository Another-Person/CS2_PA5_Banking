#include <iostream>
#include <cmath>

#include "MenuEngine.h"
#include "Customer.h"

int mainMenu()
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

Customer& createNewCustomer(std::vector<int>& pinList)
{
	std::cout << "Please enter the name for the new account: ";
	std::string name;
	std::getline(std::cin, name);
	std::cout << "\n";

	int pin = getProperPIN(pinList);
	pinList.push_back(pin);

	Customer tempCustomer = Customer();
	tempCustomer.name = name;
	tempCustomer.pin = pin;
	return tempCustomer;
}

Customer* loginMenu(std::vector<Customer>& customerList)
{
	std::cout << "Please select whether you would like to login with a name or PIN: \n";
	std::cout << "1 - Login via name \n";
	std::cout << "2 - Login via PIN \n";

	int selection = 0;
	std::cin >> selection;
	std::cin.ignore(32767, '\n');

	Customer* returnCustomer = nullptr;
	
	switch (selection)
	{
	case 0:
		std::cout << "I'm sorry, but we could not understand your input. Please type either a '1' or a '2'. \n";
		break;
	case 1:
		std::cout << "filler text running a build test";

	}
}
