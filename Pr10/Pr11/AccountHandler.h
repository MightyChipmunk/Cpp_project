#pragma once
#include "Account.h"
#include "AccountArray.h"
#include "BankingCommonDecl.h"

class AccountHandler {
private:
	int index;
	BoundCheckArray<Account*> acc; 
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void MakeNormalAccount();
	void MakeHighCreditAccount();
	void DepositMenu();
	void WithdrawMenu();
	void Print() const;
	~AccountHandler();
};
