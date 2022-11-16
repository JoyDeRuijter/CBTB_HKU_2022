#include <iostream>
#include "Bankaccount.h"
#include "Transaction.h"

int main()
{
	Bankaccount bankAcc("Joy de Ruijter");

	Transaction t1(928.15);
	Transaction t2(49.27);
	Transaction t3(-82.33);
	Transaction t4(556.00);
	Transaction t5(-29.99);

	bankAcc += t1;
	bankAcc += t2;
	bankAcc += t3;
	bankAcc += t4;
	bankAcc += t5;

	std::cout << bankAcc << std::endl;
}