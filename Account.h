#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "Customer.h"

class Account
{
public:
	virtual ~Account() = default;

	enum class Status
	{
		Closed,
		Open
	};

	Account(int number, Status acctStatus, double startBalance): acctNumber(number), status(acctStatus), balance(startBalance) {}

	void closeAccount();
	void openAccount(double balance);
	virtual void show() = 0;

	friend class Customer;
	
protected:
	int acctNumber;
	Status status;
	double balance;
	
};

#endif

