#pragma once

#include <string>

class bank_account
{
private:
	string account_name;
	int account_id;
	float balance;
	float limit;
	int total_transactions;
	int transactions_made;
	int * transactions;
	void increase_transactions();

public:
	bank_account();
	bank_account(string name, int id);
	void display_info();
	void withdraw(int amount);
	void set_limit(int amount);
	void deposit(int amount);
	~bank_account();
};
