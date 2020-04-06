#include <iostream>
#include <string>
#define MAX 100
using namespace std;

struct account {
	int accnum;
	string accname;
	int accmoney;
};

void makeaccout(account *str, int index) {
	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> str[index].accnum;
	cin.ignore(32767, '\n');
	cout << "이름: ";
	getline(cin, str[index].accname);
	cout << "입금액: ";
	cin >> str[index].accmoney;
}

void deposit(account *str) {
	int id;
	int money;
	cout << "[입금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;
	for (int i = 0; i < MAX; i++) {
		if (str[i].accnum == id) {
			str[i].accmoney += money;
			break;
		}
		else;
	}
	cout << "입금완료" << endl;
}

void withdraw(account *str) {
	int id;
	int money;
	cout << "[출금]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;
	for (int i = 0; i < MAX; i++) {
		if (str[i].accnum == id) {
			str[i].accmoney -= money;
			break;
		}
		else;
	}
	cout << "출금완료" << endl;
}

void printaccount(account *str, int index) {
	for (int i = 0; i < index; i++) {
		cout << "계좌ID " << str[i].accnum << endl;
		cout << "이름 " << str[i].accname << endl;
		cout << "잔액 " << str[i].accmoney << endl;
	}
}

int main(void) {
	account acc[MAX];
	int index = 0;

	while (1) {
		cout << "-----Menu-----" << endl;
		cout << "1. 계좌개설" << endl;
		cout << "2. 입금" << endl;
		cout << "3. 출금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 ";
		
		int choice;
		cin >> choice;

		if (choice == 1) {
			makeaccout(acc, index);
			index++;
			cout<<endl;
		}
		else if (choice == 2) {
			deposit(acc);
			cout << endl;
		}
		else if (choice == 3) {
			withdraw(acc);
			cout << endl;
		}
		else if (choice == 4) {
			printaccount(acc, index);
			cout << endl;
		}
		else if (choice == 5) {
			break;
		}
	}

	return 0;
}
