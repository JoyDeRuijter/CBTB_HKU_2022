#pragma once
#include "Transaction.h"
#include <vector>
#include <iostream>
#include <string>

class Bankaccount
{
	public:
		//For a new empty bankaccount
		Bankaccount(std::string _Owner);
		//For an existing bankaccount
		Bankaccount(std::string _Owner, float _Saldo, std::vector<Transaction> _TransactionHistory);

		std::string Owner;
		float Saldo;
		std::vector<Transaction> TransactionHistory;

		Bankaccount operator+(const Transaction& _Transaction);
		Bankaccount operator+=(const Transaction& _Transaction);

		friend std::ostream& operator<<(std::ostream& _OS, const Bankaccount& _Bankaccount);

	private:
		void handleTransaction(const Transaction& _Transaction);
};

