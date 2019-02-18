
#include <iostream>
#include<string>
#include "q1_l181009_Header.h"

using namespace std;

bank_account::bank_account()
{
	string name;
	int id;
	cout << "Enter your Name : ";
	cin >> name;
	cout << "Enter ID: ";
	cin >> id;
	account_name = name;
	account_id = id;
	balance = 0;
	limit = 200000;
	total_transactions = 3;
	transactions_made = 0;
	transactions = new int[total_transactions];
}

bank_account::bank_account(string name, int id)
{
	account_name = name;
	account_id = id;
	balance = 0;
	limit = 200000;
	total_transactions = 3;
	transactions_made = 0;
	transactions = new int[total_transactions];
}

void bank_account::display_info()
{
	cout << " -> Account Holder's Name : " << account_name << endl;
	cout << " -> Account Holder's ID : " << account_id << endl;
	cout << " -> Account Balance : " << balance << endl;
	cout << " -> Account Transactions Made : " << transactions_made << endl;
	if (transactions_made > 0)
	{
		cout << "Details of transactions : " << endl;
		for (int i = 0; i < transactions_made;i++)
		{
			cout << transactions[i] << endl;
		}
	}
}

void bank_account::increase_transactions()
{
	//cout << "Increasing...." << endl;
	int temp = total_transactions;
	int * temp_arr = new int[temp];
	total_transactions = total_transactions * 2;
	for (int i = 0; i < temp; i++)
	{
		temp_arr[i] = transactions[i];
	}
	delete[] transactions;
	transactions = new int[total_transactions];
	for (int i = 0; i < temp;i++)
	{
		transactions[i] = temp_arr[i];
	}
	delete[] temp_arr;

}

void bank_account::withdraw(int amount)
{
	if (transactions_made >= total_transactions)
		increase_transactions();
	if (balance < amount)
		cout << "Insufficient Balance. Your remaining balance is : " << balance << endl;
	else
	{
		balance = balance - amount;
		transactions[transactions_made] = -amount;
		transactions_made++;
	}
}

void bank_account::set_limit(int amount)
{
	limit = amount;
}

void bank_account::deposit(int amount)
{
	if (transactions_made >= total_transactions)
		increase_transactions();

	if ((amount + balance) <= limit)
	{
		balance = balance + amount;
		transactions[transactions_made] = amount;
		transactions_made++;
	}
	else
		cout << "You've reached the limit. Your balance limit is : " << limit << endl;
}

bank_account::~bank_account()
{
	account_name = "";
	account_id = NULL;
	balance = NULL;
	limit = NULL;
	total_transactions = NULL;
	transactions_made = NULL;
	delete[] transactions;
	transactions = nullptr;
}