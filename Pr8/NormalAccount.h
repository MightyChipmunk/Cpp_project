#pragma once
#include "Account.h"

class NormalAccount : public Account {
private:
	int Interest;
public:
	NormalAccount(int num, char* name, int money, int _interest) : Account(num, name, money), Interest(_interest) {}
	void AddMoney(int num) {
		Account::AddMoney(num);
		Account::AddMoney((int)(Interest * GetMoney() * 0.01));
	}
};