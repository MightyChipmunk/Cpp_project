#pragma once
#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int Grade;
public:
	HighCreditAccount(int num, String name, int money, int interest, int _grade) : NormalAccount(num, name, money, interest), Grade(_grade) {}
	void AddMoney(int num) {
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
		else
			cout << "�߸��� �Է��Դϴ�." << endl;
		NormalAccount::AddMoney(num);
		Account::AddMoney((int)(bonus * GetMoney() * 0.01));
	}
};