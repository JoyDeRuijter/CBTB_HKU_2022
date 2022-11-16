#include "Transaction.h"
#include <iostream>
#include <ctime>

Transaction::Transaction(float _Amount)
{
	Amount = _Amount;

	time_t ttime = time(0);
	char dt[26];
	ctime_s(dt, sizeof dt, &ttime);
	DateAndTime = dt;
}

std::string Transaction::typeOfTransaction() const
{
	if (Amount > 0)
		return "CREDIT";
	else if (Amount < 0)
		return "DEBIT";
	else
		return "BLANC";
}
