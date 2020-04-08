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
//Account 멤버들
NormalAccount::NormalAccount(int num, char* name, int money, int _interest) : Account(num, name, money), Interest(_interest) {}

void NormalAccount::AddMoney(int num) {
	Account::AddMoney(num);
	Account::AddMoney((int)(Interest * GetMoney() * 0.01));
}
//NormalAccount 멤버들
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
		cout << "잘못된 입력입니다." << endl;
	}
	Account::AddMoney(num);
	Account::AddMoney((int)((Interest + bonus) * GetMoney() * 0.01));
}
//HighCreditAccount 멤버들
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
//AccountHandler 멤버들
