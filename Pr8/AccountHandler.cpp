#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

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
	char* name = new char[MAX];
	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "이미 존재하는 ID입니다." << endl;
			return;
		}
	}
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> interest;
	acc[index] = new NormalAccount(num, name, money, interest);
	cout << endl;
	index++;
}

void AccountHandler::MakeHighCreditAccount() {
	int num, money, interest, grade;
	char* name = new char[MAX];
	cout << "[신뢰예금계좌 개설]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "이미 존재하는 ID입니다." << endl;
			return;
		}
	}
	cout << "이 름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	cout << "이자율: "; cin >> interest;
	cout << "신용등급(1toA, 2toB, 3toC): "; cin >> grade;
	acc[index] = new HighCreditAccount(num, name, money, interest, grade);
	cout << endl;
	index++;
}

void AccountHandler::DepositMenu() {
	int num, money;
	cout << "[입금]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "입금액: "; cin >> money;
			acc[i]->AddMoney(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "잘못된 입력입니다." << endl << endl;
}

void AccountHandler::WithdrawMenu() {
	int num, money;
	cout << "[출금]" << endl;
	cout << "계좌ID: "; cin >> num;
	for (int i = 0; i < index; i++) {
		if (acc[i]->GetNum() == num) {
			cout << "출금액: "; cin >> money;
			acc[i]->SubMoney(money);
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "잘못된 입력입니다." << endl << endl;
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