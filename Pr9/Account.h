#pragma once
#include "StringClass.h"

class Account {
private:
	int Accnum;
	String Accname;
	int Accmoney;
public:
	Account(int num, String name, int money);\
	Account();
	int GetNum() const; //const�� ������ ������ �Լ�
	int GetMoney() const;
	virtual void AddMoney(int num);
	void SubMoney(int num);
	void PrintAccount() const; //const�� ������ ������ �Լ�
};