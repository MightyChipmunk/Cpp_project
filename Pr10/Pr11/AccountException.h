#pragma once
#include "BankingCommonDecl.h"

class AccountException {
public:
	virtual void ShowException() = 0;
};

class MinusException :public AccountException {
private:
	int money;
public:
	MinusException(int expn) :money(expn) {}
	void ShowException() {
		cout << "입금액이 0보다 작습니다. 다시 입력해주십시오." << endl << endl;
	}
};

class WithdrawException :public AccountException {
private:
	int money;
public:
	WithdrawException(int expn) :money(expn) {}
	void ShowException() {
		cout << "잔액: " << money << ", 잔액부족입니다." << endl << endl;
	}
};