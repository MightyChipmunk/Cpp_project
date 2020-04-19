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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 ";
}

void AccountHandler::MakeAccount() {
	int choice;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	cout << "선택: "; cin >> choice;
	if (choice == 1) {
		MakeNormalAccount();
	}
	else if (choice == 2) {
		MakeHighCreditAccount();
	}
	else
		cout << "잘못된 선택입니다." << endl;
}

void AccountHandler::MakeNormalAccount() {
	int num, money, interest;
	String name;
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "이미 존재하는 ID입니다." << endl;
			return;
		}
	}
	cout << "이 름: "; cin >> name;
	while (1) {
		try {
			cout << "입금액: "; cin >> money;
			cout << "이자율: "; cin >> interest;
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
	cout << "[신뢰예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "이미 존재하는 ID입니다." << endl;
			return;
		}
	}
	cout << "이 름: "; cin >> name;
	while (1) {
		try {
			cout << "입금액: "; cin >> money;
			cout << "이자율: "; cin >> interest;
			cout << "신용등급(1toA, 2toB, 3toC): "; cin >> grade;
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
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			while (1) {
				try {
					cout << "입금액: "; cin >> money;
					cout << endl;
					acc[i]->AddMoney(money);
					break;
				}
				catch (AccountException &expn) {
					expn.ShowException();
				}
			}
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "계좌ID가 일치하는 계좌가 없습니다." << endl << endl;
}

void AccountHandler::WithdrawMenu() {
	int num, money;
	cout << "[출금]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			while (1) {
				try {
					cout << "출금액: "; cin >> money;
					cout << endl;
					acc[i]->SubMoney(money);
					break;
				}
				catch (AccountException &expn) {
					expn.ShowException();
				}
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "계좌ID가 일치하는 계좌가 없습니다." << endl << endl;
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