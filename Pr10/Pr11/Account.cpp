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
} //객체 배열 선언을 위한 생성자, 필요는 없어졌지만 그냥 나둠

int Account::GetNum() const {
	return Accnum;
} //const로 선언이 가능한 함수

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
	cout << "계좌ID: " << Accnum << endl;
	cout << "이름: " << Accname << endl;
	cout << "잔액: " << Accmoney << endl << endl;
} //const로 선언이 가능한 함수


