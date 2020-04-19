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
		cout << "�Աݾ��� 0���� �۽��ϴ�. �ٽ� �Է����ֽʽÿ�." << endl << endl;
	}
};

class WithdrawException :public AccountException {
private:
	int money;
public:
	WithdrawException(int expn) :money(expn) {}
	void ShowException() {
		cout << "�ܾ�: " << money << ", �ܾ׺����Դϴ�." << endl << endl;
	}
};