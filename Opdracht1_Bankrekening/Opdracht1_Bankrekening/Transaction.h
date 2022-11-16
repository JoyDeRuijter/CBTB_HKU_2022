#pragma once
#include <ctime>
#include <string>

class Transaction
{
	public:
		Transaction(float _Amount);

		float Amount;
		std::string DateAndTime;
		
		std::string typeOfTransaction() const; //debit/credit 
};

