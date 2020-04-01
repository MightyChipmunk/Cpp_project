#include <iostream>
#include <cstring>
#include "header.h"
#define MAX 100
using namespace std;

Account::Account(int num, char* name, int money) : Accnum(num), Accmoney(money) {
	int len = strlen(name) + 1;
	Accname = new char[len];
	//strcpy_s(Accname, len, name);
	strcpy(Accname, name);
}

Account::Account(const Account &copy) :Accnum(copy.Accnum), Accmoney(copy.Accmoney) {
	int len = strlen(copy.Accname) + 1;
	Accname = new char[len];
	//strcpy_s(Accname, len, copy.Accname);
	strcpy(Accname, copy.Accname);
} //복사 생성자 추가

Account::Account() {
	Accnum = 0;
	Accname = NULL;
	Accmoney = 0;
} //객체 배열 선언을 위한 생성자

int Account::GetNum() const {
	return Accnum;
} //const로 선언이 가능한 함수
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
//Account 멤버들

AccountHandler::AccountHandler() {
	index = 0;
}

void AccountHandler::ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 ";
}
void AccountHandler::GetAccount() {
	int num, money;
	char* name;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: "; cin >> num;
	cout << "이름: "; cin >> name;
	cout << "입금액: "; cin >> money;
	acc[index] = new Account(num, name, money);
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
	cout << "잘못된 ID입니다." << endl << endl;
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
	cout << "잘못된 ID입니다." << endl << endl;
}
void AccountHandler::Print() {
	for (int i = 0; i < index; i++) {
		acc[i]->PrintAccount();
	}
}
AccountHandler::~AccountHandler() {
	for (int i = 0; i < index; i++) 
		delete[] acc[i]; 
	delete[] acc;
}
//AccountHandler 멤버들