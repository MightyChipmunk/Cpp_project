#include "BankingCommonDecl.h"
#include "AccountException.h"
#include "Account.h"

Account::Account(int num, String name, int money) : Accnum(num), Accname(name) {
	if (money < 0)
		throw MinusException(money);
	else
		Accmoney = money;
}

Account::Account() {
	Accnum = 0;
	Accname;
	Accmoney = 0;
} //��ü �迭 ������ ���� ������, �ʿ�� ���������� �׳� ����

int Account::GetNum() const {
	return Accnum;
} //const�� ������ ������ �Լ�

int Account::GetMoney() const {
	return Accmoney;
}

void Account::AddMoney(int num) {
	if(num < 0)
		throw MinusException(num);
	Accmoney += num;
}

void Account::SubMoney(int num) {
	if (num > Accmoney)
		throw WithdrawException(num);
	Accmoney -= num;
}

void Account::PrintAccount() const {
	cout << "����ID: " << Accnum << endl;
	cout << "�̸�: " << Accname << endl;
	cout << "�ܾ�: " << Accmoney << endl << endl;
} //const�� ������ ������ �Լ�


