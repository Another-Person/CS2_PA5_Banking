#ifndef SAVINGS_H
#define SAVINGS_H

#include "myrandom.h"
#include "Account.h"

class Savings : public Account
{
protected:
	double interestRate;
	double matureBalance;
public:
	Savings() : Account(getRandomInteger(5001,10000), Account::Status::Closed, 0), interestRate(1.03), matureBalance(0) {}

	void openAccount(double balance);
	void show() override;
};

#endif