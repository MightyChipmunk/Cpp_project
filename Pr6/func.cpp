#include <iostream>
#include <cstring>
#include "header.h"
#define MAX 100
using namespace std;

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
//Account �����
NormalAccount::NormalAccount(int num, char* name, int money, int _interest) : Account(num, name, money), Interest(_interest) {}

void NormalAccount::AddMoney(int num) {
	Account::AddMoney(num);
	Account::AddMoney((int)(Interest * GetMoney() * 0.01));
}
//NormalAccount �����
HighCreditAccount::HighCreditAccount(int num, char* name, int money, int _interest, int _grade) : Account(num, name, money), Interest(_interest), Grade(_grade) {}

void HighCreditAccount::AddMoney(int num) {
	int bonus;
	if (Grade == 1) {
		bonus = 7;
	}
	else if (Grade == 2) {
		bonus = 4;
	}
	else if (Grade == 3) {
		bonus = 2;
	}
	else {
		cout << "�߸��� �Է��Դϴ�." << endl;
	}
	Account::AddMoney(num);
	Account::AddMoney((int)((Interest + bonus) * GetMoney() * 0.01));
}
//HighCreditAccount �����
AccountHandler::AccountHandler() {
	index = 0;
}

void AccountHandler::ShowMenu() const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "���� ";
}

void AccountHandler::MakeAccount() {
	int choice;
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	cout << "����: "; cin >> choice;
	if (choice == 1) {
		MakeNormalAccount();
	}
	else if (choice == 2) {
		MakeHighCreditAccount();
	}
	else
		cout << "�߸��� �����Դϴ�." << endl;
}

void AccountHandler::MakeNormalAccount() {
	int num, money, interest;
	char* name = new char[MAX];
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> num;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> interest;
	acc[index] = new NormalAccount(num, name, money, interest);
	cout << endl;
	index++;
}

void AccountHandler::MakeHighCreditAccount() {
	int num, money, interest, grade;
	char* name = new char[MAX];
	cout << "[�ŷڿ��ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> num;
	cout << "�� ��: "; cin >> name;
	cout << "�Աݾ�: "; cin >> money;
	cout << "������: "; cin >> interest;
	cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> grade;
	acc[index] = new HighCreditAccount(num, name, money, interest, grade);
	cout << endl;
	index++;
}

void AccountHandler::DepositMenu() {
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
	cout << "�߸��� �Է��Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMenu() {
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
	cout << "�߸��� �Է��Դϴ�." << endl << endl;
}

void AccountHandler::Print() const {
	for (int i = 0; i < index; i++) {
		acc[i]->PrintAccount();
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < index; i++) 
		delete acc[i]; 
}
//AccountHandler �����
