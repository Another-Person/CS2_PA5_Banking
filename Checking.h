#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include "myrandom.h"

class Checking : public Account
{
public:
	Checking() : Account(getRandomInteger(0,5000), Account::Status::Closed, 0), numberChecks(10) {}\

	void depositMoney(double depositAmount) { balance += depositAmount; }
	void withdrawMoney(double withdrawAmount) {balance -= withdrawAmount; }

	void orderChecks(int orderedChecks) { numberChecks += orderedChecks; }
	void writeCheck(double checkBalance);

	void show() override;

protected:
	int numberChecks;

};

#endif