#include <iostream>
#include <vector>

#include "Customer.h"
#include "MenuEngine.h"


int main()
{
	int menuAction = 0;
	
	while (true)
	{
		menuAction = MenuEngine::mainMenu();
		switch (menuAction)
		{
		case 1:
			MenuEngine::createNewCustomer();
			break;
		case 2:
		{
			Customer *tempCustomer = MenuEngine::loginMenu();
			if (tempCustomer == nullptr)
				break;
			MenuEngine::customerMenu(*(tempCustomer));
			break;
		}
		case 3:
			return 0;
		default:
			std::cout << "I'm sorry, but we could not understand your input. Please try again. \n";
			break;
		}
	}
}