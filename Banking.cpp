#include <iostream>
#include <vector>

#include "Customer.h"
#include "MenuEngine.h"


int main()
{
	std::vector<Customer> customerList;
	std::vector<int> pinList;
	int menuAction = 0;
	
	while (true)
	{
		menuAction = mainMenu();
		switch (menuAction)
		{
		case 1:
			customerList.push_back(createNewCustomer(pinList));
			break;
		case 2:
			customerMenu(loginMenu(customerList));
			break;
		case 3:
			return 0;
		default:
			std::cout << "I'm sorry, but we could not understand your input. Please try again. \n";
			break;
		}
	}
}