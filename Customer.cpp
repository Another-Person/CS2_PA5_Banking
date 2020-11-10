#include "Customer.h"
#include "Checking.h"
#include "Savings.h"
#include "Account.h"

bool Customer::isCheckingAccountOpen()
{
	if (checkingAccount.status == Account::Status::Open)
		return true;
	else
		return false;
}

bool Customer::isSavingsAccountOpen()
{
	if (savingsAccount.status == Account::Status::Open)
		return true;
	else
		return false;
}
