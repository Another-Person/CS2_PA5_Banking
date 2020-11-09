#include "Account.h"

void Account::closeAccount()
{
	status = Account::Status::Closed;
	balance = 0; // Closed accounts shouldn't have any funds
}

void Account::openAccount(double balance)
{
	status = Account::Status::Open;
	this->balance = balance;
}
