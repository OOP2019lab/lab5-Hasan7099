
#include <iostream>
#include<string>
#include "q1_l181009_Header.h"

using namespace std;

void est()
{
	string name = "John";
	int id = 123;
	bank_account account;
	account.display_info();
	cout << endl;
	account.deposit(15000);
	account.withdraw(2000);
	account.withdraw(1500);
	account.withdraw(4000);
	account.deposit(1500000);

	//account.~bank_account();

	cout << endl;
	account.display_info();
}

int main()
{
	est();
	system("pause");
	return 0;
}