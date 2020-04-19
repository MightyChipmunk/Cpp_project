#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"
#include "AccountException.h"

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
	String name;
	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "�̹� �����ϴ� ID�Դϴ�." << endl;
			return;
		}
	}
	cout << "�� ��: "; cin >> name;
	while (1) {
		try {
			cout << "�Աݾ�: "; cin >> money;
			cout << "������: "; cin >> interest;
			cout << endl;
			acc[index] = new NormalAccount(num, name, money, interest);
			break;
		}
		catch (AccountException &expn) {
			expn.ShowException();
		}
	}
	index++;
}

void AccountHandler::MakeHighCreditAccount() {
	int num, money, interest, grade;
	String name;
	cout << "[�ŷڿ��ݰ��� ����]" << endl;
	cout << "����ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "�̹� �����ϴ� ID�Դϴ�." << endl;
			return;
		}
	}
	cout << "�� ��: "; cin >> name;
	while (1) {
		try {
			cout << "�Աݾ�: "; cin >> money;
			cout << "������: "; cin >> interest;
			cout << "�ſ���(1toA, 2toB, 3toC): "; cin >> grade;
			cout << endl;
			acc[index] = new HighCreditAccount(num, name, money, interest, grade);
			break;
		}
		catch (AccountException &expn) {
			expn.ShowException();
		}
	}
	index++;
	
}

void AccountHandler::DepositMenu() {
	int num, money;
	cout << "[�Ա�]" << endl;
	cout << "����ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			while (1) {
				try {
					cout << "�Աݾ�: "; cin >> money;
					cout << endl;
					acc[i]->AddMoney(money);
					break;
				}
				catch (AccountException &expn) {
					expn.ShowException();
				}
			}
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "����ID�� ��ġ�ϴ� ���°� �����ϴ�." << endl << endl;
}

void AccountHandler::WithdrawMenu() {
	int num, money;
	cout << "[���]" << endl;
	cout << "����ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			while (1) {
				try {
					cout << "��ݾ�: "; cin >> money;
					cout << endl;
					acc[i]->SubMoney(money);
					break;
				}
				catch (AccountException &expn) {
					expn.ShowException();
				}
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "����ID�� ��ġ�ϴ� ���°� �����ϴ�." << endl << endl;
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