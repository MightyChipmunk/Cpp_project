#pragma once

class Account {
private:
	int Accnum;
	char* Accname;
	int Accmoney;
public:
	Account(int num, char* name, int money);
	Account(const Account &copy);
	Account();
	int GetNum() const; //const로 선언이 가능한 함수
	int GetMoney() const;
	virtual void AddMoney(int num);
	void SubMoney(int num);
	void PrintAccount() const; //const로 선언이 가능한 함수
	Account& operator=(const Account& ref);
	virtual ~Account();
};