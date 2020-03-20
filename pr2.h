#pragma once
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

class Account {
	int Accnum;
	char* Accname;
	int Accmoney;

public:
	Account(int num, char* name, int money);
	Account();
	int GetNum();
	void AddMoney(int num);
	void SubMoney(int num);
	void PrintAccount() const;
	~Account();
};

namespace func {
	void ShowMenu();
	void GetAccount(int &num, char* name, int &money);
	void DepositMenu(Account **acc);
	void WithdrawMenu(Account **acc);
	void Print(Account **acc, int index);
}