#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

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
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "�̹� �����ϴ� ID�Դϴ�." << endl;
			return;
		}
	}
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
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "�̹� �����ϴ� ID�Դϴ�." << endl;
			return;
		}
	}
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