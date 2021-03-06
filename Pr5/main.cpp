#include <iostream>
#include <cstring>
#include "header.h"
#define MAX 100
using namespace std;

int main(void) {
	AccountHandler Handler;
	while (1) {
		Handler.ShowMenu();

		int choice;
		cin >> choice;

		if (choice == 1) {
			Handler.GetAccount();
		}
		else if (choice == 2) {
			Handler.DepositMenu();
		}
		else if (choice == 3) {
			Handler.WithdrawMenu();
		}
		else if (choice == 4) {
			Handler.Print();
		}
		else if (choice == 5) {
			break;
		}
	}

	return 0;
}