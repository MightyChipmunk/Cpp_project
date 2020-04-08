#pragma once
#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;

class Account {
private:
	int Accnum;
	char* Accname;
	int Accmoney;
public:
	Account(int num, char* name, int money);
	Account(const Account &copy);
	Account();
	int GetNum() const; //const로 선언이 가능한 함수
	int GetMoney() const;
	virtual void AddMoney(int num);
	void SubMoney(int num);
	void PrintAccount() const; //const로 선언이 가능한 함수
	virtual ~Account();
};

class NormalAccount : public Account {
private:
	int Interest;
public:
	NormalAccount(int num, char* name, int money, int _interest);
	void AddMoney(int num);
};

class HighCreditAccount : public NormalAccount {
private:
	int Grade;
public:
	HighCreditAccount(int num, char* name, int money, int interest, int _grade);
	void AddMoney(int num);
};

class AccountHandler {
private:
	int index;
	Account *acc[MAX];
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void MakeNormalAccount();
	void MakeHighCreditAccount();
	void DepositMenu();
	void WithdrawMenu();
	void Print() const;
	~AccountHandler();
};
