#include <iostream>
#include <cstring>
#include "pr2.h"
#define MAX 100
using namespace std;

namespace func {
	void ShowMenu() {
		cout << "-----Menu-----" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� ";
	}
	void GetAccount(int &num, char *name, int &money) {
		cout << "[���°���]" << endl;
		cout << "����ID: "; cin >> num;
		cout << "�̸�: "; cin >> name;
		cout << "�Աݾ�: "; cin >> money;
		cout << endl;
	}
	void DepositMenu(Account **acc, int index) {
		int num, money;
		cout << "[�Ա�]" << endl;
		cout << "����ID: "; cin >> num;
		for (int i = 0; i < index; i++) {
			if (acc[i]->GetNum() == num) {
				cout << "�Աݾ�: "; cin >> money;
				acc[i]->AddMoney(money);
				cout << "�ԱݿϷ�" << endl << endl;
				return;
			}
		}
		cout << "�߸��� ID�Դϴ�." << endl << endl;
	}
	void WithdrawMenu(Account **acc, int index) {
		int num, money;
		cout << "[���]" << endl;
		cout << "����ID: "; cin >> num;
		for (int i = 0; i < index; i++) {
			if (acc[i]->GetNum() == num) {
				cout << "��ݾ�: "; cin >> money;
				acc[i]->SubMoney(money);
				cout << "��ݿϷ�" << endl << endl;
				return;
			}
		}
		cout << "�߸��� ID�Դϴ�." << endl << endl;
	}
	void Print(Account **acc, int index) {
		for (int i = 0; i < index; i++) {
			acc[i]->PrintAccount();
		}
	}
}


Account::Account(int num, char* name, int money) : Accnum(num), Accmoney(money) {
	int len = strlen(name) + 1;
	Accname = new char[len];
	strcpy_s(Accname, len, name);
}

Account::Account() {
	Accnum = 0;
	Accname = NULL;
	Accmoney = 0;
} //��ü �迭 ������ ���� ������

int Account::GetNum() {
	return Accnum;
}
void Account::AddMoney(int num) {
	Accmoney += num;
}
void Account::SubMoney(int num) {
	Accmoney -= num;
}
void Account::PrintAccount() {
	cout << "����ID: " << Accnum << endl;
	cout << "�̸�: " << Accname << endl;
	cout << "�ܾ�: " << Accmoney << endl << endl;
}
Account::~Account() {
	delete[] Accname;
}

