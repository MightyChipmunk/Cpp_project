#include <iostream>
#include <cstring>
#include "pr2.h"
#define MAX 100
using namespace std;

int main(void) {
	Account *acc[MAX];
	int index = 0;

	while (1) {
		func::ShowMenu();

		int choice;
		cin >> choice;

		if (choice == 1) {
			int num, money;
			char* name = new char[MAX];
			func::GetAccount(num, name, money);
			acc[index] = new Account(num, name, money);
			index++;
		}
		else if (choice == 2) {
			func::DepositMenu(acc, index);
		}
		else if (choice == 3) {
			func::WithdrawMenu(acc, index);
		}
		else if (choice == 4) {
			func::Print(acc, index);
		}
		else if (choice == 5) {
			break;
		}
	}

	return 0;
}