#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include "myrandom.h"
#include "Customer.h"

class Checking : public Account
{
protected:
	int numberChecks;
public:
	Checking() : Account(getRandomInteger(0,5000), Account::Status::Closed, 0), numberChecks(10) {}\

	void depositMoney(double depositAmount) { balance += depositAmount; }
	void withdrawMoney(double withdrawAmount) {balance -= withdrawAmount; }

	void orderChecks(int orderedChecks) { numberChecks += orderedChecks; }
	void writeCheck(double checkBalance);

	void show() override;
};

#endif