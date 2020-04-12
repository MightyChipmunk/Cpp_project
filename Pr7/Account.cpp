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
} //���� ������ �߰�

Account::Account() {
	Accnum = 0;
	Accname = NULL;
	Accmoney = 0;
} //��ü �迭 ������ ���� ������
int Account::GetNum() const {
	return Accnum;
} //const�� ������ ������ �Լ�

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
	cout << "����ID: " << Accnum << endl;
	cout << "�̸�: " << Accname << endl;
	cout << "�ܾ�: " << Accmoney << endl << endl;
} //const�� ������ ������ �Լ�

Account::~Account() {
	delete[] Accname;
}
