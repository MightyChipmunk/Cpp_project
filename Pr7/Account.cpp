#include "BankingCommonDecl.h"
#include "Account.h"

Account::Account(int num, char* name, int money) : Accnum(num), Accmoney(money) {
	int len = strlen(name) + 1;
	Accname = new char[len];
	strcpy_s(Accname, len, name);
	//strcpy(Accname, name);
}

Account::Account(const Account &copy) :Accnum(copy.Accnum), Accmoney(copy.Accmoney) {
	int len = strlen(copy.Accname) + 1;
	Accname = new char[len];
	strcpy_s(Accname, len, copy.Accname);
	//strcpy(Accname, copy.Accname);
} //복사 생성자 추가

Account::Account() {
	Accnum = 0;
	Accname = NULL;
	Accmoney = 0;
} //객체 배열 선언을 위한 생성자
int Account::GetNum() const {
	return Accnum;
} //const로 선언이 가능한 함수

int Account::GetMoney() const {
	return Accmoney;
}

void Account::AddMoney(int num) {
	Accmoney += num;
}

void Account::SubMoney(int num) {
	Accmoney -= num;
}

void Account::PrintAccount() const {
	cout << "계좌ID: " << Accnum << endl;
	cout << "이름: " << Accname << endl;
	cout << "잔액: " << Accmoney << endl << endl;
} //const로 선언이 가능한 함수

Account::~Account() {
	delete[] Accname;
}
