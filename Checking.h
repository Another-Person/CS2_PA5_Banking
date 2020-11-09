#ifndef CHECKING_H
#define CHECKING_H

#include "Account.h"
#include "myrandom.h"

class Checking : public Account
{
protected:
	int numberChecks;
public:
	Checking(double startBalance) : Account(getRandomInteger(0,5000), Account::Status::Closed, startBalance), numberChecks(10) {}\

	
};

#endif