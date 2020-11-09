#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	enum class Status
	{
		Closed,
		Open
	};

	Account(int number, Status acctStatus, double startBalance): acctNumber(number), status(acctStatus), balance(startBalance) {}

	void closeAccount();
	void openAccount(double balance);
	virtual void show() = 0;
	
protected:
	int acctNumber;
	Status status;
	double balance;
	
};

#endif

