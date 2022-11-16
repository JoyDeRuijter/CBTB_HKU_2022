#include "Bankaccount.h"

Bankaccount::Bankaccount(std::string _Owner)
{
	Owner = _Owner;
	Saldo = 0;
}

Bankaccount::Bankaccount(std::string _Owner, float _Saldo, std::vector<Transaction> _TransactionHistory)
{
	Owner = _Owner;
	Saldo = _Saldo;
	TransactionHistory = _TransactionHistory;
}

Bankaccount Bankaccount::operator+(const Transaction& _Transaction)
{
	//Bankaccount BankAcc(Owner, Saldo, TransactionHistory);
	//BankAcc.handleTransaction(_Transaction);
	handleTransaction(_Transaction);
	return *this;
}

Bankaccount Bankaccount::operator+=(const Transaction& _Transaction)
{
	handleTransaction(_Transaction);
	return *this;
}

void Bankaccount::handleTransaction(const Transaction& _Transaction)
{
	Saldo += _Transaction.Amount;
	TransactionHistory.push_back(_Transaction);
}

std::ostream& operator<<(std::ostream& _OS, const Bankaccount& _Bankaccount)
{
	_OS << "BANKACCOUNT - " << _Bankaccount.Owner << std::endl
		<< "CURRENT SALDO: " << _Bankaccount.Saldo << std::endl;

	if (_Bankaccount.TransactionHistory.size() != 0)
	{
		_OS << std::endl
			<< "\t --TRANSACTION HISTORY-- " << std::endl;

		for (int i = 0; i < _Bankaccount.TransactionHistory.size(); i++)
		{
			const Transaction& T = _Bankaccount.TransactionHistory.at(i);

			_OS << "\t \t TYPE OF TRANSACTION: " << T.typeOfTransaction() << std::endl
				<< "\t \t TRANSACTION AMOUNT: $" << T.Amount << std::endl
				<< "\t \t TIME/DATE OF TRANSACTION: " << T.DateAndTime << std::endl;
		}
	}

	return _OS;
}
